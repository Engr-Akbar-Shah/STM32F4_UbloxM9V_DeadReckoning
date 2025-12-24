################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/app_lsm6dso/app_lsm6dso.c \
../Drivers/app_lsm6dso/app_lsm6dso_reg.c 

OBJS += \
./Drivers/app_lsm6dso/app_lsm6dso.o \
./Drivers/app_lsm6dso/app_lsm6dso_reg.o 

C_DEPS += \
./Drivers/app_lsm6dso/app_lsm6dso.d \
./Drivers/app_lsm6dso/app_lsm6dso_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/app_lsm6dso/%.o Drivers/app_lsm6dso/%.su Drivers/app_lsm6dso/%.cyclo: ../Drivers/app_lsm6dso/%.c Drivers/app_lsm6dso/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/flash/STM32CubeIDE/STM32F4_UbloxM9V_DeadReckoning/torpedo_v1/Drivers/app_icm42688p" -I"/home/flash/STM32CubeIDE/STM32F4_UbloxM9V_DeadReckoning/torpedo_v1/Drivers/app_lsm6dso" -I"/home/flash/STM32CubeIDE/STM32F4_UbloxM9V_DeadReckoning/torpedo_v1/Drivers/app_ubloxM9V" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-app_lsm6dso

clean-Drivers-2f-app_lsm6dso:
	-$(RM) ./Drivers/app_lsm6dso/app_lsm6dso.cyclo ./Drivers/app_lsm6dso/app_lsm6dso.d ./Drivers/app_lsm6dso/app_lsm6dso.o ./Drivers/app_lsm6dso/app_lsm6dso.su ./Drivers/app_lsm6dso/app_lsm6dso_reg.cyclo ./Drivers/app_lsm6dso/app_lsm6dso_reg.d ./Drivers/app_lsm6dso/app_lsm6dso_reg.o ./Drivers/app_lsm6dso/app_lsm6dso_reg.su

.PHONY: clean-Drivers-2f-app_lsm6dso

