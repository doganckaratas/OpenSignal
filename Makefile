# OpenSignal
# Top Level Makefile
# Dogan C. Karatas | 2018 | GNU GPL v3

INSTALL=_install
CC=gcc
MAKE=make

TARGET_LIB=libopensignal.so
CFLAGS_LIB=-I./include -g -ggdb -O0
LDFLAGS_LIB=-lm -shared
SRCS_LIB=$(wildcard ./numerical/*.c)
OBJS_LIB=$(SRCS_LIB:.c=.o)
DEPS_LIB=$(OBJS_LIB:.o=.d)

TARGET_TEST_NUMERICAL=test_numerical
SRCS_TEST_NUMERICAL=$(wildcard ./test/numerical/*.c)
OBJS_TEST_NUMERICAL=$(SRCS_TEST_NUMERICAL:.c=.o)
DEPS_TEST_NUMERICAL=$(OBJS_TEST_NUMERICAL:.o=.d)
CFLAGS_TEST_NUMERICAL=-I./include -g -ggdb -O0
LDFLAGS_TEST_NUMERICAL=-L.
LIBS_TEST_NUMERICAL=-lm -lopensignal

.PHONY: lib
lib:	$(TARGET_LIB)

.PHONY: all
all:	lib tests
	
.PHONY: tests
tests:	$(TARGET_TEST_NUMERICAL)

.PHONY: clean
clean:
	$(MAKE) -C ./numerical clean V=1
	$(MAKE) -C ./test/numerical clean V=1
	rm -rf $(TARGET_LIB)
	rm -rf $(TARGET_TEST_NUMERICAL)
	rm -rf $(INSTALL)

.PHONY: install
install: all
	mkdir -p $(INSTALL)
	cp -frv $(TARGET_LIB) $(INSTALL)
	cp -frv $(TARGET_TEST_NUMERICAL) $(INSTALL)

$(TARGET_LIB): 
	$(MAKE) -C numerical all V=1
	$(CC) $(CFLAGS_LIB) -o $@ ${OBJS_LIB} $(LDFLAGS_LIB) 

$(TARGET_TEST_NUMERICAL): 
	$(MAKE) -C test/numerical all V=1
	$(CC) $(CFLAGS_TEST_NUMERICAL) -o $@ ${OBJS_TEST_NUMERICAL} $(LDFLAGS_TEST_NUMERICAL) $(LIBS_TEST_NUMERICAL) 

