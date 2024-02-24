

#include "STD_type.h"

#include "LDR_config.h"
#include "LDR_interface.h"


u8 LDR_u8GetAnalogVolt(u8 Copy_u8DigitalReading)
{
	u8 Local_u8AnalogVolt;


	Local_u8AnalogVolt = (u8) Copy_u8DigitalReading;


	return Local_u8AnalogVolt;


}
