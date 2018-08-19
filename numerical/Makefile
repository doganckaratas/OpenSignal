# OpenSignal
# Numerical Library Makefile
# Dogan C. Karatas | 2018 | GNU GPL v3

CC=gcc
CFLAGS_LIB=-I../include -Wall -Werror -Wextra -pedantic -g -ggdb -O0 -fpic
SRCS_LIB=$(wildcard *.c)
OBJS_LIB=$(SRCS_LIB:.c=.o)
DEPS_LIB=$(OBJS_LIB:.o=.d)

.PHONY: all
all:	$(OBJS_LIB)

$(DEPS_LIB): %.d:%.c
	$(CC) $(CFLAGS_LIB) -MM $< >$@

$(OBJS_LIB): $(SRCS_LIB)
	$(CC) $(CFLAGS_LIB) -c $^

-include $(DEPS_LIB)

.PHONY: clean
clean:
	rm -rf $(OBJS_LIB) $(DEPS_LIB)
