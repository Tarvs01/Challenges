//This code SEARCHES a string for all occurence of palindromes in it
//A palindrome is a string or number that is the same when written backwards.

//sample input = abba
//output = bb,abba
//That is because "abba" and "bb" are the only palindromes that can be found in "abba"

//This method uses specific combination. if the length of the string is 4, then it uses a combination of 2-4.
//so for 2, it checks every two consecutive elements to see if they are a palindrome. so in "abba", it checks "ab"," bb" then "ba"
//and for 3, it checks "abb" and "bba".

//To see another method, Check out my other code " Palindromes in a string 2"

#include <stdio.h>
#include <string.h>

void cheque(char *,int,int);
int x=0;

int main()
{
    char ar[100];
    int a,b,c;
    fgets(ar,sizeof(ar),stdin);
    //scanf("%s",ar);
  printf("Your input is %s\n",ar);
    a=strlen(ar);
    for (b=1; b<a; b++)
    {
        for (c=0; c<a && b+c<a; c++)
        {
            cheque(ar,c+b,c);
        }
    }
    if (x==0)
    {
        printf("No palindrome was found\n");
    }
    else
    {
        printf("%d palindrome(s) was(were) found\n",x);
    }
}

void cheque(char *a, int b, int c)
{
    int flag=0;
    int d;

    for (d=0; d<b && c+d<=b-d; d++)
    {
        if (a[c+d]!=a[b-d])
        {
            flag=1;
        }
    }
    if (flag==0)
    {
        for (d=c; d<=b; d++)
        {
            printf("%c",a[d]);
        }
        puts("");
        x++;
     }
}
