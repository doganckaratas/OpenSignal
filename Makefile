# OpenSignal
# Top Level Makefile
# Dogan C. Karatas | 2018 | GNU GPL v3

CC = gcc
MAKE = make
INSTALL =  _install

.PHONY: all
all:
	$(MAKE) -C ./numerical all V=1
	$(MAKE) -C ./test/numerical all V=1

.PHONY: install
install: all
	$(MAKE) -C ./numerical install V=1
	$(MAKE) -C ./test/numerical install V=1

.PHONY: clean
clean:
	${MAKE} -C ./numerical clean V=1
	${MAKE} -C ./test/numerical clean V=1
	rm -rf ${INSTALL}
