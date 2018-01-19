//
// Created by Shon on 1/19/2018.
//
#include <stdlib.h>
#include "MatrixOp.h"

Matrix* createMatrix(int row, int col){
    Matrix* m = malloc(sizeof(Matrix*));
    m->matrix = malloc(sizeof(int**)*col);
    for (int i = 0; i < col; ++i) {
        m->matrix[i] = malloc(sizeof(int*) *row);
    }
    return m;
}

Matrix* addMatrix(Matrix* m1, Matrix* m2){
    Matrix* m3 = createMatrix(m1->rowC,m2->colC);
    return m3;
}
