################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hardware/OLED/oled.c 

OBJS += \
./Hardware/OLED/oled.o 

C_DEPS += \
./Hardware/OLED/oled.d 


# Each subdirectory must supply rules for building sources it contributes
Hardware/OLED/%.o Hardware/OLED/%.su Hardware/OLED/%.cyclo: ../Hardware/OLED/%.c Hardware/OLED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L433xx -c -I../Drivers/CMSIS/Include -I"F:/biyesheji/jicheng/code/XY/KE1_RotaryEncoder/Hardware/OLED" -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Hardware-2f-OLED

clean-Hardware-2f-OLED:
	-$(RM) ./Hardware/OLED/oled.cyclo ./Hardware/OLED/oled.d ./Hardware/OLED/oled.o ./Hardware/OLED/oled.su

.PHONY: clean-Hardware-2f-OLED

