#include <stdio.h>
#include <stdlib.h>
#include "MatrixOp.h"

//Prompt the user for matrix information 
Matrix* promptMatrix(){	
	int row = 0;
	int col = 0;
	printf("Enter the number of rows and columns in your matrix (ex:3 2)\n");
	scanf("%i %i", &row, &col);
	printf("You have selected a %i by %i matrix\n", row,col);
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

int main() {
	int choice = 0;
	printf("Welcome to MatrixCalc.\n");
	while(choice > 5 || choice < 1){
		printf("Please select an option\n");
        printf("1)Addition\n"
			   "2)Subtraction\n"
			   "3)Transpose\n"
			   "4)inverse\n"
			   "5)Muliplication\n\n");
        scanf("%i",&choice);
	}
    printf("\n\n");
    Matrix* m = promptMatrix();
	printMatrix(m);
	printf("The transpose of your matrix is\n");
    Matrix* m2 = transposeM(m);
    printMatrix(m2);
	if(m)
		destroyMatrix(m);
	if(m2)
		destroyMatrix(m2);
    return 0;
}
