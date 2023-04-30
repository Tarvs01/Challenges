//This program SEARCHES for all occurence of palindromes in a string.
//A palindrome is a string or number that is read the same backwards.

//sample input- "abba"
//output - "abba"," bb"

//This method uses a fixed element to search for all palindromes with that element
//if you input "abba", it takes the last "a" as the first fixed point and searches "ba" then "bba" then "abba"
//It then takes "b" as the next fixed point and searches "bb" then "abb"
//it then takes the other "b" as the next fixed point and searches "ab"

//To see another method, check out my other code "palindromes in a string 1"

#include <stdio.h>
#include <string.h>

int check(char *,int,int);
int x=0;

int main()
{
    char ab[100];
    int a;
    fgets(ab,sizeof(ab),stdin);
    //scanf("%s",ab);
    printf("Your input is %s\n",ab);
    a=strlen(ab);
    a--;
    while (a>1)
    {
        check(ab,a,a-1);
        ab[a]='\0'; //This line is useless
        a--;
    }
    if (x==0)
    {
        printf("No palindrome was found\n");
    }
    else
    {
        printf("%d palindrome(s) was(were) found\n",x);
    }
    return 0;
}

int check(char *a, int b, int c)
{
    if (c<0)
    {
        return 0;
    }
    else
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
        check(a,b,c-1);
    }
    return 0;
}