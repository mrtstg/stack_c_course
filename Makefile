all: run

build: lib/ lib/*.c main.c target/
	gcc main.c lib/*.c -o target/bin

run: lib/ lib/*.c main.c
	make build && ./target/bin
