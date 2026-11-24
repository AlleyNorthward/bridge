all: main.exe

main.exe: build/main.o build/vector.o
	gcc build/main.o build/vector.o -o main.exe

build/main.o: main.c vector.h
	mkdir -p build
	gcc -std=c11 -c main.c -o build/main.o

build/vector.o: vector.c vector.h
	mkdir -p build
	gcc -std=c11 -c vector.c -o build/vector.o

clean:
	rm -rf build main.exe

.PHONY: all clean
