# The -sdt=gnu89 is because I developed all this on Ubuntu but wanted 
# to ensure it runs on Nitron which uses gnu89 as its default c version.
STD = -std=gnu89 -g -Wall

all: tests

tests: tests.c bst.h bst.o
	gcc $(STD) -o tests tests.c bst.o

bst.o: bst.h bst.c
	gcc -c $(STD) bst.c

check:
	egrep 'is_empty_tree|value_is_less_than_|value_is_more_than|less_sub_tree|more_sub_tree|empty_tree' bst.c

clean:
	rm -f *.o
	rm -f tests
