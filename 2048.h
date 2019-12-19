#include <stdio.h>
#include <stdlib.h>
#include <time.h>


time_t t;                     //Time variable used for random number generation
unsigned int **grid;         //The board of the game
int tiles;                  //size of array (tiles)
int maxadd;                //Maximum additions possible per row or column;Value is set by setadd
int add=0;                //Used by the movement function
int row,col;            //Used for random generaion

//      handler for move up
void swipeup()
{
    int r,c,j;
    for(c=0;c<tiles;c++)
    {
        for(r=0;r<tiles;r++)
        {
            for(j=0;j<tiles-r-1;j++)
            {
                if(grid[j][c]==0&&grid[j+1][c]!=0)
                {
                    grid[j][c]=grid[j+1][c];
                    grid[j+1][c]=0;
                }
            }
        }
    }

    for(c=0;c<tiles;c++)
    {    add=0;
        for(r=0;r<tiles-1;r++)
        {
            if((grid[r+1][c]==grid[r][c]&&grid[r][c]!=0)&&add!=maxadd)
            {
              grid[r][c]=grid[r+1][c]+grid[r][c];
              grid[r+1][c]=0;
              add=add+1;
            }
            else if(add==maxadd)
            {
                break;
            }
        }
    }

    for(c=0;c<tiles;c++)
    {
        for(r=0;r<tiles;r++)
        {
            for(j=0;j<tiles-r-1;j++)
            {
                if(grid[j][c]==0&&grid[j+1][c]!=0)
                {
                    grid[j][c]=grid[j+1][c];
                    grid[j+1][c]=0;
                }
            }
        }
    }

}

// handler for down move
void swipedwn()
{
    int r,c,j;

    for (c=0; c<tiles; c++){
        for(r=0; r<tiles; r++){
            for(j=0;j<tiles-r-1;j++)
            {
                if(grid[j+1][c]==0&&grid[j][c]!=0)
                {
                    grid[j+1][c]=grid[j][c];
                    grid[j][c]=0;
                }
            }
        }


    }
    for(c=0; c<tiles; c++){
            add=0;
        for(r=tiles-1; r>0; r--){
            if((grid[r][c]!=0 && grid[r][c]==grid[r-1][c])&&(add!=maxadd))
                {
                    grid[r][c]=grid[r-1][c]+grid[r][c];
                    grid[r-1][c]=0;
                    add=add+1;
                }
            else if(add==maxadd)
            {
                break;
            }

        }

    }

     for (c=0; c<tiles; c++){
        for(r=0; r<tiles; r++){
            for(j=0;j<tiles-r-1;j++)
            {
                if(grid[j+1][c]==0&&grid[j][c]!=0)
                {
                    grid[j+1][c]=grid[j][c];
                    grid[j][c]=0;
                }
            }
        }

}
}

// handler for right
void swiperight()
{
    int r,c,j;

    for(r=0;r<tiles;r++)
    {
        for(c=0;c<tiles;c++)
        {
            for(j=0;j<tiles-c-1;j++)
            {
                if(grid[r][j+1]==0 && grid[r][j]!=0)
                {
                    grid[r][j+1]=grid[r][j];
                    grid[r][j]=0;
                }
            }
        }
    }

    for(r=0;r<tiles;r++)
    {
        add=0;
        for(c=tiles-1;c>0;c--)
        {
            if((grid[r][c]==grid[r][c-1] && grid[r][c]!=0) && add!=maxadd)
            {
                grid[r][c]=grid[r][c]+grid[r][c-1];
                grid[r][c-1]=0;
                add=add+1;
            }

            else if(add==maxadd)
            {
                break;
            }
        }
    }


    for(r=0;r<tiles;r++)
    {
        for(c=0;c<tiles;c++)
        {
            for(j=0;j<tiles-c-1;j++)
            {
                if(grid[r][j+1]==0 && grid[r][j]!=0)
                {
                    grid[r][j+1]=grid[r][j];
                    grid[r][j]=0;
                }
            }
        }
    }




}

// Handler for left

void swipeleft()
{
    int r,c,j;

    for(r=0;r<tiles;r++)
    {
        for(c=0;c<tiles;c++)
        {
            for(j=0;j<tiles-c-1;j++)
            {
                if(grid[r][j]==0 && grid[r][j+1]!=0)
                {
                    grid[r][j]=grid[r][j+1];
                    grid[r][j+1]=0;
                }
            }
        }
    }

    for(r=0;r<tiles;r++)
    {
        add=0;
        for(c=0;c<tiles-1;c++)
        {
            if((grid[r][c]==grid[r][c+1] && grid[r][c]!=0) && add!=maxadd)
            {
                grid[r][c]=grid[r][c]+grid[r][c+1];
                grid[r][c+1]=0;
                add=add+1;
            }

            else if(add==maxadd)
            {
              break;
            }
        }
    }

    for(r=0;r<tiles;r++)
    {
        for(c=0;c<tiles;c++)
        {
            for(j=0;j<tiles-c-1;j++)
            {
                if(grid[r][j]==0 && grid[r][j+1]!=0)
                {
                    grid[r][j]=grid[r][j+1];
                    grid[r][j+1]=0;
                }
            }
        }
    }

}

// Check for end of game

void check(){
    int r,c;

    // Check for 2048 in any tile

    for(r=0;r<tiles;r++)
    {
        for(c=0;c<tiles;c++)
        {
            if(grid[r][c]==2048)
            {
                printf("\n2048 achieved.\n");
                exit(0);
            }
        }
    }

    // Empty tiles - game can continue

    for(r=0;r<tiles;r++)
    {
        for(c=0;c<tiles;c++)
        {
            if(grid[r][c] == 0)
            {
                return;
            }
        }


    }



    for(r=0;r<tiles;r++)
    {
        for(c=0;c<tiles-1;c++)

        {
           if(grid[r][c] == grid[r][c+1])
           {
           return;
           }

        }
    }
    for(c=0;c<tiles;c++)
    {
        for(r=0;r<tiles-1;r++)

        {
           if(grid[r][c] == grid[r+1][c])
           {
           return;
           }

        }
    }

printf("\n Game Over \n");
exit(0);
}
// generate random numbers for tiles
int gennum()
{
    int c;
    c=0;

    int value[] ={2,4,2,4,2,4,2,4,2};

    srand((unsigned)time(&t));

    c=rand()%10;

    return value[c];
}




// Initilize the game
void initialize()
{
    grid[row][col]=gennum();  // Seed random number gernerator

}



// update console
void display()
{
    int i,j;

    for(i=0; i<tiles; i++){
        for(j=0; j<tiles; j++)
        {
           printf("%d\t", grid[i][j]);
        }
    printf("\n");
    }
}

// Allocate memory for tiles

void allocate()
{

int c, d;

grid = malloc( tiles * sizeof(int));

for(c=0; c< tiles; c++)
    {
    grid[c] = malloc( tiles * sizeof(int));
    }
for(c=0; c<tiles; c++)
    {
    for(d=0; d<tiles; d++)
        grid[c][d] = 0;
    }

}
// Set MAX additions allowed based on num of tiles
void setadd()
{
    if(tiles==3)
    {
        maxadd=1;
    }

    else if(tiles==4)
    {
        maxadd=2;
    }

    else if(tiles==5)
    {
        maxadd=2;
    }
}

void gennxt()
{

    srand((unsigned)time(&t));

    do{
    row=rand()%tiles;
    col=rand()%tiles;
    }while (grid[row][col]!=0);

    initialize();

}
