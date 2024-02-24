

#include "STD_type.h"
#include "BIT_math.h"
#include "MAP.h"

s32 Map(s32 InputMin,s32 InputMax,s32 OutputMin,s32 OutputMax,s32 InputValue)
{

    return (((OutputMax - OutputMin) * (InputValue - InputMin)) / (InputMax - InputMin)) + OutputMin ;
}
