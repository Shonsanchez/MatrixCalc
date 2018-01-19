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
    int** matrix; //the matrix
}Matrix;

Matrix* createMatrix(int row, int col);

/**Adds two matrices together by adding each row,column from m2 to m1
 * @param m1 - the first matrix
 * @param m2  - the second matrix
 * @return the summation of the matrices
 */
Matrix* addMatrix(Matrix* m1, Matrix* m2);

/**Subtracts the entries in row,col from m1 by m2
 * @param m1 - the first matrix
 * @param m2 - the second matrix
 * @return - the subtraction of the matrix
 */
Matrix* subMatrix(Matrix* m1, Matrix* m2);

/**Multiplies two matrices
 * @param m1 - the first matrix
 * @param m2 - the second matrix
 * @return - the multiplication of the matrices
 */
Matrix* multMatrix(Matrix* m1, Matrix* m2);


Matrix* inverseM(Matrix* m);

/**
 * Takes the rows of the matrix and convert them into columns.
 * @param m- the matrix to transpose
 * @return - the transpose of the matrix
 */
Matrix* transposeM(Matrix* m);

#endif; //MATRIXCALC_MATRIXOP_H