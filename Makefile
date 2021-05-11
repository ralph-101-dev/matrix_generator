all: matrix_generator.o
	gcc matrix_generator.o -o ./matrix_generator -fopenmp

matrix_generator.o:
	gcc matrix_generator.c -c

clean:
	rm ./*.o matrix_generator