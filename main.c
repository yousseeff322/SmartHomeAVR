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
	USART_u8SendNewLine();

	USART_VidSendStringSynch("Choose an option:\n");
	USART_u8SendNewLine();

	sendOptions(); // Send the list of options
	USART_u8SendNewLine();

	// Main loop
	while (1) {
		// Send options to the user

		APP_voidDisplayDashboard() ;

		// Wait for user input
		while (USART_u8ReceiveByte(&data) != OK); // Wait until valid data is received

		Number = data; // Assign received data to Number

		// Process the received number
		switch (Number) {
		case '1':
			// LED array port
			DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_HIGH);
			USART_VidSendStringSynch("LED ON \n");  // send status of LED (LED ON)
			USART_u8SendNewLine();

			break;
		case '2':
			// LED array port
			DIO_u8SetPortValue(DIO_u8PORTC, DIO_u8PORT_LOW);
			USART_VidSendStringSynch("LED OFF \n");
			USART_u8SendNewLine();

			break;
		case '3':
			APP_voidControlLight();
			USART_VidSendStringSynch("LEDS UNDER CONTROL \n");
			USART_u8SendNewLine();

			break;
		case '4':
			APP_voidOpenDoor();
			USART_VidSendStringSynch("DOOR OPEN  \n");
			USART_u8SendNewLine();

			break;
		case '5':
			APP_voidCloseDoor();
			USART_VidSendStringSynch("DOOR CLOSE \n");
			USART_u8SendNewLine();

			break;
		case '6':
			// DC motor control pin
			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_HIGH);
			USART_VidSendStringSynch("FAN ON \n");
			USART_u8SendNewLine();

			break;
		case '7':
			// DC motor control pin
			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_LOW);
			USART_VidSendStringSynch("FAN OFF \n");
			USART_u8SendNewLine();

			break;
		case '8':
			APP_voidControlFanSpeed();
			USART_VidSendStringSynch("FAN control With TEMP \n");
			USART_u8SendNewLine();

			break;
		case '9':
			play_tone(262, 500);
			_delay_ms(100); // Delay between tones
			USART_VidSendStringSynch("MUSIC ON \n");
			USART_u8SendNewLine();

			break;
		case '0':
			// Do nothing, as the options are already sent
			break;
		default:
			USART_VidSendStringSynch("Invalid option, please try again\n");
			USART_u8SendNewLine();

			break;
		}
	}
}
