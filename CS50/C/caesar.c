#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char fixLetter(char c, char w, char key, int x);
int getkey(int arc, string arv[]);
int main(int argc, string argv[])
{
    int key = getkey(argc, argv); //gives only numeric key
    if (key > 0)
    {
        string word = get_string("plaintext: ");
        string cipher = word; //set another array
        char c, w;
        for (int i = 0, l = strlen(word); i < l; i++)
        {
            w = (char)word[i]; //for the sake of writing shorter inputs
            c = (char)cipher[i];
            if (isupper(w))
            {
                cipher[i] =  fixLetter(c, w, key, 65);
            }
            else if (islower(w))
            {
                cipher[i] =  fixLetter(c, w, key, 97);
            }
        }
        printf("ciphertext: %s\n", cipher);
    }
    else
    {
        return 1;
    }
}

int getkey(int arc, string arv[]) //filter for numbers only
{
    int k = 0;
    if (arc != 2) //if there is less or more inputs than necessary
    {
        printf("Usage: ./ceasar key \n");
    }
    else
    {
        string input = arv[1]; //check string in 2nd place - key
        for (int i = 0, l = strlen(input); i < l; i++)
        {
            if (isdigit(input[i]) == 0) //if it is not a digit
            {
                printf("Usage: ./ceasar key \n");
                return -1;
            }
            else
            {
                k = atoi(arv[1]); //converts string to int
            }
        }
    }
    return k;
}

char fixLetter(char c, char w, char key, int x) // c is cipher char, w word char, x is 65(A) or 97(a)
{
    c = w + key; //move for key signs forward
    c -= x;     //move to 0 + c on ascii table
    c %= 26;    //fix the alphabet overflow
    c += x;     //move back to alphabet part of ascii table
    return c;
}