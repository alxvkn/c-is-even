CC = clang

is_even: is_even.o
	$(CC) $(LDFLAGS) $^ -o $@

test: test.o is_even
	$(CC) $< -o $@

is_even.o: gen is_even.c
	./gen > _is_even.c
	cat is_even.c >> _is_even.c
	$(CC) $(CFLAGS) -c _is_even.c -o is_even.o

gen: gen.o
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f is_even *.o _is_even.c gen test
