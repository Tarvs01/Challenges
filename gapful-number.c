//A gapful number is one which is perfectly divisible by its first and last digits concantenated into an integer.
//And the number must 3 digits or more

//sample input = 100
// 100 is gapful because 100/10 = 10

//sample input = 546
//546 is not gapful because 546/56 =9.75 which is not a perfect division

//This challenge only checks if the input number is a gapful number. It does not generate gapful numbers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char a[10],b[3];
    scanf("%s",a);
    int c,d,e;
    c=strlen(a);
    if (c<3)
    {
        printf("Number entered is less than 3 digits. Try again");
        return 0;
    }
    b[0]=a[0];
    b[1]=a[c-1];
    b[2]='\0';
    d=atoi(a);
    e=atoi(b);
    if (d%e==0)
    {
        printf("%d is a gapful number\n",d);
        printf("%d/%d = %d",d,e,d/e);
    }
    else
    {
        printf("%d is not a gapful number\n",d);
        printf("%d/%d = %.4f",d,e,(float)d/e);
    }
    return 0;
}