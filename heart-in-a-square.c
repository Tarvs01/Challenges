/*If love, how much?* 

The actual question starts here=>
Prepare your cardioids for next 14th February: The formula of love? Linear algebra!
Post Valentine codes using a mathematical function or geometrical shapes to calculate the maximal area of a heart fitting in a square of side 5cm or 300 px. Or display it, because We ❤️maths
and stops here<=

* Anthony and Cleopatra, Shakespeare. Challenge proposed with SR‎ , thanks to Minho 🇰🇷 Elizabeth Kelly , Frogged for advice.*/

#include <stdio.h>
#include <math.h>

#define pi 3.142857

int main() 
{
    int a = 5;
    a*=a;
    printf("The length of the square is 5cm\n");
    printf("So the area is 25cm²\n");
    printf("\n\nThe heart can be divided into three parts, two semi circles and a smaller square\n");
    printf("\nThe side of the square equals the diameter of the semicircles\n");
    printf("\nWe will start iterating from a length of 0.5cm until we find the largest possible value to a precision of 0.0001\n");
    printf("\n Our iteration will take the area of the heart into account, its height and its base length\n");
    float b =0.5,sq=0,c=0.0,height=0.0,base=0.0,h,ba;
    while (sq<a && height<5 && base<5)
    {
        c=sq;
        h=height;
        ba=base;
        sq = (b*b)+(pi*(b/2.0)*(b/2.0));
        height = ((3.0/4.0)*sqrt(2)+0.5)*b;
        base = ((sqrt(2)/2.0)+1)*b;
        b+=0.0001;
    }
    printf("\nThe largest heart that can fit inside a square of length 5cm has an area of %.5fcm²\n",c);
    printf("\nThe height of that heart is %.5f\n",h);
    printf("\nThe base length/width of that heart is %.5f\n",ba);
    printf("\nThe diameter of the semicircles and the length of the smaller square is %.5f",b-0.0001);
    return 0;
}