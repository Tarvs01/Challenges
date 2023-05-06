/* The challenge is to draw an art of an among us character using console */

//This is an ASCII/console art challenge

#include <stdio.h>

int main() 
{
    int ar[10][8] = {0};
    int x,y;
    for (x=0; x<10; x++)
    {
        for (y=0; y<8; y++)
        {
            if ((x==0 && y>1 && y<6) || ((y==1 || y==6) && x>0 && x<10) || (x==9 && y>0 && y<7) || (y==0 && x>2 && x<7) || ((x==2 || x==4) && y>4 && y<8) || ((y==3 || y==4) && x>6))
            ar[x][y]=1;
        }
    }
    ar[3][6]=0;
    ar[3][5]=ar[3][7]=1;
    for (x=0; x<10; x++)
    {
        for (y=0; y<8; y++)
        {
            if (ar[x][y]==1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        puts("");
    }
    printf("Among us 😅😅😅");
    return 0;
}