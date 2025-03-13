#include "traffic_light.h"
#include "TM4C123GH6PM.h"

#define WAIT_TIME 10000000
#define BLINK_TIME 2000000

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

// Update the state base on the time elapsed 
void TrafficLight_Update(void){
	for (int i=0; i<=WAIT_TIME+1; i++){
		if (i>WAIT_TIME){
			switch (currentState){
				case RED_STATE:
					currentState  = GREEN_STATE;
					TrafficLight_SetState(currentState);
				break;
				case GREEN_STATE:
					currentState = YELLOW_STATE;
					TrafficLight_SetState(currentState);
				break;
				case YELLOW_STATE:
					currentState = RED_STATE;
					TrafficLight_SetState(currentState);
				break;
				
			}
		}
	}
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
	
	//Turn off all LEDs
	GPIOB->DATA &= 0x0;
	
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

/**
 * @brief return the current state of the system
 *
 *  
 *
 * @param None
 * @return currentState
 */
TrafficLightState TrafficLight_GetState(void){
	
	return currentState;
}

 void delay(int count){
	
	 for(int i=0; i<=count; i++){}
 
 } 