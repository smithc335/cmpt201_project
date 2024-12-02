# Claire Smith and Matt Beaulieu
# Makefile in Main Directory

CC=gcc
CFLAGS=-Wall -std=c11

project: test_palette.o pigment.o
	$(CC) $(CFLAGS) $^ -o $@
	mv *.o obj
	mv $@ bin

test_colour: test_colour.o pigment.o
	$(CC) $(CFLAGS) $^ -o $@
	mv *.o obj
	mv $@ bin

%.o: src/%.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean package

clean:
	rm -f obj/*.o
	rm -f bin/*

package:
	tar -czvf cmpt201_project_lab11_CS_MB.tar.gz README.md bin data makefile obj src