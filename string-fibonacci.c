/*#Challenge
Level: Baby Scratch Coder

Make this sequence
( Fibonacci Word )
0,01,010,01001,01001010,  ...*/

#include <stdio.h>
#include <string.h>

int main() 
{
    char a[1000] = "0";
    char b[1000] = "01";
    char wa[1000];
    char *temp;
    int c=0;
    printf("%s\n\n%s\n\n",a,b);
    while(c++<14)
    {
        strcpy(wa,b);
        temp = strcat(b,a);
        strcpy(a,wa);
        strcpy(b,temp);
        puts(temp);
        puts("\n");
    }
    return 0;
}