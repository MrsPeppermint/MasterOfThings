#include <stdio.h>
#include <cs50.h>

int getHeight(void);
int main(void)
{
    int stored = getHeight(); //gives 1-8 heights
    for (int i = 1; i <= stored; i++) //num. of rows = stored
    {
        for (int j = 1; j < stored + 2 + i; j++) // = num. of columns = stored + num. of #
        {
            if (j - 1 == stored) // empty column
            {
                printf("  ");
            }
            else if (i + j > stored && j < stored + 1) // copy of easier version but limited on the right
            {
                printf("#");
            }
            else if (j > stored + 1) // till the end of the row
            {
                printf("#");
            }
            else
            {
                printf(" "); //filler
            }
        }
        printf("\n");
    }
}
int getHeight(void) // gives only heights 1-8
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}
