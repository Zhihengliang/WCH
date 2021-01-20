################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CODE/Car_control.c \
../CODE/Function.c \
../CODE/Key.c \
../CODE/Open_loop.c \
../CODE/Pid.c \
../CODE/Uart_TAR.c \
../CODE/Variable.c 

OBJS += \
./CODE/Car_control.o \
./CODE/Function.o \
./CODE/Key.o \
./CODE/Open_loop.o \
./CODE/Pid.o \
./CODE/Uart_TAR.o \
./CODE/Variable.o 

C_DEPS += \
./CODE/Car_control.d \
./CODE/Function.d \
./CODE/Key.d \
./CODE/Open_loop.d \
./CODE/Pid.d \
./CODE/Uart_TAR.d \
./CODE/Variable.d 


# Each subdirectory must supply rules for building sources it contributes
CODE/%.o: ../CODE/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"../Libraries/wch_libraries/Core" -I"../Libraries/wch_libraries/Peripheral" -I"../Libraries/wch_libraries/Startup" -I"../Libraries/seekfree_libraries" -I"../Libraries/seekfree_peripheral" -I"../Libraries/board" -I"../CODE" -I"../USER" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

