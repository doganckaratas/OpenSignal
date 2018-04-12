TARGET=numerical
CC=gcc
#TEST+=-DCOMPLEX_TEST
#TEST+=-DPOLAR_TEST
TEST+=-DMATRIX_TEST
TEST+=-DMATRIX_BASIC_TEST
TEST+=-DMATRIX_COMPARE_TEST
TEST+=-DMATRIX_IDENTITY_TEST
TEST+=-DMATRIX_COPY_TEST
TEST+=-DMATRIX_TRANSPOSE_TEST
CFLAGS=-I../include -g -Wall -Werror ${TEST}
LIBS=-lm
SRCS:=$(wildcard *.c)

.PHONY: numerical clean

# for now it outputs as executable (-DTEST flag)

$(TARGET): $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean: 
	rm -f $(TARGET)

