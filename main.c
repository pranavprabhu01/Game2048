//Description:A simple implementation of 2048 game in C language.
//Author:Pranav Prabhu
//Version:1.0
//Date of first release:19 December 2019
#include <stdio.h>
#include <stdlib.h>
#include "2048.h"



int main()
{


   char choice;

    printf("Enter the size of board(3,4 or 5):");
    choice = getchar();
    switch (choice){
        case 51:
            tiles = 3;
            break;
        case 52:
            tiles = 4;
            break;
        case 53:
            tiles = 5;
            break;
        }
    printf("\n No of bytes needed: %d\n", tiles*sizeof(int));
    //tiles = 3;

    setadd();
    allocate();
    //display();
    srand((unsigned)time(&t));

    row=rand()%tiles;
    col=rand()%tiles;

   initialize();

   gennxt();

   display();

   for(;;)
   {
    printf("---Press (lower case)u-to move  up,d-to move down,l-to move left,r-to move right");
    choice=getchar();

    switch(choice)
    {
     case 'u':
        swipeup();
        gennxt();
        display();
        break;

     case 'd':
        swipedwn();
        gennxt();
        display();
        break;

     case 'l':
        swipeleft();
        gennxt();
        display();
        break;

     case 'r':
        swiperight();
        gennxt();
        display();
        break;



   }
   check();

   }


}
