#include <conf_usart_example.h>
#include <asf.h>

/*! \brief Main function.
*/
int main(void)
{
	uint8_t tx_buf[] = "\n\rEnter the numbers you want to add:\n ";
	uint8_t tx_length = 36;
	uint8_t received_byte;
	uint8_t i;
	uint8_t num1,num2,num3,num4,out,out1;

	/* Initialize the board.
	* The board-specific conf_board.h file contains the configuration of
	* the board initialization.
	*/
	board_init();
	sysclk_init();

	// USART options.
	static usart_rs232_options_t USART_SERIAL_OPTIONS = {
		.baudrate = USART_SERIAL_EXAMPLE_BAUDRATE,
		.charlength = USART_SERIAL_CHAR_LENGTH,
		.paritytype = USART_SERIAL_PARITY,
		.stopbits = USART_SERIAL_STOP_BIT
	};

	// Initialize usart driver in RS232 mode
	usart_init_rs232(USART_SERIAL_EXAMPLE, &USART_SERIAL_OPTIONS);

	// Send "message header"
	for (i = 0; i < tx_length; i++) {
		usart_putchar(USART_SERIAL_EXAMPLE, tx_buf[i]);
	}
	// Get and echo a character forever, specific '\r' processing.
	while (true) {
		received_byte = usart_getchar(USART_SERIAL_EXAMPLE);
		if (received_byte == '\r') {
			for (i = 0; i < tx_length; i++) {
				usart_putchar(USART_SERIAL_EXAMPLE, tx_buf[i]);
			}
		} else
		num1=usart_getchar(USART_SERIAL_EXAMPLE);
		usart_putchar(USART_SERIAL_EXAMPLE,num1);
		usart_putchar(USART_SERIAL_EXAMPLE, '+' );
		num2=usart_getchar(USART_SERIAL_EXAMPLE);
		usart_putchar(USART_SERIAL_EXAMPLE,num2);
		usart_putchar(USART_SERIAL_EXAMPLE, '=');
		num3=num1-48;
		num4=num2-48;
		out=num3+num4;
		out1=out+48;
		if(out>=48 ||out<=66){
			usart_putchar(USART_SERIAL_EXAMPLE, out1);
		usart_putchar(USART_SERIAL_EXAMPLE, '\r'); }
		else if (out<48){
		usart_putchar(USART_SERIAL_EXAMPLE, '!' );}
		else
		{
			out1=out+48;
			usart_putchar(USART_SERIAL_EXAMPLE, out1);
			usart_putchar(USART_SERIAL_EXAMPLE, '\r');
		}
	}
}
