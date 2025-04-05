#include <stdio.h>
#include "compute.h"

extern int yylex();

void computeMatrixProduct() {
    int token = yylex(); // compute
    if (token != COMPUTE) {
        printf("Expected 'compute'\n");
        return;
    }

    token = yylex(); // M
    if (token != M) {
        printf("Expected 'M'\n");
        return;
    }

    token = yylex(); // =
    if (token != EQUALS) {
        printf("Expected '='\n");
        return;
    }

    token = yylex(); // A
    if (token != A) {
        printf("Expected 'A'\n");
        return;
    }

    token = yylex(); // *
    if (token != MULTIPLY) {
        printf("Expected '*'\n");
        return;
    }

    token = yylex(); // B
    if (token != B) {
        printf("Expected 'B'\n");
        return;
    }

    token = yylex(); // ;
    if (token != END) {
        printf("Expected ';'\n");
        return;
    }

    double matA[3][2], matB[2][2], matC[3][2];

    printf("Enter values for 3x2 matrix A (row-wise):\n");
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
            scanf("%lf", &matA[i][j]);

    printf("Enter values for 2x2 matrix B (row-wise):\n");
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            scanf("%lf", &matB[i][j]);

    // Multiply A * B -> C
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j) {
            matC[i][j] = 0;
            for (int k = 0; k < 2; ++k)
                matC[i][j] += matA[i][k] * matB[k][j];
        }

    printf("Resultant 3x2 Matrix (A * B):\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j)
            printf("%8.2f ", matC[i][j]);
        printf("\n");
    }
}
