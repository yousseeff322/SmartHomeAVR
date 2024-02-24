
#ifndef TIMERS_REGISTER_H_
#define TIMERS_REGISTER_H_

#define OCR0			*((volatile u8*)0x5C)		/*Output compare match register*/

#define TIMSK			*((volatile u8*)0x59)		/*Timer mask register*/
#define TIMSK_TOIE0		0								/*Timer0 overflow interrupt enable*/
#define TIMSK_OCIE0		1								/*Timer0 compare match interrupt enable*/
#define TIMSK_TICIE1    5
#define TIMSK_TOIE1     2                               /* Timer 1 OVF INT Enable */


#define TCCR0           *((volatile u8*)0x53)		/*Timer counter control register 0*/
#define TCCR0_COM01		5								/*Compare match output mode bit 1*/
#define TCCR0_COM00		4								/*Compare match output mode bit 0*/
#define TCCR0_WGM00		6								/*Waveform generation mode bit 0*/
#define TCCR0_WGM01		3								/*Waveform generation mode bit 1*/


#define TCNT0           *((volatile u8*)0x52)		/*Timer counter 0 register*/

#define TCCR1A			*((volatile u8*)0x4F)		/*Timer1 Control registerA*/
#define TCCR1A_COM1A1	7                               /*ChannelA compare match output mode bit1*/
#define TCCR1A_COM1A0	6                               /*ChannelA compare match output mode bit0*/
#define TCCR1A_WGM11	1                               /*Waveform generation mode bit1*/
#define TCCR1A_WGM10	0                               /*Waveform generation mode bit1*/


#define TCCR1B			*((volatile u8*)0x4E)         /*Timer1 control register*/
#define TCCR1B_ICNC1	7                                /* Input capture noise cancler*/
#define TCCR1B_ICES1	6                                /*Input capture edge select */
#define TCCR1B_WGM13	4                                /*Waveform generation mode bit3*/
#define TCCR1B_WGM12	3                                /*Waveform generation mode bit2*/
#define TCCR1B_CS12		2                                /*Prescaler bit 2*/
#define TCCR1B_CS11		1                                /*Prescaler bit 1*/
#define TCCR1B_CS10		0								 /*Prescaler bit 0*/

#define OCR1A			*((volatile u16*)0x4A)			/*ChannelA Output compare match register*/

#define ICR1			*((volatile u16*)0x46)			/*Input capture register*/

#define TCNT1			*((volatile u16*)0x4C)			/*Timer1 register*/


#endif
