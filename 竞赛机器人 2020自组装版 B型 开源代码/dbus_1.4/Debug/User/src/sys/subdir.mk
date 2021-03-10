################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/src/sys/class_task.c \
../User/src/sys/lib_system.c \
../User/src/sys/pid.c 

OBJS += \
./User/src/sys/class_task.o \
./User/src/sys/lib_system.o \
./User/src/sys/pid.o 

C_DEPS += \
./User/src/sys/class_task.d \
./User/src/sys/lib_system.d \
./User/src/sys/pid.d 


# Each subdirectory must supply rules for building sources it contributes
User/src/sys/%.o: ../User/src/sys/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F427xx -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/hal" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/inc" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/inc/user" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/m3" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/os" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/src" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/User/inc" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/User/src/sys"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


