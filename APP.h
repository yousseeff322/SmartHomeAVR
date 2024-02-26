

#ifndef APP_INTERFACE_H
#define APP_INTERFACE_H







void APP_voidLogin(void) ;
void sendOptions() ;
void APP_voidDisplayDashboard(void) ;
void APP_voidControlLight(void);
void APP_voidOpenDoor(void);
void APP_voidCloseDoor(void);
void APP_voidControlFanSpeed(void);
void play_tone(u32 frequency, u32 duration) ;
u16 ConvertToTemp(u16 adc_value) ;





#endif
