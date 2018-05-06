#*******************************************************************************
#
# Copyright (C) 2018 by Tatyana Lukoyanova - Company of Nizhniy Novgorog
#
#*******************************************************************************
#
# Add your Source files to this variable
SOURCES = main.c memory.c
INCLUDES = -I../include/common

ifeq ($(PLATFORM),MSP432)
  SOURCES += system_msp432p401r.c \
	     startup_msp432p401r_gcc.c \
	     interrupts_msp432p401r_gcc.c

  INCLUDES = -I../include/CMSIS -I../include/common -I../include/msp432
endif
