/*[Challenge] Create your own piece of code of the Karaca Encryption Algorithm (any programming language can be used)

This encryption algorithm is an easy common challenge. 

Given the string "mango", the string is encrypted as the following: -

Step 1 : - The word "mango" is reversed into "ognam"

Step 2:-  All the vowels are replaced using the following base: a = 0 , e = 1 ,  i = 2 , o = 3 , u = 4 which gives us "3gn0m".

Step 3:- Add "aca" at the end of the word - "3gn0maca"

Example Input:- "I love C#"
Example Output:- "#C 1v3l 2aca"*/

#include <stdio.h>
#include <string.h>

int main() 
{
    char ar[100];
    char temp;
    fgets(ar,sizeof(ar),stdin);
    int a = strlen(ar);
    int b;
    
    //reverses the string
    for (b=0; b<a/2; b++)
    {
        temp = ar[b];
        ar[b] = ar[a-b-1];
        ar[a-b-1] = temp;
    }
    
    //switches the vowels
    for (b=0; b<a; b++)
    {
        switch (ar[b])
        {
            case 'a':
            case 'A':
                ar[b]='0';
                break;
            case 'e':
            case 'E':
                ar[b]='1';
                break;
            case 'i':
            case 'I':
                ar[b]='2';
                break;
            case 'o':
            case 'O':
                ar[b]='3';
                break;
            case 'u':
            case 'U':
                ar[b]='4';
                break;
            default:
                continue;
        }
    }
    
    //adds "aca"
    strcat(ar,"aca");
    ar[a+3]='\0';
    printf("%s",ar);
    return 0;
}