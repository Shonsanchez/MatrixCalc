#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "MatrixOp.h"

Matrix* initializeM(int row, int col){
	Matrix* m = createMatrix(row,col);
	printf("\n");
	for (int i = 0; i < row; i++) {
        printf("Enter %i integers for row %i (separated by spaces)\n", col, i+1);
        for (int j = 0; j < col; j++) {
            scanf("%i", &m->matrix[i][j]);
        }
    }
	return m;
}

//Prompt the user for matrix information 
Matrix* promptMatrix(){	
	int row = 0;
	int col = 0;
	printf("Enter the number of rows and columns in your matrix (ex:3 2)\n");
	scanf("%i %i", &row, &col);
	assert(row);
	assert(col);
	return initializeM(row,col);
}

Matrix* promptMatrixRC(int row, int col, int squared){
	if(squared){
		printf("Enter the dimension of your matrix\n");
		scanf("%i" , &row);
		col = row;
	}else{
		if(row == 0){
			printf("Enter the number of rows in your matrix\n");
			scanf("%i", &row);
		}
		if(col == 0){
			printf("Enter the number of columns in your matrix\n");
			scanf("%i", &col);
		}
		assert(row);
		assert(col);	
	}
	return initializeM(row, col);
}

int main() {
	int choice = 0; // choice for the operation to perform on matrix or matrices
	Matrix* m1 = NULL; // the first matrix
	Matrix* m2 = NULL; // the second matrix
	Matrix* r = NULL; // the resulting matrix
	int d;
	printf("Welcome to MatrixCalc.\n");
	while(choice > 6 || choice < 1){
		printf("Please select an option\n");
        printf("1)Addition\n"
			   "2)Subtraction\n"
			   "3)Muliplication\n"
			   "4)Determinate\n"
			   "5)Inverse\n"
			   "6)Transpose\n\n");
        scanf("%i",&choice);
	}
    printf("\n\n");
	if(choice == 4 || choice == 5){
	   	m1 = promptMatrixRC(0,0,1);
	}else
		m1 = promptMatrix();
	printf("You have entered the following matrix\n");
	printMatrix(m1);
	switch(choice){
	case 1:
		m2 = promptMatrixRC(m1->rowC,m1->colC,0);
		printf("You have entered the following matrix\n");
		r = addMatrix(m1,m2);
		printf("The addition of your matrices is\n");
		printMatrix(r);
		break;
	case 2:
		m2 = promptMatrixRC(m1->rowC,m1->colC,0);
		printf("You have entered the following matrix\n\n");
		r = subMatrix(m1,m2);
		printf("The subtraction of your matrices is\n\n");
		printMatrix(r);
		break;
	case 3:
		m2 = promptMatrixRC(m1->colC, 0, 0);
		printf("You have entered the following matrix\n");
		r = multMatrix(m1,m2);
		printf("The product of your matrices is\n\n");
		printMatrix(r);
		break;
	case 4:
		//		printf("Functionality not yet implemented\n\n");
		d = determinate(m1);
		printf("The determinate of your matrix is: %i\n", d);
		break;
	case 5:
		printf("Functionality not yet implemented\n\n");
		break;
	case 6:
		r = transposeM(m1);
		printf("The transpose of your matrix is\n\n");
		printMatrix(r);
		break;
	}
	if(m1)
		destroyMatrix(m1);
	if(m2){
		destroyMatrix(m2);
	}
	if(r)
		destroyMatrix(r);
    return 0;
}
