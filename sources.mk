#*******************************************************************************
#
# Copyright (C) 2018 by Tatyana Lukoyanova - Company of Nizhniy Novgorog
#
#*******************************************************************************
#
# Add your Source files to this variable
SOURCES = src/main.c \
          src/memory.c \
          src/course1.c \
          src/data.c \
          src/stats.c

INCLUDES = -I./include/common

ifeq ($(PLATFORM),MSP432)
  SOURCES += src/system_msp432p401r.c \
	     src/startup_msp432p401r_gcc.c \
	     src/interrupts_msp432p401r_gcc.c

  INCLUDES += -I./include/CMSIS \
              -I./include/msp432
endif
