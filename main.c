#include <stdio.h>
#include <stdlib.h>
#include "MatrixOp.h"

int main() {
  //int choice;
  int row = 0;
  int col = 0;
  printf("Welcome to MatrixCalc.\n");
//   while(choice > 5 || choice < 1){
//        printf("Please select an option\n");
//        printf("1)Addition\n"
//                       "2)Subtraction\n"
//                       "3)Transpose\n"
//                       "4)inverse\n"
//                       "5)Muliplication\n");
//        scanf("%i",&choice);
 //   }
    printf("Enter the number of rows and column in your matrix (ex:3 2)\n");
    scanf("%i %i", &row, &col);
    Matrix* m = createMatrix(row,col);
    printf("\n");
    for (int i = 0; i < row; i++) {
        printf("Enter %i integers for row %i (separated by spaces)\n", col, i+1);
        for (int j = 0; j < col; j++) {
            scanf("%i", &m->matrix[i][j]);
        }
    }
    printf("\n\n");
    printMatrix(m);
    Matrix* m2 = transposeM(m);
    printf("The transpose of your matrix is\n");
    printMatrix(m2);
    printf("You have selected a %i by %i matrix\n", row,col);
    return 0;
}
