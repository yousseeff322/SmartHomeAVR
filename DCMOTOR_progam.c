

#include "STD_type.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "DCMOTOR_interface.h"
#include "DCMOTOR_config.h"
#include "DCMOTOR_privite.h"



u8 DCMOTOR_u8RotateCW(u8* Copy_pDCMOTOR)
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pDCMOTOR != NULL)
	{
		Local_u8ErrorState = OK;

		DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2, DIO_u8PIN_LOW);
	}

	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}



u8 DCMOTOR_u8RotateCCW(u8* Copy_pDCMOTOR)
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pDCMOTOR != NULL)
	{
		Local_u8ErrorState = OK;

		DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2, DIO_u8PIN_HIGH);
	}

	else
	{
		Local_u8ErrorState =  NULL_POINTER;
	}

	return Local_u8ErrorState;

}



u8 DCMOTOR_u8Stop(u8* Copy_pDCMOTOR)
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pDCMOTOR != NULL)
	{
		Local_u8ErrorState = OK;

		DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2, DIO_u8PIN_LOW);
	}

	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;

}

