all: main.o eles.h
	gcc -o output main.o

main.o: main.c eles.h
	gcc -c main.c

run:
	./output

clean:
	rm output
	rm *.o
