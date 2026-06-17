#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    for(int i=x; i<x+width; i++)
    {
        canvas[y][i] = '*';
        canvas[y+height-1][i] = '*';
    }

    for(int i=y; i<y+height; i++)
    {
        canvas[i][x] = '*';
        canvas[i][x+width-1] = '*';
    }
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for(int i=0; i<=steps; i++)
    {
        canvas[(int)(y+0.5)][(int)(x+0.5)]='*';
        x += xInc;
        y += yInc;
    }
}

int main()
{
    int choice;

    initializeCanvas();

    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Display Canvas\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Line\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                displayCanvas();
                break;

            case 2:
                drawRectangle(5,5,10,6);
                printf("Rectangle Drawn!\n");
                break;

            case 3:
                drawLine(0,0,15,10);
                printf("Line Drawn!\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice!=4);

    return 0;
}
