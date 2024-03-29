PREFIX ?= /usr/local
CC ?= cc
LDFLAGS = -lX11
HOST=$(shell hostname)

ifeq ($(HOST), core)
	ANY_VAR=LAPTOP 
else
	ANY_VAR=PC
endif

output: dwmblocks.c blocks.def.h blocks.h
	${CC}  -D$(ANY_VAR) dwmblocks.c $(LDFLAGS) -o dwmblocks
blocks.h:
	cp blocks.def.h $@


clean:
	rm -f *.o *.gch dwmblocks
install: output
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 dwmblocks $(DESTDIR)$(PREFIX)/bin/dwmblocks
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmblocks
