################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Gyroscope/Gyroscope.c 

OBJS += \
./HAL/Gyroscope/Gyroscope.o 

C_DEPS += \
./HAL/Gyroscope/Gyroscope.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Gyroscope/%.o: ../HAL/Gyroscope/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


