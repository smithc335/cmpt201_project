# Claire Smith and Matt Beaulieu
# Makefile in src Directory

CC=gcc
CFLAGS=-Wall -std=c11

test_load: test_load.o pigment.o
	$(CC) $(CFLAGS) $^ -o $@

test_value: test_value.o pigment.o
	$(CC) $(CFLAGS) $^ -o $@

test_palette: test_palette.o pigment.o
	$(CC) $(CFLAGS) $^ -o $@

test_colour: test_colour.o pigment.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f test_load test_value test_palette test_colour *.o