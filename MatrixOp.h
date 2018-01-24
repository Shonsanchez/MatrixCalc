//
// Created by Shon on 1/19/2018.
//

#ifndef MATRIXCALC_MATRIXOP_H
#define MATRIXCALC_MATRIXOP_H
#define NEGATIVE_ONE -1
/**
 * A matrix struct that contains the number of rows
 * and columns of the matrix along with the inputs.
 */
typedef struct{
    int rowC; //Row count
    int curRow; // Current row
    int colC; //Column count
    int curCol; // Current column
    int** matrix; //the matrix
}Matrix;

/**
 * Creates a pointer to a matrix struct. Allocates enough 
 * space to hold a two dimensional array.
 * @param row - the number of rows the matrix has
 * @param col - the number of columns of the matrix
 * @return - a pointer to a matrix with row rowC and col colC
 */
Matrix* createMatrix(int row, int col);


/**
 * Frees up the memory in the matrix. 
 * @param m - the matrix to free.
 */
void destroyMatrix(Matrix* m);

/**
 * Displays the matrix in standard output
 * @param m - the matrix to be printed.
 */
void printMatrix(Matrix* m);

/**
 * Adds two matrices together by adding each row,column from m2 to m1
 * @param m1 - the first matrix
 * @param m2  - the second matrix
 * @return the summation of the matrices
 */
Matrix* addMatrix(Matrix* m1, Matrix* m2);

/**
 * Subtracts the entries in row,col from m1 by m2
 * @param m1 - the first matrix
 * @param m2 - the second matrix
 * @return - the subtraction of the matrix
 */
Matrix* subMatrix(Matrix* m1, Matrix* m2);

/**
 * Multiplies two matrices
 * @param m1 - the first matrix
 * @param m2 - the second matrix
 * @return - the multiplication of the matrices
 */
Matrix* multMatrix(Matrix* m1, Matrix* m2);

/**
 * Checks for the dimensions of the matrix and calculates a determinate
 * for the matrix if it is 2 dimensional, else recursively creates a 
 * smaller dimensioned matrix until a determinate can be computed.
 * @param m - a squared matrix
 * @return - the determinate of the matrix
 */
int determinate(Matrix* m);

/**
 * Creates a new matrix that is the reciprocal
 * @param m - the matrix to invert
 * @return - an inverted matrix or NULL if matrix cannot be inverted
 */
Matrix* inverseM(Matrix* m);

/**
 * Takes the rows of the matrix and convert them into columns.
 * @param m- the matrix to transpose
 * @return - the transpose of the matrix
 */
Matrix* transposeM(Matrix* m);

#endif //MATRIXCALC_MATRIXOP_H
