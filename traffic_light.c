#include "traffic_light.h"
#include "TM4C123GH6PM.h"

/**
 * @brief Initializes the traffic light system.
 *
 * This function configures the GPIOs for the traffic light LEDs 
 * and sets the initial state to RED.
 *
 * @return None
 */
void TrafficLight_Init(void){
	SYSCTL->RCGCGPIO |= (1U<<1);
	
	//Enable the GPIOB for digital operation
	GPIOB->DEN |= (RED_LED_PIN | GREEN_LED_PIN | YELLOW_LED_PIN);
	
	//Configure the GPIOB as output
	GPIOB->DIR |= (RED_LED_PIN | GREEN_LED_PIN | YELLOW_LED_PIN);
	
	//Set the initial state of my system
	TrafficLight_SetState(RED_STATE);
}
void TrafficLight_Update(void){
	
}

/**
 * @brief Turn on the led corresponding the state of the system
 *
 * This function takes the current state of the system and turn 
 * on the led corresponding to the state. 
 *
 * @param newState current state 
 * @return None
 */
void TrafficLight_SetState(TrafficLightState newState){
	currentState = newState;
	
	//Activate the current LED based on the state
	switch(currentState){
		case RED_STATE:
			GPIOB->DATA_Bits[RED_LED_PIN] |= RED_LED_PIN;
		break;
		case GREEN_STATE:
			GPIOB->DATA_Bits[GREEN_LED_PIN] |= GREEN_LED_PIN;
		break;
		case YELLOW_STATE:
			GPIOB->DATA_Bits[YELLOW_LED_PIN] |= YELLOW_LED_PIN;
		break;
	}
}
TrafficLightState TrafficLight_GetState(void){
	
	return 0;
}