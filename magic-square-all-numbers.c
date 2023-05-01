//This code prints out the trivial magic square for the given input. Input is in the range 1-10
//A trivial magic square is an n*n square containing numbers from 1-n*n such that each number appears only once and the sum of each row,column and the two main diagonals are the same

//This program is capable of printing out the magic squares for numbers greater than 10. But that feature is appealing to people on PC and tablet. if you are on mobile, limit your input to the range 1-10. If you are on PC and you want to input a value greater than 10, change the formatting in function print to a larger number like 4 or 5.

//Check out my other code "Magic square- odd numbers" for a clearer look at generating odd numbered magic squares.

#include <stdio.h>
#include <math.h> //useless
#include <ctype.h> //also useless

void odd(int); //for solving odd numbers
void single(int); //solving multiples of 2
void ddouble(int); //solving multiples of 4
void print(int n, int ae[n][n]);
void cach(int n, int bud[n][n], int i, int j, int k, int l, int m, int o);

int main()
{
    int a;

    scanf("%d",&a);
    printf("You entered %d\n",a);
    if (a<1)
    {
        printf("Enter an integer greater than 0. Try again\n");
    }
    else if (a==2)
    {
        printf("There is no magic square for number 2\n");
    }
    else if (a%2!=0)
    {
        printf("The magic square for %d is\n",a);
        odd(a);
        printf("\nThe magic sum is %d",a*((a*a)+1)/2);
    }
    else if (a%4==0)
    {
        printf("The magic square for %d is\n",a);
        ddouble(a);
        printf("\nThe magic sum is %d",a*((a*a)+1)/2);
    }
    else
    {
        printf("The magic square for %d is\n",a);
        single(a);
        printf("\nThe magic sum is %d",a*((a*a)+1)/2);
    }

    return 0;
}

void ddouble(int n)
{
    int a,x,y;
    a=n/4;
    int ar[n][n];
    for (x=0; x<n; x++)
    {
        for (y=0; y<n; y++)
        {
            ar[x][y]=0;
        }
    }
    for (x=0; x<n; x++)
    {
        for (y=0; y<n; y++)
        {
            if ((x<a && y<a) || (x>=n-a && y>=n-a) || (x<a && y>=n-a) || (x>=n-a && y<a) || (x>=a && x<n-a && y>=a && y<n-a))
            {
                ar[x][y]=1;
            }
        }
    }
    a=1;
    for (x=0; x<n; x++)
    {
        for (y=0; y<n; y++)
        {
            if (ar[x][y]==1)
            {
                ar[x][y]=a;
                a++;
            }
            else
            {
                a++;
            }
        }
    }
    a=n*n;
    for (x=0; x<n; x++)
    {
        for (y=0; y<n; y++)
        {
            if (ar[x][y]==0)
            {
                ar[x][y]=a;
                a--;
            }
            else
            {
                a--;
            }
        }
    }
    for (x=0; x<n; x++)
    {
        for (y=0; y<n; y++)
        {
            printf("%-4d",ar[x][y]);
        }
        puts("");
    }
}

void print(int n, int ae[n][n])
{
    int a,b;
    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)
        {
            printf("%3d",ae[a][b]);
        }
        puts("");
    }
}

void single(int n)
{
    int ar[n][n];
    int av[n][n];
    int i,j,d,e,t,a,b,c,temp=0;
    a=((n+2)/4)-1;
    b=a-1;
    c=n/4;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            ar[i][j]=0;
            av[i][j]=0;
        }
    }
    d=n*n;//36
    d=d/4;//9
    e=n/2;//3
    t=d;//9
    cach(n,ar,0,e-1,0,e-1,0,d);
    cach(n,ar,e,n-1,e,n-1,t,t+d);
    t=t+d;
    cach(n,ar,0,e-1,e,n-1,t,t+d);
    t=t+d;
    cach(n,ar,e,n-1,0,e-1,t,t+d);
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if ((i<a && j<a) || (i==c && j>0 && j<=c) || (i>c && i<=c*2 && j<a) || (i<=c*2 && j>=n-b))
            {
                av[i][j]=1;
            }
        }
    }
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (av[i][j]==1)
            {
                temp=ar[i][j];
                ar[i][j]=ar[i+e][j];
                ar[i+e][j]=temp;
            }
        }
    }
    print(n,ar);
}

void cach(int n, int bud[n][n], int i, int j, int k, int l, int m, int o)
{
    int b,c;
    b=i;
    c=(l+k)/2;
    bud[b][c]=++m;
    while (m<o)
    {
        if (b>i && c<l && bud[b-1][c+1]==0)
        {
            bud[b-1][c+1]=++m;
            b=b-1;
            c=c+1;
        }
        else if (b>i && c<l && bud[b-1][c+1]!=0)
        {
            bud[b+1][c]=++m;
            b=b+1;
            c=c;    
        }
        else if (b==i && c==l && bud[j][k]==0)
        {
            bud[j][k]=++m;
            b=j;
            c=k;
        }
        else if (b==i && c==l && bud[j][k]!=0)
        {
            bud[b+1][c]=++m;
            b=b+1;
            c=c;
        }
        else if (c==l && bud[b-1][k]==0)
        {
            bud[b-1][k]=++m;
            b=b-1;
            c=k;
        }
        else if (c==l && bud[b-1][k]!=0)
        {
            bud[b+1][c]=++m;
            b=b+1;
            c=c;
        }
        else if (b==i && bud[j][c+1]==0)
        {
            bud[j][c+1]=++m;
            b=j;
            c=c+1;
        }
        else if (b==i && bud[j][c+1]!=0)
        {
            bud[b+1][c]=++m;
            b=b+1;
            c=c;
        }
        else
        {
            
        }
    }
}

void odd(int n)
{
    int b,c,m=0;
    int bud[n][n];
    for (b=0; b<n; b++)
    {
        for (c=0; c<n; c++)
        {
            bud[b][c]=0;
        }
    }
    b=0;
    c=n/2;
    bud[b][c]=++m;
    while (m<n*n)
    {
        if (b>0 && c<n-1 && bud[b-1][c+1]==0)
        {
            bud[b-1][c+1]=++m;
            b=b-1;
            c=c+1;
        }
        else if (b>0 && c<n-1 && bud[b-1][c+1]!=0)
        {
            bud[b+1][c]=++m;
            b=b+1;
            c=c;    
        }
        else if (b==0 && c==n-1 && bud[n-1][0]==0)
        {
            bud[n-1][0]=++m;
            b=n-1;
            c=0;
        }
        else if (b==0 && c==n-1 && bud[n-1][0]!=0)
        {
            bud[b+1][c]=++m;
            b=b+1;
            c=c;
        }
        else if (c==n-1 && bud[b-1][0]==0)
        {
            bud[b-1][0]=++m;
            b=b-1;
            c=0;
        }
        else if (c==n-1 && bud[b-1][0]!=0)
        {
            bud[b+1][c]=++m;
            b=b+1;
            c=c;
        }
        else if (b==0 && bud[n-1][c+1]==0)
        {
            bud[n-1][c+1]=++m;
            b=n-1;
            c=c+1;
        }
        else if (b==0 && bud[n-1][c+1]!=0)
        {
            bud[b+1][c]=++m;
            b=b+1;
            c=c;
        }
        else
        {
            
        }
    }
    print(n,bud);
}
