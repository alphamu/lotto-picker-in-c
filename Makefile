CFLAGS=-Wall -g

all:
	gcc lotto.c -o lotto.bin

clean:
	rm -f lotto.bin
