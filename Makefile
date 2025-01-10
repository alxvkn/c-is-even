CC = clang

is-even: is-even.o is_even.o
	$(CC) $(LDFLAGS) $^ -o $@

test: test.o is_even.o
	$(CC) $^ -o $@

is_even.o: gen is_even.c
	$(CC) $(CFLAGS) -c is_even.c -o is_even.o

is_even.c: gen
	./gen > $@

gen: gen.o
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f is-even *.o is_even.c gen test
