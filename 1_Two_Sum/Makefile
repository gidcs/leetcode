CC=g++
CFLAGS=-I.
DEPS = src/solution.hpp
OBJ = main.o src/solution.o
PROG = main

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(OBJ) $(PROG)

