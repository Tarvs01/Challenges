//The challenge is to print a diamond shape in the given pattern based on an input number
//Please enter an integer between 1 and 10.
//Entering a value outside this range defaults the value to 9
//This is an ASCII/console art challenge


/*sample input 10
output=
                   1                    
                  2 2                   
                 3   3                  
                4     4                 
               5       5                
              6         6               
             7           7              
            8             8             
           9               9            
          0                 0           
         9 9               9 9          
        8   8             8   8         
       7     7           7     7          
      6       6         6       6       
     5         5       5         5      
    4           4     4           4     
   3             3   3             3    
  2               2 2               2   
 1                 1                 1  
  2               2 2               2   
   3             3   3             3    
    4           4     4           4     
     5         5       5         5      
      6       6         6       6       
       7     7           7     7        
        8   8             8   8         
         9 9               9 9          
          0                 0           
           9               9            
            8             8             
             7           7              
              6         6               
               5       5                
                4     4                 
                 3   3                  
                  2 2                   
                   1                    

*/

#include <stdio.h>
#include <math.h>

int main() 
{
    int a,b,n,m,x,c;
    scanf("%d",&c);
    if (c>10 || c<1)
    {
        c=9;
    }
    n=c-1;
    m=n*2;
    x=4*n;
    for (a=0; a<=x; a++)
    {
        for (b=0; b<=x; b++)
        {
            if (((b-a)==m) || ((a-b)==m) || (b+a==m) || (b+a==m+x) || (a>=n && a<=(x-n) && a==b) || (a>=n && a<=(x-n) && a+b==x))
            {
                if ((a<(m/2)) || (a>=m && a<(m+(m/2))))
                {
                    printf("%d",a%m+1);
                }
                else if (a==(m/2) || a==(m+(m/2)))
                {
                    printf("0");
                }
                else if ((a>m+(m/2) && a<x))
                {
                    printf("%d",x-a+1);
                }
                else if (a<m && a>m-(m/2))
                {
                    printf("%d",m-a+1);
                }
                else
                {
                    printf("1");
                }
            }
            else
            {
                printf(" ");
            }
        }
        puts("");
    }
    return 0;
}