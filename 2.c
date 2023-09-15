// Create a program to perform the following operation
// 1. Check whether the given matrix is sparse or dense
// 2. Calculate the operations (addition, deletion & multi) of two matrices

#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int isSparse(int matrix[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }
    return count > (ROWS * COLS) / 2;
}

void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLS];

    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    if (isSparse(matrix1)) {
        printf("\nMatrix 1 is sparse.\n");
    } else {
        printf("\nMatrix 1 is dense.\n");
    }

    if (isSparse(matrix2)) {
        printf("Matrix 2 is sparse.\n");
    } else {
        printf("Matrix 2 is dense.\n");
    }

    printf("\nMatrix 1 + Matrix 2:\n");
    addMatrices(matrix1, matrix2, result);
    printMatrix(result);

    printf("\nMatrix 1 - Matrix 2:\n");
    subtractMatrices(matrix1, matrix2, result);
    printMatrix(result);

    printf("\nMatrix 1 * Matrix 2:\n");
    multiplyMatrices(matrix1, matrix2, result);
    printMatrix(result);

    return 0;
}
