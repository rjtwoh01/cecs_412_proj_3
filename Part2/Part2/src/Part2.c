#include <board.h>
#include <sysclk.h>
#include <st7565r.h>
#include "led.h"

const int Message[8][6] = {
	0x3E, 0x41, 0x41, 0x41, 0x00, 0x00, //C
	0x7F, 0x49, 0x49, 0x49, 0x00, 0x00, //E
	0x3E, 0x41, 0x41, 0x41, 0x00, 0x00, //C
	0x46, 0x49, 0x49, 0x49, 0x31, 0x00, //S
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //SPACE
	0x3C, 0x22, 0x7F, 0x20, 0x00, 0x00, //4
	0x42, 0x7F, 0x40, 0x00, 0x00, 0x00, //1
	0x62, 0x51, 0x4D, 0x46, 0x00, 0x00, //2
};

int main(void)
{
	//! the page address to write to
	uint8_t page_address;
	//! the column address, or the X pixel.
	uint8_t column_address;
	//! store the LCD controller start draw line
	uint8_t start_line_address = 0;

	board_init();
	sysclk_init();

	gpio_set_pin_high(NHD_C12832A1Z_BACKLIGHT); //turns backlight on

	// initialize the interface (SPI), ST7565R LCD controller and LCD
	st7565r_init();

	// set addresses at beginning of display
	st7565r_set_page_address(0);
	st7565r_set_column_address(0);

	// clear display
	//for (page_address = 0; page_address <= 4; page_address++) {
		//st7565r_set_page_address(page_address);
		//for (column_address = 0; column_address < 128; column_address++) {
			//st7565r_set_column_address(column_address);
			///* fill every other pixel in the display. This will produce
			//horizontal lines on the display. */
			//st7565r_write_data(0x00);
		//}
	//}
	
	//Write message
	for (int i = 0; i < 8; i++) 
	{
		for (int k = 0; k < 6; k++)
		{
			st7565r_write_data(Message[i][k]);
		}
	}
}