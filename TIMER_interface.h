
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H



typedef enum
{
    TIMER0_OVF=0,
    TIMER0_COMP,
    TIMER1_COMP,
    TIMER1_ICU,
	TIMER1_OVF

}TIMERS_Int_Src_t;



void TIMER0_voidInit(void);

void TIMER0_voidPWMDisable(void);


u8 TIMERS_u8SetCallBack( TIMERS_Int_Src_t Copy_u8TimerIntSource ,  void (* Copy_pvCallBackFunction )(void) );

 
void TIMER0_voidSetCompValue(u8 Copy_u8Value);




void TIMER1_voidInit(void);
void TIMER1_voidSetCompValue(u16 Copy_u16Value);

void TIMER1_voidSetTimerVal(u16 Copy_u16Value);
u16 TIMER1_u16GetTimerVal(void);


void ICU_voidInit(void);



u8 ICU_voidSetTriggerSrc(u8 Copy_u8TriggerSrc);
/* choose the edge 1-FALLING_EDGE
                   2-RISSING_EDGE

**/


u32 ICU_u32GetVal(void);

void ICU_voidIntEnable(void);
void ICU_voidIntDisable(void);



  



#endif
