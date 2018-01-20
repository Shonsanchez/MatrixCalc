//
// Created by Shon on 1/19/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "MatrixOp.h"

Matrix* createMatrix(int row, int col){
	Matrix* m = malloc(sizeof(Matrix));
	m->matrix = malloc(sizeof(int*)*row);
	for (int i = 0; i < row; ++i) {
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
			printf("%3.i ",m->matrix[i][j]);
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

Matrix* subMatrix(Matrix* m1, Matrix* m2){
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

int multHelper(Matrix* m1, Matrix* m2, int row, int col){
	int sum = 0;
	int max = m1->colC;
	for(int i = 0; i < max; i++)
		sum += m1->matrix[row][i] * m2->matrix[i][col];
	return sum;
}

Matrix* multMatrix(Matrix* m1, Matrix* m2){
	if(m1->colC != m2->rowC)
		return NULL;
	int rowC = m1->rowC;
	int colC = m2->colC;
	Matrix* m3 = createMatrix(rowC, colC);
	for(int row = 0; row < rowC; row++){
		for(int col = 0 ; col < colC; col++){
			m3->matrix[row][col] = multHelper(m1,m2,row,col);
		}
	}

	return m3;
}



Matrix* transposeM(Matrix* m){
	int row = m->rowC;
	int col = m->colC;
	Matrix* m2 = createMatrix(col, row);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m2->matrix[j][i] = m->matrix[i][j];
		}
	}
	return m2;
}


