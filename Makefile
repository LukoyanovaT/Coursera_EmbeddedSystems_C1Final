#*******************************************************************************
#
# Copyright (C) 2018 by Tatyana Lukoyanova - Company of Nizhniy Novgorog
#
#*******************************************************************************
#
#*******************************************************************************
# Makefile for platform  HOST and MSP432>
# 
#  Use: make [TARGET] [PLATFORM-OVERRIDES]
# 
#  Build Targets:
#    <FILE>.i     Build preprocessed file
#    <FILE>.asm   Build assembly file
#    <FILE>.o     Build object file 
#    compile-all  Compile all object files
#    build        Compile and link project.out
#    clean        Remove all generated files
# 
#  
#*******************************************************************************

include sources.mk

#Target name
TARGET_NAME=c1m2
#output file name
TARGET=$(TARGET_NAME).out

# Platform Overrides
PLATFORM = HOST

DFLAGS = -D$(PLATFORM)

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
THUMB = thumb
ARCH = armv7e-m
SPECS = nosys.specs
FLOAT = hard
FPU = fpv4-sp-d16

# Compiler Flags and Defines
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=$(TARGET_NAME).map

#general compiler flags for both platforms
CFLAGS = -Wall -Werror -g -O0 -std=c99 $(DFLAGS)

#object files         
OBJS = $(SOURCES:.c=.o)

#platform dependent changes
ifeq ($(PLATFORM),HOST)
  CC = gcc
else
  CC = arm-none-eabi-gcc
  CFLAGS += -mcpu=$(CPU) -m$(THUMB) --specs=$(SPECS) -mfloat-abi=$(FLOAT) -mfpu=$(FPU) -march=$(ARCH)
  LD = arm-none-eabi-ld
  LDFLAGS += -T$(LINKER_FILE)
endif

#make build target
.PHONY: build
build: $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@
	size $(TARGET)

#building object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@  

#building assembly files
%.asm: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -S $< -o $@

#create preprocessed files
%.i: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -E $< -o $@

#compile all sources
.PHONY: compile-all
compile-all: $(OBJS)

#make clean target, removes all generated files
.PHONY: clean
clean:
	@printf "clean project directory ...... \n"
	@rm -f *.o *.i *.map *.out *.asm *.d *.s
