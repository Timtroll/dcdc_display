################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/paper_screen/subdir.mk
-include Drivers/STM32L0xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/STM32L0538-Discovery/subdir.mk
-include Drivers/BSP/Components/gde021a1/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
screen_paper.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
screen_paper.list \

OBJCOPY_BIN += \
screen_paper.bin \


# All Target
all: screen_paper.elf secondary-outputs

# Tool invocations
screen_paper.elf: $(OBJS) $(USER_OBJS) H:\Projects\Paper_screen_tdd\hardware\STM32L053C8TX_FLASH.ld
	arm-none-eabi-gcc -o "screen_paper.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"H:\Projects\Paper_screen_tdd\hardware\STM32L053C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="screen_paper.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

screen_paper.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "screen_paper.list"
	@echo 'Finished building: $@'
	@echo ' '

screen_paper.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "screen_paper.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
