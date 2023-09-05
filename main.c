#include <stdio.h>
#include <stdlib.h>
//#include<conio.h>
void sudoku_input(int(*p)[10][2],int x, int y);
void sudokuPrint(int(*p)[10][2]);
int sudoku_empty_counter(int(*p)[10][2]);
char intial_sudoku[10][10][2]=
{
    {{' ','1'},{'1','1'},{'2','1'},{'3','1'},{'4','1'},{'5','1'},{'6','1'},{'7','1'},{'8','1'},{'9','1'}},
    {{'1','1'},{'5','1'},{'3','1'},{'_','0'},{'_','0'},{'7','1'},{'_','0'},{'_','0'},{'_','0'},{'_','0'}},
    {{'2','1'},{'6','1'},{'_','0'},{'_','0'},{'1','1'},{'9','1'},{'5','1'},{'_','0'},{'_','0'},{'_','0'}},
    {{'3','1'},{'_','0'},{'9','1'},{'8','1'},{'_','0'},{'_','0'},{'_','0'},{'_','0'},{'6','1'},{'_','0'}},
    {{'4','1'},{'8','1'},{'_','0'},{'_','0'},{'_','0'},{'6','1'},{'_','0'},{'_','0'},{'_','0'},{'3','1'}},
    {{'5','1'},{'4','1'},{'_','0'},{'_','0'},{'8','1'},{'_','0'},{'3','1'},{'_','0'},{'_','0'},{'1','1'}},
    {{'6','1'},{'7','1'},{'_','0'},{'_','0'},{'_','0'},{'2','1'},{'_','0'},{'_','0'},{'_','0'},{'6','1'}},
    {{'7','1'},{'_','0'},{'6','1'},{'_','0'},{'_','0'},{'_','0'},{'_','0'},{'2','1'},{'8','1'},{'_','0'}},
    {{'8','1'},{'_','0'},{'_','0'},{'_','0'},{'4','1'},{'1','1'},{'9','1'},{'_','0'},{'_','0'},{'5','1'}},
    {{'9','1'},{'_','0'},{'_','0'},{'_','0'},{'_','0'},{'8','1'},{'_','0'},{'_','0'},{'7','1'},{'9','1'}},


};
char number;

int main()
{
    int x,y,numberEmpty,editOption=1,result;
    numberEmpty=sudoku_empty_counter(intial_sudoku);
    sudokuPrint(intial_sudoku);
    while(numberEmpty)
    {

        printf(" X position = ");
        scanf("%d",&x);
        printf(" Y position = ");
        scanf("%d",&y);

        positionHashing(intial_sudoku,x,y);
        system("cls");
        sudokuPrint(intial_sudoku);

        printf(" Number = ");
        fflush(stdin);
        scanf("%c",&number);

        sudoku_input(intial_sudoku,x,y);
        system("cls");
        sudokuPrint(intial_sudoku);
        numberEmpty=sudoku_empty_counter(intial_sudoku);
    }

    while(editOption)
    {
        printf("Are you want to edit ? '1' for ok '0' for no ");
        scanf("%d",&editOption);
        if (editOption==0)
            break;
        else
            printf(" X position = ");
            scanf("%d",&x);
            printf(" Y position = ");
            scanf("%d",&y);

            positionHashing(intial_sudoku,x,y);
            system("cls");
            sudokuPrint(intial_sudoku);

            printf(" Number = ");
            fflush(stdin);
            scanf("%c",&number);

            sudoku_input(intial_sudoku,x,y);
            system("cls");
            sudokuPrint(intial_sudoku);
    }
    result = sudoku_check(intial_sudoku);
    if(result==1)printf("-Good work-");
    else printf("-NOT Correct !-");





    return 0;
}
