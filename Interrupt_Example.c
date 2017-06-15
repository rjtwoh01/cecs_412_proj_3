#include <asf.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//bullshit

//RED LED on XmegaA3BU Xplained
#define LEDPORT PORTR
#define LEDPIN PIN0_bm

ISR(PORTF_INT1_vect)
{
	//Toggle LED on interrupt
	LEDPORT.OUTTGL = LEDPIN;
}

int main (void)
{
	//CLI and sei are two functions you must ALWAYS use in C for interrupts (WILL BE ON MIDTERM)
	//clear interrupt (shut off interrupt system)
	//sei set enable interrupts (turn on interrupt system)
	//Have to turn off the interrupts at the start because we haven't actually told them how they're supposed to work yet
	cli();
	
	//External Interrupt 1 on PF1, sense rising edge
	PORTF.DIR = 0x00; //All zeros means input
	PORTF.PIN1CTRL = PORT_ISC_RISING_gc;
	PORTF.INT1MASK = PIN1_bm;
	PORTF.INTCTRL = PORT_INT1LVL0_bm;

	//LEDPORT output, toggle in ISR
	LEDPORT.DIRSET = LEDPIN; //Data direction on LED to OUTPUT

	//Interrupt signal on PF1, connect to PC0

	//Enable low level interrupts
	PMIC.CTRL |= PMIC_LOLVLEN_bm;
	sei();
	int i = 0;
	while(1) 
		for (i = 0; i < 100; i++) { //This for loop shows that the interrupt still works despite this loop running through the cpu
		}
	}
}