CFLAGS = -g -Wall -pedantic
CFLAGS_T=-g -Wall -pedantic -pthread

.PHONY: all
all: malloc

repl: malloc.c
	echo "Compiling malloc.c"
	gcc $(CFLAGS_T) -o $@ $^

.PHONY: clean
clean:
	rm -f *.o malloc