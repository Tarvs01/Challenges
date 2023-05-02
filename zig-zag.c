//This is a solution to the zig-zag challenge.
//With the user input n, create an n*n square with numbers from 0-(n*n)-1 filling it in a zig-zag pattern. For example
//user input = 3
//output = 0 1 5
//         2 4 6
//         3 7 8

//For this code, the input has to be between 1-10 to create an appealing output. it gets congested for inputs above 10. Or you can change the formatting string I used to accomodate larger values.

#include <stdio.h>
int zig(int a, int arr[a][a],int b);
int x = 0;
int y = 1;
int z = 0;

int main() 
{
    int a,b=0;
    scanf("%d",&a);
    if (a<1 || a>10)
    {
        printf("Enter a number in the range 1-10");
        return 0;
    }
    printf("Your input is %d\n",a);
    int ar[a][a];
    ar[0][0]=0;
    while (b<(a*a-1))
    {
        b = zig(a,ar,b);
    }
    int c,d;
    for (c=0; c<a; c++)
    {
        for (d=0; d<a; d++)
        {
            printf("%3d",ar[c][d]);
        }
        puts("");
    }
    return 0;
}

int zig(int a, int arr[a][a],int b)
{
    if (z==0)
    {
        if (y<a-1)
        {
            while (y>=0)
            {
                arr[x++][y--]=++b;
            }
            y++;
            z=1;
            return b;
        }
        else
        {
            while (x<=a-1)
            {
                arr[x++][y--]=++b;
            }
            x--;
            y+=2;
            z=1;
            return b;
        }
    }
    else
    {
        if (x<a-1)
        {
            while (x>=0)
            {
                arr[x--][y++]=++b;
            }
            x++;
            z=0;
            return b;
        }
        else
        {
            while (y<=a-1)
            {
                arr[x--][y++]=++b;
            }
            y--;
            x+=2;
            z=0;
            return b;
        }
    }
}