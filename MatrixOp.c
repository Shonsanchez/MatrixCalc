//
// Created by Shon on 1/19/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "MatrixOp.h"

Matrix* createMatrix(int row, int col){
	assert(row);
	assert(col);
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

void destroyMatrix(Matrix* m){
	assert(m);
	assert(m->matrix);
	int row =  m->rowC;
	for(int r = 0; r < row; r++){
		free(m->matrix[r]);
	}
	free(m->matrix);
	free(m);
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

Matrix* decrementM(Matrix* m, int row, int col){
	Matrix* r = createMatrix(m->rowC-1,m->rowC-1);
	int mrow = 0;//The row of matrix m
	int mcol = 0;
	for(int rrow = 0; rrow < r->rowC; rrow++,mrow++){
		mrow == row ? mrow++: row;
		for(int rcol = 0, mcol = 0; rcol < r->rowC; rcol++, mcol++){
			mcol == col ? mcol++ : col;
			r->matrix[rrow][rcol] = m->matrix[mrow][mcol];
		}
	}
	return r;
}

int determinate(Matrix* m){
	assert(m->rowC > 1);
	if(m->rowC == 2){
		int a = m->matrix[0][0];
		int b = m->matrix[0][1];
		int c = m->matrix[1][0];
		int d = m->matrix[1][1];
		return(a*d - b*c);
	}
	int sum = 0;
	Matrix *d;
	for(int col = 0; col < m->colC; col ++){
		d = decrementM(m,0,col);
		sum += pow(-1,col+2)*m->matrix[0][col]*determinate(d);
		destroyMatrix(d);
	}
	return sum;
}

Matrix* inverseM(Matrix* m){
	if(m->rowC ==2){
		return determinate(m);
	}
	return NULL;
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


