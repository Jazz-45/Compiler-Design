all: compute

compute: lex.yy.c compute.o main.o
	$(CC) -o compute lex.yy.c compute.o main.o -lfl

lex.yy.c: compute.l
	flex compute.l

compute.o: compute.c compute.h
	$(CC) -c compute.c

main.o: main.c compute.h
	$(CC) -c main.c

clean:
	rm -f *.o lex.yy.c compute
