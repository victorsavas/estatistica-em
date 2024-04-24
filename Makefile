BUILD ?= STANDARD
PROJECT_NAME ?= tabela

SRC_DIR = src

CC = gcc
CFLAGS += -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces

INCLUDE += -I $(SRC_DIR)

ifeq  ($(BUILD), DEBUG)
    CFLAGS += -g -O0
else
    CFLAGS += -s -O1
endif

OBJS := $(wildcard $(SRC_DIR)/*.c)

.PHONY: all

all:
	$(CC) -o $(PROJECT_NAME) $(OBJS) $(CFLAGS) $(INCLUDE)