#ifndef __TRAFFIC_LIGHT_H
#define __TRAFFIC_LIGHT_H


// Pin definition GPIOB
#define RED_LED_PIN (1<<1)
#define GREEN_LED_PIN (1U<<2)
#define YELLOW_LED_PIN (1U<<3)



//Define traffic light states
typedef enum{
	RED_STATE,
	GREEN_STATE,
	YELLOW_STATE
} TrafficLightState;

//Variable to track current_state 
static TrafficLightState currentState = RED_STATE;

//Function prototypes
void TrafficLight_Init(void);
void TrafficLight_Update(void);
void TrafficLight_SetState(TrafficLightState newState);
TrafficLightState TrafficLight_GetState(void);
void TrafficLight_Blink();
void delay(int count);

#endif /* TRAFFIC_LIGHT_H */