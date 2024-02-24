################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../AppMaster.c \
../CLCD_program.c \
../DCMOTOR_progam.c \
../DIO_program.c \
../EXTI_program.c \
../GIE_program.c \
../KEYPAD_program.c \
../LDR.c \
../LDR_progom.c \
../LM35_progom.c \
../MAP.c \
../PORT_program.c \
../TIMER_prog.c \
../USART_program.c \
../app.c \
../main.c 

OBJS += \
./ADC_program.o \
./AppMaster.o \
./CLCD_program.o \
./DCMOTOR_progam.o \
./DIO_program.o \
./EXTI_program.o \
./GIE_program.o \
./KEYPAD_program.o \
./LDR.o \
./LDR_progom.o \
./LM35_progom.o \
./MAP.o \
./PORT_program.o \
./TIMER_prog.o \
./USART_program.o \
./app.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./AppMaster.d \
./CLCD_program.d \
./DCMOTOR_progam.d \
./DIO_program.d \
./EXTI_program.d \
./GIE_program.d \
./KEYPAD_program.d \
./LDR.d \
./LDR_progom.d \
./LM35_progom.d \
./MAP.d \
./PORT_program.d \
./TIMER_prog.d \
./USART_program.d \
./app.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


