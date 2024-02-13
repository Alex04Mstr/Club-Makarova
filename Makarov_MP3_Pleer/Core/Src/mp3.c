/* MP3 LIB
 * V 0.1, Andrey Koryagin, Kremenchuk, Ukraine, 2016
* Simple library to use the DFPlayer.
* It's can say a numbers from -9999 to 9999.
* Before using need to copy specially prepared mp3-files to SD-card.
* You can find a sample of this files in folder "SD_CARD_FILES"
* You can make same folders for different languages and choose language for playing.
* To choose a language (folder), please use MP3_set_folder function.
* You can free use and modify this lib as you like. Good luck.
*
 */
#include "stm32f1xx.h"
#include "mp3.h"

volatile uint8_t mp3_RXi;
volatile char mp3_RXc;
volatile char mp3_RX_Buf[mp3_RX_Buf_SIZE] = {'\0'};
volatile uint8_t mp3_folder = 1;
static uint8_t mp3_cmd_buf[10] = {0x7E, 0xFF, 0x6, 0x00, 0x01, 0x0, 0x0, 0x00, 0x00, 0xEF};
volatile uint8_t mp3_queue[MP3_QUEUE_LEN] = {MP3_NO_VALUE, MP3_NO_VALUE, MP3_NO_VALUE, MP3_NO_VALUE, MP3_NO_VALUE, MP3_NO_VALUE, MP3_NO_VALUE, MP3_NO_VALUE, MP3_NO_VALUE, MP3_NO_VALUE};
volatile int8_t mp3_queue_id = 0;
volatile uint8_t mp3_flag = 0;
extern UART_HandleTypeDef huart1;
/* UART3 Initialization for DFPlayer using
 * Communication Standard: 9600 bps
*/

/* Clear receive data buffer.
 * DFPlayer sends messages when certain events.
 * This buffer is used to receive messages from the player.
*/
void MP3_clear_RXBuffer(void) {
	for (mp3_RXi=0; mp3_RXi<mp3_RX_Buf_SIZE; mp3_RXi++)
		mp3_RX_Buf[mp3_RXi] = '\0';
	mp3_RXi = 0;
}

/* Processing data received from a DFPlayer
 * We need to know the moment of the end of track playing.
 * Sets a flag when message received and the end of track playing is detected.
 * Other messages are ignored.
 */

/* Calculate checksum
 */
uint16_t MP3_checksum (void) {
	uint16_t sum = 0;
	uint8_t i;
	for (i=1; i<7; i++) {
		sum += mp3_cmd_buf[i];
	}
	return -sum;
}

/* Send command to DFPlayer
 */
void MP3_send_cmd (uint8_t cmd, uint16_t high_arg, uint16_t low_arg) {

	uint16_t checksum;

	mp3_cmd_buf[3] = cmd;
	mp3_cmd_buf[5] = high_arg;
	mp3_cmd_buf[6] = low_arg;

	checksum = MP3_checksum();
	mp3_cmd_buf[7] = (uint8_t) ((checksum >> 8) & 0x00FF);
	mp3_cmd_buf[8] = (uint8_t) (checksum & 0x00FF);

	// Send command to UART3
	HAL_UART_Transmit(&huart1, mp3_cmd_buf, 10, 0xffff);

}

/* This function make a queue from simple mp3-files to say a long number.
 * Range -9999...9999
 * You can use prefix and suffix. It's a mp3-files which will play before and after number.
 */

/* QUEUE Processing.
 * This function handles the queue and starts playing the next file after the finish of file playing.
 */
void MP3_queue_processing(void) {
	// MP3 QUEUE Processing
	if ( (mp3_queue[mp3_queue_id] != MP3_NO_VALUE) & (mp3_queue_id < MP3_QUEUE_LEN) ) {
		if (mp3_flag == 1) {
			MP3_send_cmd(MP3_PLAY_FOLDER_FILE, mp3_folder, mp3_queue[mp3_queue_id]);
			mp3_queue_id++;
			MP3_clear_RXBuffer();
			mp3_flag = 0;
		}
	}
}

void MP3_set_folder (uint8_t folder) {
	mp3_folder = folder;
}

void MP3_play(uint16_t num) {
	uint16_t checksum;

	mp3_cmd_buf[3] = MP3_TRAKING_NUM;
	mp3_cmd_buf[4] = 0;

	mp3_cmd_buf[5] = 0;
	mp3_cmd_buf[6] = num;

	checksum = MP3_checksum();
	mp3_cmd_buf[7] = (uint8_t) ((checksum >> 8) & 0x00FF);
	mp3_cmd_buf[8] = (uint8_t) (checksum & 0x00FF);

	HAL_UART_Transmit(&huart1, mp3_cmd_buf, 10, 0xffff);
}

void MP3_pause () {
	uint16_t checksum;

	mp3_cmd_buf[3] = MP3_PAUSE;

	mp3_cmd_buf[4] = 0;

	mp3_cmd_buf[5] = 0;
	mp3_cmd_buf[6] = 0;

	checksum = MP3_checksum();
	mp3_cmd_buf[7] = (uint8_t) ((checksum >> 8) & 0x00FF);
	mp3_cmd_buf[8] = (uint8_t) (checksum & 0x00FF);
	HAL_UART_Transmit(&huart1, mp3_cmd_buf, 10, 0xffff);
}
