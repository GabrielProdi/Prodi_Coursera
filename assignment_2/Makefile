#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#-------------------------------------------------------------------------------------------------------------------------
# Makefile for multitarget build system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#	   <FILE>.i - Builds <FILE>.i preprocessed file
#	   <FILE>.asm - Builds <FILE>.asm assembler file
#	   compile-all - Compiles all source files generating objects, 
#					 assembler, preprocesses and dependencies files, 
#					 outputting then into their respective directories.
#	   build - Compiles and links all source files
#	   clean - Removes all generated files
#
# Platform Overrides:
#      PLATFORM = HOST   - Compile for host environment execution
#      PLATFORM = MSP432 - Compile for embedded system MSP432 execution
#-------------------------------------------------------------------------------------------------------------------------
include sources.mk

SRC = ./src
OBJ = ./obj
#MAP = ./map
ASM = ./asm
PP  = ./pp
DEP = ./dep

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = ./lnk/msp432p401r.lds
CPU   = cortex-m4
ARCH  = armv7e-m
FPU   = fpv4-sp-d16
SPECS = nosys.specs

# Output basename

BASENAME = c1m2
TARGET = $(BASENAME).out

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)

CC = gcc
LD = 
LDFLAGS = -O0 -Wl,-Map=$(BASENAME).map
CFLAGS = -Wall -Werror -g -std=c99 -DHOST
CPPFLAGS = -MD
SIZE = size -Atd $(TARGET)

endif
ifeq ($(PLATFORM), MSP432)

CC = arm-none-eabi-gcc
LD = #arm-none-eabi-ld
LDFLAGS = -O0 -T$(LINKER_FILE) -Wl,-Map=$(BASENAME).map
CFLAGS = -Wall -Werror -g -std=c99 -DHOST -mcpu=$(CPU) \
	-mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=$(FPU) \
	--specs=$(SPECS) -DMSP432
CPPFLAGS = -MD
SIZE = arm-none-eabi-size -Atd $(TARGET)

endif

OBJS = $(SOURCES:.c=.o)
%.o: $(SRC)/%.c
	@echo 'Compiling $@'
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ)/$@
	@echo ' '

PPS = $(SOURCES:.c=.i)
%.i: $(SRC)/%.c
	@echo 'Pre-Processing $@'
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -E $< -o $(PP)/$@
	@echo ' '

ASMS = $(SOURCES:.c=.asm)
%.asm: $(SRC)/%.c
	@echo 'Assembling $@'
	$(CC) $(CFLAGS) $(INCLUDES) -S $< -o $(ASM)/$@
	@echo ' '

DEPS = $(SOURCES:.c=.d)
%.d: $(SRC)/%.c
	@echo 'Dependency output: $@'
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $(DEP)/$@
	@echo ' '

$(TARGET): $(OBJ)/*.o
	@ echo 'Building $@'
	$(CC) $^ $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@
	@echo ' '


.PHONY: compile-all
compile-all: $(OBJS)
	
.PHONY: build
build: compile-all $(DEPS)
	@make $(TARGET)
	$(SIZE)

.PHONY: clean
clean:
	rm $(OBJ)/*.o ./*.map $(ASM)/*.asm $(PP)/*.i $(DEP)/*.d ./$(TARGET)
