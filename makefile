build:
	gcc main.c -lSDL2 -o demo

release:
	gcc main.c -O3 -lSDL2 -o demo
	strip demo

run: build
	./demo

.DEFAULT: release 