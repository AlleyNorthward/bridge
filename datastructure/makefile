all: main.exe

main.exe: build/main.o build/vector.o
	gcc build/main.o build/vector.o -o build/main.exe

build/main.o: main.c include/c/vector.h
	mkdir -p build
	gcc -std=c11 -c main.c -o build/main.o

build/vector.o: include/c/vector.c include/c/vector.h
	mkdir -p build
	gcc -std=c11 -c include/c/vector.c -o build/vector.o

clean:
	rm -rf build

.PHONY: all clean
