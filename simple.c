#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 10  // Maximum matrix size

int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Two matricies should be defined\n");
        return 1;
    }

    // TODO use argv - using random values for now
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;  // Initialize C matrix
        }
    }

    // Parallelize basic matrix multiplication 
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display the result
    printf("Result Matrix:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
