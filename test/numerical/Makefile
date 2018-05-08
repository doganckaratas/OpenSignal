# OpenSignal
# Numerical Library Test Makefile
# Dogan C. Karatas | 2018 | GNU GPL v3

TARGET = test_numerical
INSTALL = ../../_install
CC = gcc
CFLAGS = -I../../include -g -Wall -Wextra -Werror $(TEST)
LIBS = -lm -lnumerical -L../../numerical

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

#TEST+=-DCOMPLEX_TEST
#TEST+=-DPOLAR_TEST
TEST+=-DMATRIX_TEST
#TEST+=-DMATRIX_BASIC_TEST
#TEST+=-DMATRIX_COMPARE_TEST
#TEST+=-DMATRIX_IDENTITY_TEST
TEST+=-DMATRIX_COPY_TEST
#TEST+=-DMATRIX_DETERMINANT_TEST
TEST+=-DMATRIX_TRANSPOSE_TEST
TEST+=-DVECTOR_TEST
TEST+=-DVECTOR_BASIC_TEST

.PHONY: all
all: ${TARGET}

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: install
install: all
	$(shell if [ ! -d ${INSTALL} ];	then mkdir ${INSTALL}; fi;)
	cp -f ${TARGET} ${INSTALL}/${TARGET}

.PHONY: clean
clean:
	rm -f ${TARGET} ${OBJS}
	rm -f ${INSTALL}/${TARGET}
