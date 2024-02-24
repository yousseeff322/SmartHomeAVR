#include "STD_type.h"
#include <util/delay.h>
#include "MAP.h"

#include "USART_interface .h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

#include "KEYPAD_interface.h"
#include "CLCD_interface.h"
#include "LDR.h"


#include "APP.h"



void main(void) {
	u8 Number = 0, data;

	// Initialize peripherals
	PORT_voidInit();
	USART_VidInit();
	ADC_voidInt();
	CLCD_voidInit();
	TIMER0_voidInit();
	TIMER1_voidInit();

	// Perform login
	APP_voidLogin();

	// Main loop
	while (1) {
		// Check if data is received from USART
		if (USART_u8ReceiveByte(&data) == OK) {
			Number = data; // Assign received data to Number

			// Process the received number
			switch (Number) {
			case '1':
				// LED array port
				DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_HIGH);
				USART_VidReceiveStringSynch("LED ON \n");	// send status of LED (LED ON)

				break;
			case '2':
				// LED array port
				DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_LOW);
				CLCD_voidSendString("LEDS OFF ");
				_delay_ms(500);
				break;
			case '3':
				APP_voidControlLight();
				break;
			case '4':
				APP_voidOpenDoor();
				CLCD_voidSendString("DOOR OPEN ");
				_delay_ms(500);
				break;
			case '5':
				APP_voidCloseDoor();
				CLCD_voidSendString("DOOR CLOSE ");
				_delay_ms(500);
				break;
			case '6':
				// DC motor control pin
				DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_HIGH);
				CLCD_voidSendString("FAN ON ");
				_delay_ms(500);
				break;
			case '7':
				// DC motor control pin
				DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_LOW);
				CLCD_voidSendString("FAN OFF ");
				_delay_ms(500);
				break;
			case '8':
				APP_voidControlFanSpeed();
				break;
			case '9':
				play_tone(262, 500);
				_delay_ms(100); // Delay between tones
				break;
			default:
				break;
			}
		}
	}
}
