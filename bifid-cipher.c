//The question for the challenge is below the code. just scroll down.

//The input is the key then the message. so if your key is "Nigeria" and your message is "Tarvs is awesome", your input will be: Nigeria Tarvs is awesome

//Please don't use punctuation or special characters in your input. I didn't error check, so it may(will) give unexpected results.

//I know this code is unnecessarily long. But with my knowledge, this was the best way I knew how to do it. If you find areas that can be optimized, please say. Thanks.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void bifid(char *, char *); //encoding function. 

int main()
{
    char a[50],b[50];

    scanf("%s",a);
    printf("Your key is %s \n",a);
    fflush(stdin);
//clears input space from scanf to allow for fgets
    fgets(b,sizeof(b),stdin);
    printf("Your message is %s\n\n",b);
    bifid(a,b);
    return 0;
}

void bifid(char *a, char *b)
{
    int c,d,e=0,f,g=1,h=0,flag;
    char ac[50];
    strcpy(ac,b);
    char ar[26]="ABCDEFGHIKLMNOPQRSTUVWXYZ";
    char ab[26]="";
//stores our polybius
    c = strlen(a);
    
    //Adds unique elements of the key to the polybius
    for (d=0; d<c; d++)
    {
        flag=0;
        if (a[d]=='j' || a[d]=='J')
        {
            a[d]='I'; //swaps J to I
        }
        else if (a[d]==' ')
        {
            continue; //Ignores spaces
        }
        for (f=0; f<d; f++)
        {
            if ((a[d])==a[f])
            {
                flag=1;
            }
        }
        if (flag==0)
        {
            ab[e++]=toupper(a[d]);
        }
    }
    
    //adds the remaining elements to the polybius
    for (d=0; d<strlen(ar); d++)
    {
        flag=0;
        for (f=0; f<e; f++)
        {
            if (ar[d]==ab[f])
            {
                flag=1;
            }
        }
        if (flag==0)
        {
            ab[e++]=ar[d];
        }
    }
    
    //prints the polybius
    printf("Your Polybius square for your key is\n");
    printf("  1 2 3 4 5\n1 ");
    for (d=0; d<26 && ab[d]!='\0'; d++)
    {
        printf("%c ",ab[d]);
        if ((d+1)%5==0 && g<5)
        {
            puts("");
            printf("%d ",++g);
        }
    }
    
    //gets the rows and columns from the polybius
    g=strlen(b);
    int row[g],col[g];
    for (d=0; d<g; d++)
    {
        if (b[d]==' ')
        {
            continue;
        }
        else if (b[d]=='j' || b[d]=='J')
        {
            b[d]='I';
        }
        for (f=0; f<26 && ab[f]!='\0'; f++)
        {
            if (toupper(b[d])==ab[f])
            {
                if (f<5)
                {
                    row[h]=1;
                    col[h++]=f%5+1;
                }
                else if (f<10)
                {
                    row[h]=2;
                    col[h++]=f%5+1;
                }
                else if (f<15)
                {
                    row[h]=3;
                    col[h++]=f%5+1;
                }
                else if (f<20)
                {
                    row[h]=4;
                    col[h++]=f%5+1;
                }
                else
                {
                    row[h]=5;
                    col[h++]=f%5+1;
                }
            }
        }
    }
    
    //prints the rows and columns
    printf("\n\nYour message is %s\n",ac);
    printf("\nRows: ");
    for (d=0; d<h; d++)
    {
        printf("%d ",row[d]);
    }
    printf("\nCols: ");
    for (d=0; d<h; d++)
    {
        printf("%d ",col[d]);
    }
    
    //merges the rows and columns
    int bc[h*2];
    d=0;
    for (f=0; f<h; f++)
    {
        bc[d++]=row[f];
    }
    for (f=0; f<h; f++)
    {
        bc[d++]=col[f];
    }
    
    //prints the merging
    printf("\n\nAfter merging, we get:\n");
    for (d=0; d<h; d++)
    {
        printf("%d%d ",bc[d*2],bc[d*2+1]);
    }
    
    //Encodes the message with the polybius
    printf("\n\nYour encoded message is\n");
    int x,y;
    for (d=0; d<h; d++)
    {
        x=bc[d*2];
        y=bc[d*2+1];
        x--;
        y--;
        x*=5;
        printf("%c",ab[x+y]);
    }
}

/*[Challenge : Bifid Cipher]

"In classical cryptography, the bifid cipher is a cipher which combines the Polybius square with transposition, and uses fractionation to achieve diffusion. It was invented around 1901 by Felix Delastelle! " ~ Wiki

Tricky definition?
Let me try to explain ^_^


The Bifid cipher uses a 5 x 5 Polybius square.
The letters of a message are encoded via the coordinates of that letter in the square.

    1  2  3  4  5
 1  A  B  C  D  E
 2  F  G  H  I  K
 3  L  M  N  O  P
 4  Q  R  S  T  U
 5  V  W  X  Y  Z

- In the square all the letters of the alphabet except 'J' are present.
- Each letter appears only one time.
- Each 'J' in input must be changed to 'I'.
- White spaces are ignored and shall be removed from the key and from the message.

Your task is to write a function/ method encodeBifid which will take two parameters "key" and "message" and will return the encoded message.


Bonus : Decode the cipher!
Let's say we want to encode "Hello World" with the key "Sololearn"

Then the Polybius square can be written as below 👇

   1  2  3  4  5
1  S  O  L  E  A
2  R  N  B  C  D
3  F  G  H  I  K
4  M  P  Q  T  U
5  V  W  X  Y  Z 

[ Notice : The head of the square is formed by the key and all the duplicate letters, 'J' and whitespace are ignored. ]


To encode the message we need to find the coordinates of each letter in the Polybius square.

For example the first letter of our msg, "H" can be found in Row : 3 and Col : 3.

The full message "HELLOWORLD" can be written down as follows:

Msg: HELLOWORLD

Row:   3 1 1 1 1 5 1 2 1 2
Col :  3 4 3 3 2 2 2 1 3 5


The encoding takes place by merging the values of rows and columns.
Row values followed by the column values. 
And then we read them horizontally and find the corresponding letters from our Polybius square.


31  11  15  12  12  34   33   22   21  35  -->  
F     S    A    O    O    I     H     N     R    K

Output is in uppercase with no whitespace!*/