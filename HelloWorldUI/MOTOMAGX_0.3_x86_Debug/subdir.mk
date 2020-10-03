################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
H_SRCS += \
../HelloWorld.h 

CPP_SRCS += \
../HelloWorld.cpp \
../main.cpp 

MOC_CPP += \
./moc_HelloWorld.cpp 

OBJS += \
./HelloWorld.o \
./moc_HelloWorld.o \
./main.o 

CPP_DEPS += \
./HelloWorld.d \
./moc_HelloWorld.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MOTODEV Compiler'
	i686-mot-linux-gnu-g++ -DQWS -DMOTODEV_STUDIO -I"${SDK_INCLUDE_DIR}" -I./include -I"${SDK_X86_OS_INCLUDE_DIR}" -I"${SDK_PRIVATE_INCLUDE_DIR}" -I"${SDK_X86_OS_INCLUDE_DIR}/c++/3.4.3" -I"${SDK_X86_OS_INCLUDE_DIR}/c++/3.4.3/i686-mot-linux-gnu" -c -pipe -fno-rtti -fexceptions -W -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

moc_HelloWorld.cpp: ../HelloWorld.h
	@echo 'Building file: $<'
	@echo 'Invoking: QT Meta Object Compiler'
	moc -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ./%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MOTODEV Compiler'
	i686-mot-linux-gnu-g++ -DQWS -DMOTODEV_STUDIO -I"${SDK_INCLUDE_DIR}" -I./include -I"${SDK_X86_OS_INCLUDE_DIR}" -I"${SDK_PRIVATE_INCLUDE_DIR}" -I"${SDK_X86_OS_INCLUDE_DIR}/c++/3.4.3" -I"${SDK_X86_OS_INCLUDE_DIR}/c++/3.4.3/i686-mot-linux-gnu" -c -pipe -fno-rtti -fexceptions -W -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


