# Makefile

all:
	gcc -std=c99 -Wall -Wextra mypcm.c lab2.c -o lab2

clean:
	rm -f lab2.exe
