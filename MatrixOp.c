//
// Created by Shon on 1/19/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "MatrixOp.h"

Matrix* createMatrix(int row, int col){
    Matrix* m = malloc(sizeof(Matrix*));
    m->matrix = malloc(sizeof(int*)*row);
    for (int i = 0; i < col; ++i) {
        m->matrix[i] = malloc(sizeof(int) *col);
    }
    m->rowC = row;
    m->colC = col;
    m->curCol = 0;
    m->curRow = 0;
    return m;
}

void printMatrix(Matrix* m){
    int row = m->rowC;
    int col = m->colC;
    for (int i = 0; i < row; ++i) {
        for(int j=0; j < col; j++){
            printf("%i ",m->matrix[i][j]);
        }
        printf("\n");
    }
}

Matrix* addMatrix(Matrix* m1, Matrix* m2){
    Matrix* m3 = createMatrix(m1->rowC,m2->colC);
    int row = m1->rowC;
    int col = m1->colC;
    for (int i = 0; i < row; ++i) {
        for(int j=0; j < col; j++){
            m3->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
        }
    }
    return m3;
}
