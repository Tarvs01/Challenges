//This program checks a given range for the largest distance between two consecutive primes.
//You input the outer boundary so  it checks between 2 and that boundary.
//It uses the sieve of Erathothenes to find the primes.

#include <stdio.h>

int main()
{
    printf("Enter the range you want to check\n");
    unsigned int n;
    scanf("%d",&n);
    unsigned int a[n];
    unsigned int b,c;
    
    for (b=0; b<n; b++)
    {
        a[b]=1;
    }
    
    for (b=2; b<n; b++) 
    {
        for (c=b+1; c<n; c++)
        {
            if (c%b==0) 
            {
                a[c]=0; 
            }
        }
    }
    unsigned int count=2,d=0,e=0,f=0;
    for (b=2; b<n; b++)
    {
        if (a[b]==1) 
        {
    if ((b-count)>e)
    {
        e=b-count;
        d=b;
        f=count;
    }
            count=b; 
        }
    }
  printf("The greatest distance between primes in range 2-%u is\n",n);
  printf("%u and is between %u and %u",e,d,f);
}