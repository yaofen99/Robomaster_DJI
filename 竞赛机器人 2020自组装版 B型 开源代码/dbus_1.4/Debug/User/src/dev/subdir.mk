################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/src/dev/dbus.c \
../User/src/dev/gyroscope.c \
../User/src/dev/hall.c \
../User/src/dev/infrared.c \
../User/src/dev/key.c \
../User/src/dev/motor.c \
../User/src/dev/potentiometer.c \
../User/src/dev/sonic.c \
../User/src/dev/stick.c \
../User/src/dev/uart.c \
../User/src/dev/wireless.c 

OBJS += \
./User/src/dev/dbus.o \
./User/src/dev/gyroscope.o \
./User/src/dev/hall.o \
./User/src/dev/infrared.o \
./User/src/dev/key.o \
./User/src/dev/motor.o \
./User/src/dev/potentiometer.o \
./User/src/dev/sonic.o \
./User/src/dev/stick.o \
./User/src/dev/uart.o \
./User/src/dev/wireless.o 

C_DEPS += \
./User/src/dev/dbus.d \
./User/src/dev/gyroscope.d \
./User/src/dev/hall.d \
./User/src/dev/infrared.d \
./User/src/dev/key.d \
./User/src/dev/motor.d \
./User/src/dev/potentiometer.d \
./User/src/dev/sonic.d \
./User/src/dev/stick.d \
./User/src/dev/uart.d \
./User/src/dev/wireless.d 


# Each subdirectory must supply rules for building sources it contributes
User/src/dev/%.o: ../User/src/dev/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F427xx -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/hal" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/inc" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/inc/user" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/m3" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/os" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/LibInc/src" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/User/inc" -I"C:/Users/brody.zhang/Desktop/tutorial/car_1.3/User/src/sys"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


