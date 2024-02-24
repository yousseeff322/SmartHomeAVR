

#include "STD_type.h"
#include "LM35_interface.h"

u16 LM35_u8GetTempreature(u16 Copy_u8DigitalReading)
{

	u16 temp_celsius ;
    temp_celsius = ((u32)Copy_u8DigitalReading * 5000ul) / (1024.0 * 10.0);
    return temp_celsius;

}
