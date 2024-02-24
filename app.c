/**
 * @brief 		this is a semi-smart home using AVR atmega32
 * @author		YOUSSEF HAMED.
 * @version		1.0
 * @date		24-2-2024
 * @details		The project includes the following hardware:
 * 													1- AVR atmega32 microcontroller.
 * 													2- LM016L LCD 16*2.
 * 													3- LM35 temperature sensor.
 * 													4- LDR.
 * 													5- Keypad.
 * 													6- 7-Segment Display.
 * 													8- Buzzer.
 * 													9- DC Motor.
 * 													10- LEDs.
 * 				- it has a login page that asks the user to enter an ID, and password, checks if the password
 * 				  checks if the password == the ID entered but in reverse it logs the user in.
 *
 * 				- if not the 7segment already showing 3, refers to the number of attempts available, with each
 * 				  wrong trial the 7segment is decremented, a beep sound outputs from the buzzer and the user
 * 				  is asked to enter the credentials again.
 *
 * 				- after 3 wrong trials user is blocked and system shuts down.
 *
 *
 *
 */

#include "STD_type.h"
#include <util/delay.h>
#include "MAP.h"

#include "TIMER_interface.h"
#include "USART_interface .h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

#include "KEYPAD_interface.h"
#include "CLCD_interface.h"
#include "LDR_interface.h"


#include "APP.h"



void APP_voidLogin(void) {
    u8 LOCAL_u8Id[4] = {'1', '2', '3', '4'}, LOCAL_u8Password[4] = {'4', '3', '2', '1'};
    u8 LOCAL_u8CheckId[4] = {0}, LOCAL_u8CheckPassword[4] = {0};
    u8 ID = 1, Password = 1;
    u8 LoginI = 3;
    u8 RxData;
    u8 idCounter = 0, passCounter = 0;

    CLCD_voidGotoXY(3, 0);
    CLCD_voidSendString("Welcome...");
    _delay_ms(2000);

    while (LoginI) {
        ID = 1;
        Password = 1;
        idCounter = 0;
        passCounter = 0;

        CLCD_voidSendCommand(1);
        CLCD_voidSendString("Enter ID : ");
        CLCD_voidGotoXY(1, 0);

        // Wait for ID input
        while (idCounter < 4) {
            if (USART_u8ReceiveByte(&RxData) == OK) {
                LOCAL_u8CheckId[idCounter++] = RxData;
                CLCD_voidSendData(RxData); // Echo back received character
            }
        }

        // Check ID validity
        for (u8 i = 0; i < 4; i++) {
            if (LOCAL_u8CheckId[i] != LOCAL_u8Id[i]) {
                ID = 0;
            }
        }

        CLCD_voidSendCommand(1);
        CLCD_voidSendString("Enter Password:");
        CLCD_voidGotoXY(1, 0);

        // Wait for Password input
        while (passCounter < 4) {
            if (USART_u8ReceiveByte(&RxData) == OK) {
                LOCAL_u8CheckPassword[passCounter++] = RxData;
                CLCD_voidSendData(RxData); // Echo back received character
            }
        }

        // Check Password validity
        for (u8 i = 0; i < 4; i++) {
            if (LOCAL_u8CheckPassword[i] != LOCAL_u8Password[i]) {
                Password = 0;
            }
        }

        // Handle login result
        if (ID && Password) {
            CLCD_voidSendCommand(1);
            CLCD_voidSendString("Welcome Youssef");
            _delay_ms(2000);
            break;
        } else {
            CLCD_voidSendCommand(1);
            CLCD_voidSendString("Invalid ID or Password");
            LoginI--;
            if (LoginI) {
                _delay_ms(2000);
                CLCD_voidSendCommand(1);
                CLCD_voidSendString("Try Again..");
                _delay_ms(2000);
            }
        }
    }

    if (!(ID && Password)) {
        _delay_ms(2000);
        CLCD_voidSendCommand(1);
        CLCD_voidSendString("Invalid Login ");

}

}

void APP_voidOpenDoor(void)
{

	/* PWM mode in timer1 with top value = 40000 to control the duty cycle   */
	TIMER1_voidSetCompValue(6000);


}

void APP_voidCloseDoor(void)
{
	/* PWM mode in timer1 with top value = 40000 to control the duty cycle   */
	TIMER1_voidSetCompValue(1000);

}



void APP_voidControlFanSpeed(void)
{

	u8 check =100   ;
	u16 LocalAdcValue ;

	/* fast PWM mode */

	while(check > 10)
	{

		/* Get the analog volt from the  Potentiometer and map it */
		TIMER0_voidSetCompValue(Map(0,255,0,250,ADC_u8StartConversionSynch(0  , &LocalAdcValue)));

		check = ADC_u8StartConversionSynch(0 , & LocalAdcValue) ;
	}

	TIMER0_voidPWMDisable();
}

void APP_voidControlLight(void)
{
    u16 adc_value;
    u8 LOCAL_u8Light;

    // Read analog voltage from LDR using ADC
    adc_value = ADC_u8StartConversionSynch(7, &adc_value);

    // Map the ADC value to a range suitable for LED brightness
    LOCAL_u8Light = Map(0, 1023, 0, 255, adc_value);

    // Determine the number of LEDs to light up based on the mapped value
    u8 num_leds = LOCAL_u8Light / 10; // Adjust divisor based on LED characteristics

    // Set the LED states based on the number of LEDs to light up
    for (u8 i = 0; i < num_leds; i++) {
        DIO_u8SetPinValue(DIO_u8PORTC, i, DIO_u8PIN_HIGH); // Turn on LED
        _delay_ms(100); // Delay for stability
    }

    // Turn off any remaining LEDs
    for (u8 i = num_leds; i < 8; i++) {
        DIO_u8SetPinValue(DIO_u8PORTC, i, DIO_u8PIN_LOW); // Turn off LED
    }
}







// Function to generate a tone of given frequency and duration
void play_tone(u32 frequency, u32 duration) {
	u32 period = 1000000 / frequency; // Calculate period in microseconds
	u32 pulse_width = period / 2; // Half period for square wave

	for ( u32 i = 0; i < duration * frequency / 1000; i++) {
		DIO_u8SetPinValue(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PORT_HIGH) ;
		_delay_us(pulse_width); // Wait for half period
		DIO_u8SetPinValue(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PORT_LOW) ;
		_delay_us(pulse_width); // Wait for half period
	}
}
