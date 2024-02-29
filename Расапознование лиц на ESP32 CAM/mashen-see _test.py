# подключаем библиотеку компьютерного зрения 
import cv2
from urllib.request import urlopen
import numpy as np

url = 'http://192.168.1.178/cam-lo.jpg'
# функция определения лиц
def highlightFace(net, frame, conf_threshold=0.7):
    # делаем копию текущего кадра
    frameOpencvDnn=frame.copy()
    # высота и ширина кадра
    frameHeight=frameOpencvDnn.shape[0]
    frameWidth=frameOpencvDnn.shape[1]
    # преобразуем картинку в двоичный пиксельный объект
    blob=cv2.dnn.blobFromImage(frameOpencvDnn, 1.0, (300, 300), [104, 117, 123], True, False)
    # устанавливаем этот объект как входной параметр для нейросети
    net.setInput(blob)
    # выполняем прямой проход для распознавания лиц
    detections=net.forward()
    # переменная для рамок вокруг лица
    faceBoxes=[]
    # перебираем все блоки после распознавания
    for i in range(detections.shape[2]):
        # получаем результат вычислений для очередного элемента
        confidence=detections[0,0,i,2]
        # если результат превышает порог срабатывания — это лицо
        if confidence>conf_threshold:
            # формируем координаты рамки
            x1=int(detections[0,0,i,3]*frameWidth)
            y1=int(detections[0,0,i,4]*frameHeight)
            x2=int(detections[0,0,i,5]*frameWidth)
            y2=int(detections[0,0,i,6]*frameHeight)
            # добавляем их в общую переменную
            faceBoxes.append([x1,y1,x2,y2])
            # рисуем рамку на кадре
            cv2.rectangle(frameOpencvDnn, (x1,y1), (x2,y2), (0,255,0), int(round(frameHeight/150)), 8)
    # возвращаем кадр с рамками
    return frameOpencvDnn,faceBoxes

# загружаем веса для распознавания лиц
faceProto="opencv_face_detector.pbtxt"
# и конфигурацию самой нейросети — слои и связи нейронов
faceModel="opencv_face_detector_uint8.pb"

# запускаем нейросеть по распознаванию лиц
faceNet=cv2.dnn.readNet(faceModel,faceProto)

# получаем видео с камеры
video=cv2.VideoCapture(url)
# пока не нажата любая клавиша — выполняем цикл
while cv2.waitKey(1)<0:
    # получаем очередной кадр с камеры
    hasFrame,frame=video.read()
    # если кадра нет
    if not hasFrame:
        # останавливаемся и выходим из цикла
        cv2.waitKey()
        break

    while True:
        # Read a frame from the video stream
        img_resp = urlopen(url)
        imgnp = np.array(bytearray(img_resp.read()), dtype=np.uint8)
        # ret, frame = cap.read()
        im = cv2.imdecode(imgnp, -1)
        # распознаём лица в кадре
        resultImg, faceBoxes = highlightFace(faceNet, im)
        # если лиц нет
        if not faceBoxes:
            # выводим в консоли, что лицо не найдено
            print("Лица не распознаны")

        cv2.imshow('live Cam Testing', resultImg)
        key = cv2.waitKey(5)
        if key == ord('q'):
            break

    video.release()
    cv2.destroyAllWindows()


