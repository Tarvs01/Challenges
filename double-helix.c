//This is a solution to the double helix challenge
//The input is a string of no more than 20 characters. If you input more than 20 characters, it only uses the first 20.
//The output is a helix of the string done as many times as the characters in the string.
//If you input cat, the output will be
//   c   c
//     a
//   t   t
//   c   c
//     a
//   t   t
//   c   c
//     a
//   t   t
//This is a console/ASCII art challenge

#include <stdio.h>
#include <string.h>

int main() 
{
    char word[100];
    int a,b,c,d;
    scanf("%20s",word);
    a=strlen(word);
    for (d=0; d<a; d++)
    {
        for (c=0; c<a; c++)
        {
            for (b=0; b<a; b++)
            {
                if (b==c || b==(a-c-1))
                {
                    printf("%c ",word[c]);
                }
                else
                {
                    printf("  ");
                }
            }
            puts("");
        }
    }
    return 0;
}