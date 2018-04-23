# OpenSignal
# Numerical Library Makefile
# Dogan C. Karatas | 2018 | GNU GPL v3

TARGET = libnumerical.so
INSTALL = ../_install
CC = gcc
CFLAGS = -I../include -g -Wall -Wextra -Werror -fpic
LDFLAGS = -lm -shared

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET}

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(SRCS:.c=.d)

.PHONY: install
install: all
	$(shell if [ ! -d ${INSTALL} ];	then mkdir ${INSTALL}; fi;)
	cp -f ${TARGET} ${INSTALL}/${TARGET}

.PHONY: clean
clean:
	rm -f ${TARGET} ${OBJS} $(SRCS:.c=.d)
	rm -f ./${INSTALL}/${TARGET}
