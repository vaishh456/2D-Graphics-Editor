#include <stdio.h>

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

int main()
{
    int choice;

    initializeCanvas();

    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Display Canvas\n");
        printf("2. Draw Rectangle\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                displayCanvas();
                break;

            case 2:
                drawRectangle(5, 5, 10, 6);
                printf("Rectangle Drawn!\n");
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice!=3);

    return 0;
}
