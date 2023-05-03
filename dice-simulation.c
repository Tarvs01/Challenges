/*[Challenge]
Player A and Player B have different dice. They play the following game: Both roll their dice at the same time and whoever has the higher number gets one point. Who is likely to win after 100 rounds? Create a simulation to verify your guess.*/

//For the dice, player A has 4 indents on four faces and nothing on two faces
//Player B has 2 indents on four faces and 6 indents on 2 faces

//Due to the orientation of the dice, a simple probability calculation will show that player B has a higher chance of winning.
//This program just confirms that.

//The input is the number of rounds you want to play *100. so if you enter 2, there will be 200 rounds.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play(int *, int *);

int main() 
{
    srand(time(NULL));
    int a,b,c,d,f=0,g=0;
    scanf("%d",&a);
    printf("This game will play %d time(s). Each game has 100 rounds\n\n",a);
    for (b=1; b<=a; b++)
    {
        c=d=0;
        play(&c,&d);
        printf("For game %d\n",b);
        printf("Player A won %d times\n",c);
        printf("Player B won %d times\n",d);
        f+=c;
        g+=d;
        puts("\n");
    }
    printf("Overall, out of the total %d rounds played\n",a*100);
    printf("Player A won %d times\n",f);
    printf("Player B won %d times\n",g);
    printf("So player ");
    if (f>g)
    {
        printf("A");
    }
    else
    {
        printf("B");
    }
    printf(" Has a higher chance of winning");
    return 0;
}

void play(int *a, int *b)
{
    int e,c,d;
    int ab[6]={0,0,4,4,4,4};
    int ac[6]={2,2,2,2,6,6};
    for (d=0; d<100; d++)
    {
        e = rand()%6;
        c = rand()%6;
        if (ab[e]>ac[c])
        {
            (*a)++;
        }
        else if (ac[c]>ab[e])
        {
            (*b)++;
        }
    }
}