################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ICU_HW.c \
../Ultrasonic.c \
../gpio.c \
../lcd.c \
../main.c 

OBJS += \
./ICU_HW.o \
./Ultrasonic.o \
./gpio.o \
./lcd.o \
./main.o 

C_DEPS += \
./ICU_HW.d \
./Ultrasonic.d \
./gpio.d \
./lcd.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


