################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/app_ubloxM9V/app_ubloxM9V.c 

OBJS += \
./Drivers/app_ubloxM9V/app_ubloxM9V.o 

C_DEPS += \
./Drivers/app_ubloxM9V/app_ubloxM9V.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/app_ubloxM9V/%.o Drivers/app_ubloxM9V/%.su Drivers/app_ubloxM9V/%.cyclo: ../Drivers/app_ubloxM9V/%.c Drivers/app_ubloxM9V/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/flash/STM32CubeIDE/STM32F4_UbloxM9V_DeadReckoning/torpedo_v1/Drivers/app_icm42688p" -I"/home/flash/STM32CubeIDE/STM32F4_UbloxM9V_DeadReckoning/torpedo_v1/Drivers/app_lsm6dso" -I"/home/flash/STM32CubeIDE/STM32F4_UbloxM9V_DeadReckoning/torpedo_v1/Drivers/app_ubloxM9V" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-app_ubloxM9V

clean-Drivers-2f-app_ubloxM9V:
	-$(RM) ./Drivers/app_ubloxM9V/app_ubloxM9V.cyclo ./Drivers/app_ubloxM9V/app_ubloxM9V.d ./Drivers/app_ubloxM9V/app_ubloxM9V.o ./Drivers/app_ubloxM9V/app_ubloxM9V.su

.PHONY: clean-Drivers-2f-app_ubloxM9V

