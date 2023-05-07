//Please for input, either read what I wrote or click the link below
//https://codegolf.stackexchange.com/questions/38305/draw-ascii-playing-cards

//for input, enter the cards you want to print seperated with space. For example
//to print jack of spades and 6 of hearts you will enter=> js 6h. so the input is the number or first letter of the face followed by the first letter of the suit.

//Enter b to print the back of the card or r to print the joker. please feel free to enter wrong cards. I want to test my check function well

//If you want to run the code on a compiler like Dev C++ or C++ droid, uncomment line 27. if you don't uncomment it, you will have to add a space at the end of your input for it to work. similar to sololearn. if you don't comment it in SL, you will have to add a space at the end of your input for it to work.

//This is an ASCII/console art challenge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int card(char *); //To print the card
int check(char *); //To check whether the card is valid
char suits[4][10]={"Hearts","Spades","Diamonds","Clubs"}; //To print out the suits
char face[4][10] = {"♥","♠","♦","♣"};

int main()
{
    char in[100];
    fgets(in, sizeof(in), stdin); 
    //in[strlen(in)-1]='\0'; //This line enables the program to work properly on compilers like Dev c++. unnecessary for sololearn
    
    printf("You entered %s\n\n",in);
    
    //Convert the input to small letters
    int a;
    for (a=0; a<strlen(in); a++)
    {
        if (in[a]>=65 && in[a]<=90)
        {
            in[a] = in[a]+32;
        }
    }
    
    //This splits the input into srings seperated with a space. I miss Ruby's split(' ')
    char *curd = strtok(in," ");
    
    while (curd != NULL)
    {
        card(curd);
        curd = strtok(NULL," ");
    }
    return 0;
}

int card(char *p)
{
    //This prints out the back of the card.
    if ((!strcmp(p,"b")) || (!strcmp(p,"B")))
    {
        puts("Back of the card");
        int a,b;
        for (a=0; a<15; a++)
        {
            printf("_");
        }
        puts("");
        for (a=0; a<13; a++)
        {
            printf("|");
            for (b=0; b<13; b++)
            {
                printf("*");
            }
            printf("|");
            puts("");
        }
        for (a=0; a<15; a++)
        {
            printf("-");
        }
        puts("\n");
    }
    //This prints out the Joker card. Take note of the format, that's how the others are
    else if ((!strcmp(p,"r")) || (!strcmp(p,"R")))
    {
        int a,b;
        puts("\nJoker");
        for (a=0; a<15; a++)
        {
            printf("_"); //prints the upper boundary
        }
        puts("");
        for (a=0; a<13; a++)
        {
            printf("|"); //prints newline left boundary
            //Prints the rest of the card
            for (b=0; b<13; b++)
            {
                if((a==0 && b==0) || (a==3 && b==4) || (a==8 && b==12))
                {
                    printf("J");
                }
                else if ((a==1 && b==0) || (a==4 && b==5) || (a==9 && b==12))
                {
                    printf("O");
                }
                else if ((a==2 && b==0) || (a==5 && b==6) || (a==10 && b==12))
                {
                    printf("K");
                }
                else if ((a==3 && b==0) || (a==6 && b==7) || (a==11 && b==12))
                {
                    printf("E");
                }
                else if ((a==4 && b==0) || (a==7 && b==8) || (a==12 && b==12))
                {
                    printf("R");
                }
                else if ((b==2 || b==10) && a>1 && a<11)
                {
                    printf("|");
                }
                else if ((a==1 || a==10) && b>1 && b<10)
                {
                    printf("_");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("|"); //prints end of line boundary
            puts("");
        }
        for (a=0; a<15; a++)
        {
            printf("_"); //prints lower boundary
        }
        puts("\n");
    }
    
    //This is for cards that are neither Joker nor Back
    else
    {;
        char c[4];
        int g,a,b;
        if ((strlen(p)<2) || (strlen(p)>3))
        {
            printf("\n%s is an invalid card\n\n",p); //First check for invalid cards
            return 0;
        }
        
        strcpy(c,p);
        c[strlen(c)-1]='\0'; //c contains the face
        
        //This checks for the suit for printing
        char ar[5] = {'h','s','d','c','\0'};
        int e;
        for (g=0; g<5; g++)
        {
            if (p[strlen(p)-1] == ar[g])
            {
                e=g;
            }
        }
        
        if (check(p)) //if the card is valid,print it with the given parameters
        {
            if (!strcmp(c,"a"))
            {
                printf("Ace of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("A");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || (a==5 && b==6))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            else if (!strcmp(c,"2"))
            {
                printf("2 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("2");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || ((a==3 || a==9) && b==6))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            else if (!strcmp(c,"3"))
            {
                printf("3 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("3");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || ((a==3 || a==9 || a==6) && b==6))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"4"))
            {
                printf("4 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("4");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || ((a==3 || a==9) && (b==4 || b==8)))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"5"))
            {
                printf("5 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("5");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || ((a==4 || a==8) && (b==4 || b==8)) || (a==6 && b==6))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"6"))
            {
                printf("6 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("6");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || ((a==3 || a==6 || a==9) && (b==4 || b==8)))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"7"))
            {
                printf("7 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("7");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || ((a==3 || a==6 || a==9) && (b==4 || b==8)) || (a==6 && b==6))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"8"))
            {
                printf("8 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("8");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || ((a==3 || a==5 || a==7 || a==9) && (b==4 || b==8)))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"9"))
            {
                printf("9 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12))
                        {
                            printf("9");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || ((a==3 || a==5 || a==7 || a==9) && (b==4 || b==8)) || (a==6 && b==6))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"10"))
            {
                printf("10 of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==11))
                        {
                            printf("1");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==12))
                        {
                            printf("0");
                        }
                        else if ((a==0 && b==2) || (a==12 && b==10) || ((a==3 || a==5 || a==7 || a==9) && (b==3 || b==9)) || ((a==4 || a==8) && (b==6)))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"j"))
            {
                printf("Jack of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12) || (a==5 && b==6))
                        {
                            printf("J");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || (a==3 && b==3) || (a==9 && b==9))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"q"))
            {
                printf("Queen of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12) || (a==5 && b==6))
                        {
                            printf("Q");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || (a==3 && b==3) || (a==9 && b==9))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }
            if (!strcmp(c,"k"))
            {
                printf("King of %s\n",suits[e]);
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("");
                for (a=0; a<13; a++)
                {
                    printf("|");
                    for (b=0; b<13; b++)
                    {
                        if ((a==0 && b==0) || (a==12 && b==12) || (a==5 && b==6))
                        {
                            printf("K");
                        }
                        else if ((a==0 && b==1) || (a==12 && b==11) || (a==3 && b==3) || (a==9 && b==9))
                        {
                            printf("%s",face[e]);
                        }
                        else if ((b==10 || b==2) && a>1 && a<11)
                        {
                            printf("|");
                        }
                        else if ((a==1 || a==10) && b>1 && b<10)
                        {
                            printf("_");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("|");
                    puts("");
                }
                for (a=0; a<15; a++)
                {
                    printf("_");
                }
                puts("\n");
            }    
        }
        else
        {
            printf("%s is an invalid card\n\n",p);
        }
    }
    return 0;
}

int check(char *p)
{
    char ar[5] = {'h','d','s','c','\0'}; //This contains the suits
    char ae[5] = {'a','k','q','j','\0'}; //This contain the non-numerical faces
    int count = 0,g;
    
    //This checks that the face is valid
    if (isalpha(p[0]))
    {
        for (g=0; g<5; g++)
        {
            if (p[0]==ae[g])
            {
                count=1;
            }
        }
    }
    else
    {
        count=2;
    }
    if (count==0)
    {
        return 0;
    }
    count = 0;
    
    //This checks that the suit is valid
    if (isalpha(p[strlen(p)-1]))
    {
        for (g=0; g<5; g++)
        {
            if (p[strlen(p)-1] == ar[g])
            {
                count=1;
            }
        }
    }
    else
    {
        return 0;
    }
    if (count==0)
    {
        return 0;
    }
    
    //This checks that no number greater than 10 is valid
    if (isdigit(p[0]) && strlen(p)>2 && p[1]!='0')
    {
        return 0;
    }
    
    //This checks that 1 is an invalid card. It is ace and not 1
    if (p[0]=='1' && strlen(p)==2)
    {
        printf("It is Ace and not 1\n");
        return 0;
    }
    
    return 1;
}


//There are supposed to be diagrams but they did not copy well so I erased them. click on the link at the top of the code

/*Consider these 15 ASCII playing card patterns (ace through Joker, and the back side), where X is a placeholder for the suit symbol: (they look better with less line spacing)

 Write a program that takes in a string denoting a space separated sequence of cards using...

A 2 3 4 5 6 7 8 9 10 J Q K followed by one of C D H S (for clubs, diamonds, hearts, and spades) for the 52 standard cards.
A single R for a Joker.
A single B for the back side (a face down card).
So the string B AS KH 10C R JD denotes a face down card, followed by an ace of spades, followed by a king of hearts, followed by a ten of clubs, followed by a Joker, followed by a jack of diamonds.

Your program needs to print the corresponding ASCII playing cards to stdout, replacing X with the appropriate suit symbol.

For example, the output for B AS KH 10C R JD would be

 
You can take the input from stdin or write a function that takes a string.

The submission with the shortest number of characters wins.

Bonus: Subtract 30 from your character count if you use the black Unicode suit symbols ♣ ♦ ♥ ♠ instead of C D H S in your output. (The input always uses C D H S.)

Notes
There may be more than 54 cards in the input string and there may be duplicates of any card.
There should be no output if the input is the empty string.
There should be no trailing spaces besides (optionally) the two that make up the right corners of the last card.
You may assume the input is valid.
Update: The lower right label on standard cards has been reversed so the value is in the corner. The lower right Joker label hasn't changed.*/
