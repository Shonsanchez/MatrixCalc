//
// Created by Shon on 1/19/2018.
//

#ifndef MATRIXCALC_MATRIXOP_H
#define MATRIXCALC_MATRIXOP_H

//**
typedef struct{
    int rowC; //Row count
    int curRow; // Current row
    int colC; //Column count
    int curCol; // Current column
    int** grid; //the matrix
}Matrix;

Matrix* createMatrix(int row, int col);

/**Adds two matrices together by adding each row,column from m2 to m1
 * @param m1 - the first matrix
 * @param m2  - the second matrix
 * @param row - the row count of the matrices
 * @param col - the column count of the matrices
 * @return the summation of the matrices
 */
int** addMatrix(int** m1, int** m2, int row, int col);

/**Subtracts the entries in row,col from m1 by m2
 * @param m1 - the first matrix
 * @param m2 - the second matrix
 * @param row - the row count of the matrices
 * @param col - the column count of the matrices
 * @return - the subtraction of the matrix
 */
int** subMatrix(int** m1, int** m2, int row, int col);

/**Multiplies two matrices
 * @param m1 - the first matrix
 * @param m2 - the second matrix
 * @param row - the row count of the matrices
 * @param col - the column count of the matrices
 * @return - the multiplication of the matrices
 */
int** multMatrix(int** m1, int** m2,int row, int col);


int** inverseM(int** m1, int row, int col);

/**
 * Takes the rows of the matrix and convert them into columns.
 * @param m1 - m1 - the matrix to transpose
 * @param row - the row count of the matrix
 * @param col - the column count of the matrix
 * @return - the transpose of the matrix
 */
int** transposeM(int** m1, int row, int col);

#endif; //MATRIXCALC_MATRIXOP_H