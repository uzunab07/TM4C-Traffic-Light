#include <stdint.h>
#include "TM4C123GH6PM.h"
/**
 * Traffic Light Project - Embedded Systems
 *
 * TODO:
 * 
 * 1. Hardware Setup:
 *    - Connect LEDs (Red, Yellow, Green) to GPIO pins.
 *    - Connect push button for pedestrian crossing.
 *    - Ensure correct resistor values are used.
 *
 * 2. Software Structure:
 *    a) Configure all GPIOs (input for button, output for LEDs).
 *    b) Implement state machine for traffic light sequence.
 *    c) Use timers for precise delays (instead of blocking delays).
 *    d) Add button interrupt to trigger pedestrian crossing mode.
 *    e) Implement power-saving mode (optional).
 *
 * 3. Testing and Debugging:
 *    - Check LED functionality.
 *    - Ensure timing is correct.
 *    - Handle edge cases (button press at different states).
 *
 * 4. Enhancements (Optional):
 *    - Add UART debugging for status updates.
 *    - Implement PWM for LED brightness control.
 *    - Use an LCD or seven-segment display for countdown timer.
 */

int main(){
	//Clock gating gpiof and b
	SYSCTL->RCGCGPIO |= (1U<<5 | 1U<<1);
	 while ((SYSCTL->PRGPIO & ((1U << 5) | (1U << 1))) == 0);
	
	GPIOF->DEN |= (1U<<1 | 1U<<2);
	GPIOF->DIR |= (1U<<1 | 1U<<2);
	GPIOB->DEN |= (1U<<2);
	GPIOB->DIR |= (1U<<2);
	
  
	while(1){
 	GPIOB->DATA_Bits[1U<<2] = 1U<<2;
	GPIOF->DATA_Bits[1U<<2] = 1U<<2;	
	GPIOF->DATA_Bits[1U<<1] = 1U<<1;
	
		
	}
	return 0;
}