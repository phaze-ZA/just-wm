PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	gcc $(CFLAGS) -I$(PREFIX)/include src/main.c -L$(PREFIX)/lib -lX11 -o tinywm

clean:
	rm -f tinywm
