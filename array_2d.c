#include<stdio.h>
#include<stdlib.h>
#include<windows.h>




extern char number;
void sudokuPrint(char(*p)[10][2])
{
    for(int i=0; i<10; i++)
    {

        for(int j=0; j<10; j++)
        {
            if(p[i][j][1]=='0')
            {
               // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
                printf("%5c",p[i][j][0]);
            }
            else
            {
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|COMMON_LVB_REVERSE_VIDEO);
                printf("%5c",p[i][j][0]);
            }



        }
        printf("\n\n");
    }
}

void sudoku_input(char(*p)[10][2],int x, int y)
{

    if(p[x][y][1]=='0')
    {

        p[x][y][0]= number;

    }
    else
    {
        printf("you can't change the fixed number \n") ;
    }
}


int sudoku_empty_counter(char(*p)[10][2])
{
    int counter =0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if (p[i][j][0]=='_'||p[i][j][0]=='#')counter++;
        }
    }
    return counter;
}


void positionHashing(char(*p)[10][2],int x,int y)
{

    if(p[x][y][1]=='0') p[x][y][0]='#';
    else
    printf("you can't change the fixed number \n") ;

}

int sudoku_check(char(*p)[10][2])
{
    for(int i =1 ; i <10 ; i++ )
    {
        for(int j=1 ;j<10 ;j++)
        {
            if(p[1][i]==p[1][j+1])
                return 0;
        }
    }
    for(int i =1 ; i <10 ; i++ )
    {
        for(int j=1 ;j<10 ;j++)
        {
            if(p[i][1]==p[j+1][1])
                return 0;
        }
    }
    return 1;
}
















