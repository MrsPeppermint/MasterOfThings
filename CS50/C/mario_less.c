#include <stdio.h>
#include <cs50.h>

int getHeight(void);
int main(void)
{
    int height = getHeight();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i + j > (height - 2))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
// gives only heights 1-8
int getHeight(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}
