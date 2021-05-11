#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>

#define BUF_SIZE 1024

void print_matrix(FILE* file, int *matrix, int m, int n);

int main(int argc, char **argv) {
    int m, n;
    int end_number;
    int *matrix;
    char filename[BUF_SIZE] = {0, };
    FILE* file;
    struct timeval start, end;
    double diffTime;

    if(argc != 4) {
        fprintf(stderr, "Usage : %s <m> <n> <end_number>\n", argv[0]);
        exit(1);
    }

    m = atoi(argv[1]);
    n = atoi(argv[2]);

    // if(m > 20000 || n > 20000) {
    //     fprintf(stderr, "matrix maximum size is 20000 by 20000\n");
    //     exit(1);
    // } else 
    if(m <= 3 || n <= 3) {
        fprintf(stderr, "matrix minimum size is 4 by 4\n");
        exit(1);
    }   

    end_number = atoi(argv[3]) + 1;
    matrix = malloc(sizeof(int)*m*n);

    printf("%d by %d matrix generate time is ", m, n);
    fflush(stdout);
    srand(time(NULL));

    gettimeofday(&start, NULL);

    #pragma omp parallel for collapse(2)
    {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i*n+j] = rand() % end_number;
            }
        }
    }

    sprintf(filename, "./result/%d_by_%d_matrix.matrix", m, n);
    file = fopen(filename, "w");

    print_matrix(file, matrix, m, n);

    gettimeofday(&end, NULL);

    diffTime = (double)1000*( end.tv_sec - start.tv_sec ) + (( end.tv_usec - start.tv_usec ) / (double)1000);

    printf("%lf ms\n", diffTime);

    fclose(file);

    free(matrix);

    exit(0);
}

void print_matrix(FILE* file, int *matrix, int m, int n) {
    char buf[BUF_SIZE] = {0, };

    if(file == NULL) return;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(j+1 == n) {
                sprintf(buf, "%d\n", matrix[i * n + j]);
            } else {
                sprintf(buf, "%d ", matrix[i * n + j]);
            }
            fwrite(buf, strlen(buf), 1, file);
        }
    }
}