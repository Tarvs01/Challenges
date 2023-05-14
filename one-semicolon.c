/*
[Java Challenge ♨️]

Write a method which will take a positive integer n as input from user and will print the following pattern using one or no semi-colon!

Ex : Given, n = 5
The pattern should look like this.

1
12
123
1234
12345

[ p.s. C, C++ and C# are welcome too! ]*/

//My solution uses one semicolon.

#include <stdio.h>
void fun(int a, int b , int c)
{
    if (scanf("%d",&a))
    {
        while (++b<=a && printf("\n") && (c=1))
        {
            while (c<=b && printf("%d",c++))
            {
                
            }
        }
    }
}

int main() 
{
    fun(0,0,0);
}