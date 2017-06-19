#include <board.h>
#include <sysclk.h>
#include <st7565r.h>

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

	// initialize the interface (SPI), ST7565R LCD controller and LCD
	st7565r_init();

	// set addresses at beginning of display
	st7565r_set_page_address(0);
	st7565r_set_column_address(0);

	// fill display with lines
	for (page_address = 0; page_address <= 4; page_address++) {
		st7565r_set_page_address(page_address);
		for (column_address = 0; column_address < 128; column_address++) {
			st7565r_set_column_address(column_address);
			/* fill every other pixel in the display. This will produce
			horizontal lines on the display. */
			st7565r_write_data(0xAA);
		}
	}

	// scroll the display using hardware support in the LCD controller
	while (true) {
		st7565r_set_display_start_line_address(start_line_address++);
		delay_ms(250);
	}
}
