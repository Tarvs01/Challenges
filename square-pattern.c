/* 
Sample execution:
input=4
output=
* * * * * * * * *
*   *   *   *   * 
* * *   *   *   * 
*       *   *   * 
* * * * *   *   * 
*           *   * 
* * * * * * *   * 
*               * 
* * * * * * * * * 

*/
//This is a console/ASCII art challenge

#include <stdio.h>

int main() 
{
    int n,a,b;
    scanf("%d",&n);
    for (a=0; a<=(n*2); a++)
    {
        for (b=0; b<=(n*2); b++)
        {
            if ((a%2==0 && b<=a) || (b%2==0 && a<=b) || (a==0 || b==0))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        puts("");
    }
    return 0;
}