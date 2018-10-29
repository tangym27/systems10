all: rand.c
	gcc -o test rand.c

run: all
	./test

clean:
		rm test
		rm *.out
		rm arrFile
