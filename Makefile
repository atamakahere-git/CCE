engine:
	mkdir -p build
	gcc -Wall src/main.c src/init.c -o build/cce


default: engine

