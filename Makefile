#*******************************************************************************
#
# Copyright (C) 2018 by Tatyana Lukoyanova - Company of Nizhniy Novgorog
#
#*******************************************************************************
#
#*******************************************************************************
# Makefile for platform  HOST and MSP432
# 
#  Use: make [TARGET_NAME] [PLATFORM] [COURSE] [VERBOSE=yes]
# 
#    PLATFORM     The target platform ( HOST(default) , MSP432 )
#    TARGET_NAME  The name .out file (default c1final.out)
#    COURSE       The assignment selection 
#                 COURSE1(default) - final assignment
#                 C1M1 - week 1 assignment
#                 C1M2 - week 2 assignment
#    VERBOSE=yes  Enable debug printing
#
#  Build Targets:
#    <FILE>.i     Build preprocessed file
#    <FILE>.asm   Build assembly file
#    <FILE>.o     Build object file 
#    compile-all  Compile all object files
#    build        Compile and link c1final.out
#    clean        Remove all generated files
# 
#*******************************************************************************

include sources.mk

#Target name
TARGET_NAME=c1final
#output file name
TARGET=$(TARGET_NAME).out

# Platform Overrides
PLATFORM = HOST
COURSE   = COURSE1 

DFLAGS = -D$(PLATFORM)
DFLAGS += -D$(COURSE)

ifdef VERBOSE
  DFLAGS += -DVERBOSE
endif

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
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
CFLAGS  = -Wall -Werror -g -O0 -std=c99
CFLAGS += $(DFLAGS) $(INCLUDES)

#object files         
OBJS = $(SOURCES:.c=.o)

#platform dependent changes
ifeq ($(PLATFORM),MSP432)
  CC = arm-none-eabi-gcc
  CFLAGS += -mcpu=$(CPU) -m$(THUMB) --specs=$(SPECS) -mfloat-abi=$(FLOAT) 
  CFLAGS += -mfpu=$(FPU) -march=$(ARCH)
  LD = arm-none-eabi-ld
  LDFLAGS += -T$(LINKER_FILE)
else #($(PLATFORM),HOST)
CC = gcc
endif

#make build target
.PHONY: build
build: $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	size $(TARGET)

#building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  

#building assembly files
%.asm: %.c
	$(CC) $(CFLAGS) -S $< -o $@

#create preprocessed files
%.i: %.c
	$(CC) $(CFLAGS)  -E $< -o $@

#compile all sources
.PHONY: compile-all
compile-all: $(OBJS)

#make clean target, removes all generated files
.PHONY: clean
clean:
	@printf "clean project directory ...... \n"
	@rm -f src/*.o src/*.i *.map *.out src/*.asm src/*.d src/*.s
