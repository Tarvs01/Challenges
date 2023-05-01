//This code prints out the magic square for odd n*n squares
//A magic square is an n*n square filled with numbers from 1-n*n with each number appearing only once such that the sum of every row,column and the two main diagonals all result in the same number
//sample input = 3
/*sample output =8 1 6
                 3 5 7
                 4 9 2
if you add each row,column and the two main diagonals, you get the sum 15.
*/

//The algorithm I used here only works for odd numbers. so your input should be an odd number between 1-9.
//If you are using a PC or tablet, your input can be more than 9. I put 9 because of those on mobile. Just simply remove lines 31-35

//Check out my other code "Magic Square - All numbers" for a solution to all numbers

#include <stdio.h>

int main() 
{
    int a,b,c,f,d=1;
    scanf("%d",&a);
    if (a%2==0)
    {
        printf("This program is only for odd numbers. Try again");
        return 0;
    }
    if (a<1)
    {
        printf("Your number is invalid. Enter an odd integer greater than 0");
        return 0;
    }
    if (a>9)
    {
        printf("Numbers greater than 9 won't produce a clear result unless you are on PC. The default value of 9 would be used instead.\n\n");
        a=9;
    }
    int bud[a][a];
    for (b=0; b<a; b++)
    {
        for (c=0; c<a; c++)
        {
            bud[b][c]=0;
        }
    }
    bud[0][a/2]=1;
    b=0;
    c=a/2;
    while (d<=a*a)
    {
        if (c<a-1 && b>0 && bud[b-1][c+1]==0)
        {
            bud[b-1][c+1]=++d;
            b=b-1;
            c=c+1;
        }
        else if (c<a-1 && b>0 && bud[b-1][c+1]!=0)
        {
            bud[b+1][c]=++d;
            b=b+1;
            c=c;
        }
        else if (c==a-1 && b==0 && bud[a-1][0]==0)
        {
            bud[a-1][0]=++d;
            b=a-1;
            c=0;
        }
        else if (b==0 && c==a-1 && bud[a-1][0]!=0)
        {
            bud[b+1][c]=++d;
            b=b+1;
            c=c;
        }
        else if (c==a-1 && bud[b-1][0]==0)
        {
            bud[b-1][0]=++d;
            b=b-1;
            c=0;
        }
        else if (c==a-1 && bud[b-1][0]!=0)
        {
            bud[b+1][c]=++d;
            b=b+1;
            c=c;
        }
        else if (b==0 && bud[a-1][c+1]==0)
        {
            bud[a-1][c+1]=++d;
            b=a-1;
            c=c+1;
        }
        else if (b==0 && bud[a-1][c+1]!=0)
        {
            bud[b+1][c]=++d;
            b=b+1;
            c=c;
        }
    }
    for (b=0; b<a; b++)
    {
        for (c=0; c<a; c++)
        {
            printf("%3d",bud[b][c]);
        }
        puts("");
    }
    f=a*((a*a)+1)/2;
    printf("\n The sum is %d",f);
    return 0;
}