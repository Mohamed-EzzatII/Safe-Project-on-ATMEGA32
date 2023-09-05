################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app.c \
../gpio.c \
../green_led.c \
../keypad.c \
../lcd.c \
../main.c \
../red_led.c 

OBJS += \
./app.o \
./gpio.o \
./green_led.o \
./keypad.o \
./lcd.o \
./main.o \
./red_led.o 

C_DEPS += \
./app.d \
./gpio.d \
./green_led.d \
./keypad.d \
./lcd.d \
./main.d \
./red_led.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


