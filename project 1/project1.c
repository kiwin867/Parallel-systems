#include <stdio.h>
#include <stdlib.h>

void multiplyMatrix(double* m1[], double* m2[], double* res[], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = 0;
            for (int k = 0; k < size; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
                printf("in multiply, res[%d][%d] = %f, k = %d\n", i, j, res[i][j], k);
            }
            printf("in multiply, res[%d][%d] = %f\n", i, j, res[i][j]);
        }
    }
    printf("left mul success\n");
}

void swap(double* m1[], double* m2[], int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m2[i][j] = m1[i][j];
            printf("in swap\n");
        }
    }
}

void matrix_power(double* A[], int p, double* Out[], int size){
    printf("in power\n");
    double** base = malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        base[i] = malloc(size * sizeof(double));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0 ; j < size; j++) {
            base[i][j] = A[i][j];
        }
    }
    double** res = malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        res[i] = malloc(size * sizeof(double));
    }
    double** temp = malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        temp[i] = malloc(size * sizeof(double));
    }
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         temp[i][j] = 0;
    //     }
    // }
    printf("in power after init\n");
    int i = 0;
    int j = 0;
    printf("size = %d, i = %d, j = %d\n", size, i, j);
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         res[i][j] = 0;
    //         printf("ret[%d][%d] = %f\n", i, j, res[i][j]);
    //     }
    // }
    while (i < size && j < size) {
        res[i][j] = 1;
        printf("ret[%d][%d] = %f\n", i, j, res[i][j]);
        i++;
        j++;
    }
    i = 0;
    j = 0;
    while (p > 0) {
        if (p % 2 == 1) {
            printf("before multiply, p = %d\n", p);
            multiplyMatrix(res, base, temp, size);
            printf("before multiply after\n");
            swap(temp,res, size);
            printf("after swap\n");
        }
        printf("after swap\n");
        if (p > 1) {
            printf("before multiply, p = %d\n", p);
            multiplyMatrix(base, base, temp, size);
            printf("before multiply after\n");
            swap(temp,base, size);
            printf("after swap 2\n");
        }
        printf("after swap\n");
        p = p/2;
        printf("after swap\n");
    }
    printf("after swap\n");
    for (int i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            Out[i][j] = res[i][j];
            printf("res[%d][%d] = %f\n", i, j, res[i][j]);
            printf("Out[%d][%d] = %f\n", i, j, Out[i][j]);

        }
    }
}

int main(){
    printf("before power\n");
    double** A = malloc(2*sizeof(double*));
    A[0] = malloc(2*sizeof(double));
    A[1] = malloc(2*sizeof(double));
    printf("before power\n");
    int size = 2;
    A[0][1] = 4;
    A[1][1] = 1;
    A[1][0] = 5;
    A[0][0] = 3;
    int p = 3;
    double** Out = malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        Out[i] = malloc(size * sizeof(double));
    }
    printf("before power\n");
    matrix_power(A, p, Out, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("good here?\n");
            printf("Out[%d][%d] = %f\n", i, j, Out[i][j]);
            printf("A[%d][%d] = %f\n", i, j,A[i][j]);
            printf("after power\n");
        }
    }
}
