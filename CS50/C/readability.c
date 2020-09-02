#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int ColemanLiau(float avgL, float avgS);
int main(void)
{
    string text = get_string("Text: ");
    int countL = 0;
    int countW = 1; //there is no space before first word
    int countS = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (((64 < text[i]) && (text [i] < 91)) || //checks for letters
            ((96 < text[i]) && (text [i] < 123)))
        {
            countL++;
        }
        else if (text[i] == 32) //checks for spaces
        {
            countW++;
        }
        else if (text[i] == 46 || text [i] == 63 || text[i] == 33)//checks for punctuation
        {
            countS++;
        }
    }
    float avgL = ((float)countL / (float)countW) * 100; // average letters/100 words
    float avgS = ((float)countS / (float)countW) * 100; // average sentences/100 words
    int index = ColemanLiau(avgL, avgS);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
int ColemanLiau(float avgL, float avgS) //returns index from averages
{
    float clIndex = 0.0588 * avgL - 0.296 * avgS - 15.8;
    return round(clIndex);
}