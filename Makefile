PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	gcc $(CFLAGS) -I$(PREFIX)/include src/main.c src/winman.c -L$(PREFIX)/lib -lX11 -o justwm

clean:
	rm -f justwm
