CFLAGS=-Wall -g

all:
	gcc lotto.c -o lotto.bin
	gcc lotto.c -o powerball.bin

clean:
	rm -f lotto.bin
