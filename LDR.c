


#include "STD_type.h"
#include "LDR.h"


u16 LDR_u16GetAnalogVolt(u8 ADC_u8GetChannelReading)
{


    #if ADC_u8RESOLUTION == EIGHT_BITS

         return (u16)(((u32)ADC_u8GetChannelReading * 5000UL) / 256UL);

    #elif ADC_u8RESOLUTION == TEN_BITSs

         return (u16)(((u32)ADC_u8GetChannelReading * 5000UL) / 1024UL);

    #else 

        #error Wrong ADC_u8RESOLUTION confegration option 

    #endif


}
