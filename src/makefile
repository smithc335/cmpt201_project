# Claire Smith and Matt Beaulieu
# Makefile in src Directory

CC=gcc
CFLAGS=-Wall -std=c11

test_load: test_load.o pigment.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean package

clean:
	rm -f test_load *.o

package:
	tar -czvf cmpt201_project_lab09_CS_MB.tar.gz *.c *.h makefile
