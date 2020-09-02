#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int checkDoubles(string key);
string getKey(int argc, string argv[]);
int main(int argc, string argv[])
{
    string key = getKey(argc, argv);
    if (atoi(key) != 1)
    {
        string word = get_string("plaintext: ");
        string cipher = word;
        string alphA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";// alphabet
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0, l = strlen(word); i < l; i++) // checks each letter of the word
        {
            int j = 0;
            if (isalpha(word[i]) == 0)
            {
                cipher[i] = word[i];
            }
            else
            {
                if (isupper(word[i]) != 0)          //letter is uppercase
                {
                    while (word[i] != alphA[j])
                    {
                        j++;
                    }
                    cipher[i] = toupper(key[j]);    //keep uppercase
                }
                else                                //letter is lowercase
                {
                    while (word[i] != alpha[j])
                    {
                        j++;
                    }
                    cipher[i] = tolower(key[j]);    //keep lowercase
                }

            }
        }
        printf("ciphertext: %s\n", cipher);
        return 0;
    }
    else                    // if the key is not accepted
    {
        return 1;
    }
}
string getKey(int argc, string argv[])
{
    string key = "1"; //return value
    int i = 0;
    if (argc != 2)  // if there's no input or spaces in input
    {
        printf("Usage: ./substitution key \n");
        key = "1";
    }
    else
    {
        string input = argv[1];         //save input for key and then verify
        int l = strlen(input);
        while (i < l)                    //read input
        {

            if (isalpha((char)input[i]) == 0)       //if it's not alphabetic character
            {
                printf("Usage: ./substitution key \n");
                key = "1";                          // return value
                i += l + 1 ;                        // +1 is to fix the i==l later
            }
            else
            {
                key = input;                        //return value
                i++;
            }
        }

        if (i == l && i != 26)                      // check length of key
        {
            printf("Key must contain 26 characters. \n");
            key = "1";
        }
        if (checkDoubles(input) == 1)
        {
            printf("Usage: ./substitution key \n");
            key = "1";
        }
    }
    return key;
}
int checkDoubles(string key)
{
    string check = key; // check for double characters in key
    for (int m = 0; m < 26; m++)
    {
        for (int n = 0; n < 26; n++)
        {
            if (m != n && toupper(key[m]) == toupper(check[n]))
            {
                return 1;
            }
        }
    }
    return 0;
}