#include <stdio.h>
#include <cs50.h>
#include <math.h>

float change(void);
int main(void)
{
    float cash = change();
    int cents = round(cash * 100); // convert to integer for safety reasons
    int coins = 0; // counter
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
     while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
     while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
     while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    //print only coins
    printf("%i\n", coins);
}

float change(void)
{
    float m;
    do
    {
        m = get_float("Change owed: ");
    }
    while (m < 0); // must be positive
    return m;
}
