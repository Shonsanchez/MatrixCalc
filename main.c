#include <stdio.h>

int main() {
    int choice = 0;
    int row;
    int col;
    int** matrix;
    int*** matrices;
    printf("Welcome to MatrixCalc.\n");
    while(choice > 5 || choice < 1){
        printf("Please select an option\n");
        printf("1)Addition\n"
                       "2)Subtraction\n"
                       "3)Transpose\n"
                       "4)inverse\n"
                       "5)Muliplication\n");
        scanf("%i",&choice);
    }
    printf("Enter the number of rows and column in your matrix (ex:3 2)\n");
    scanf("%i %i", &row, &col);
    printf("You have selected a %i by %i matrix\n", row,col);
    return 0;
}