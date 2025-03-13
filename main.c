#include <stdint.h>
#include "TM4C123GH6PM.h"
#include "traffic_light.h"
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
	TrafficLight_Init();
		
	while(1){
		TrafficLight_Update();
	}
	return 0;
}