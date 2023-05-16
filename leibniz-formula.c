//This calculates PI using leibniz's formula
//input is the number of terms you want to use
//Using a higher input will give better accuracy. So use inputs like 10000, 100000, 1000000, 10000000 and the like for higher accuracy

#include <stdio.h>

int main() 
{
    double a = 1.0, b = 1.0,d = 0;
    int c;
    scanf("%d",&c);
    while(c>0)
    {
        d += (a/b);
        a *= -1;
        b += 2;
        c--;
    }
    
    printf("%lf",d*4);
    return 0;
}