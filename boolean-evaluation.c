/*Challenge #2

Evaluate a boolean expression represented as string
Given a string consisting of only 0, 1, A, B, C where
A = AND
B = OR
C = XOR

Calculate the value of the string assuming no order of precedence and evaluation is done from left to right.

Constraints – The length of string will be odd. It will always be a valid string.

Example, 1AA0 will not be given as an input.
Example input = 1a0b1
        output = 1
        because 1a0b1 = 1 and 0 or 1 
        which equals 1*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char ar[50];
    scanf("%s",ar);
    char ab[] = "10ABCabc";
    printf("Your input is %s\n",ar);
    int x,y,flag=0,flug=0,fleg=0,c=0;
    for (x=0; x<strlen(ar); x++)
    {
        c=0;
        for (y=0; y<strlen(ab); y++)
        {
            if (ar[x]==ab[y])
            {
                c++;
            }
        }
        if (c==0)
        {
            flag=1;
        }
    }
    for (x=0; x<strlen(ar)-1; x++)
    {
        if ((isalpha(ar[x]) && isalpha(ar[x+1])) || (isdigit(ar[x]) && isdigit(ar[x+1])))
        {
            flug=1;
        }
    }
    if (isalpha(ar[0]) || isalpha(ar[strlen(ar)-1]))
    {
        fleg=1;
    }
    
    //checks if input contains even number of characters
    if (strlen(ar)%2==0)
    {
        printf("Invalid input. Logic error");
    }
    
    //checks if input is less than 2
    else if (strlen(ar)<2)
    {
        printf("Invalid input. Input too short");
    }
    
    //checks if characters are correct
    else if (flag==1)
    {
        printf("Invalid input. Wrong character in input");
    }
    
    //checks if input dosen't contain consecutive numbers or operators
    else if (flug==1)
    {
        printf("Invalid input. Input should be alternating number and operator");
    }
    
    //checks if input starts and end with a number
    else if (fleg==1)
    {
        printf("Invalid input. Input should start with 0 or 1 and end with 0 or 1");
    }
    
    //if it fulfils all conditions
    else
    {
        int a,b,d=1,e=2;
        a = ar[0] - '0';//first number
        b = ar[e] - '0';//second number
        while (ar[d]!='\0')//checks for null
        {
            switch (toupper(ar[d]))//uppercase letter
            {
                case 'A':
                    a = a && b; //and gate
                    break;
                case 'B':
                    a = a || b; //or gate
                    break;
                case 'C':
                    if (a == b)
                    {
                        a = 0;//XOR same value
                    }
                    else
                    {
                        a = 1;//XOR different value
                    }
                    break;
                default:
                    continue;
            }
            d+=2;//next logic gate
            e+=2;//next number
            b = ar[e] - '0';//next number to int
        }
        printf("your result is %d",a);
    }
    return 0;
}