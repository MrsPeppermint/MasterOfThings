// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 143091;

//Counts number of words in dictionary in load function, used in size function
int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //copy word because hash encodes uppper and lowercase differently
    char copy[LENGTH + 1];

    //add end sign \0
    copy[strlen(word)] = '\0';

    //copy each char in lower
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        copy[i] = tolower(word[i]);
    }

    //hash copied word to obtain a hash value
    //access linked list at hash index in table
    node *cursor = table[hash(copy)];

    //traverse linked list - look for word --> strcasecmp () == 0
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        //move cursor to next node
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO

    /***************************************************************************************
    *   HASH FUNCTION
    *   Title: One-at-a-Time hash for strings
    *   Author: Bob Jenkins
    *   Year: 1996
    *   Availability: https://burtleburtle.net/bob/hash/doobs.html
    *
    ***************************************************************************************/

    uint32_t hash = 0;
    for (; *word; ++word)
    {
        hash += *word;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    //else read strings from file one at a time
    char dictionaryWord[LENGTH + 1];
    while (fscanf(file, "%s", dictionaryWord) != EOF)
    {
        //create a new node for each word
        node *n = malloc(sizeof(node));
        //if it doesn't have enough memory
        if (n == NULL)
        {
            unload();
            fclose(file);
            return false;
        }

        //strcpy(char dest,  const char src) - copy scanned word to node
        strcpy(n->word, dictionaryWord);

        //hash word to obtain a hash value
        int value = hash(n->word);
        //insert node into a hash table at that location
        node *cursor = table[value];

        //check if there is no other nodes
        if (cursor == NULL)
        {
            table[value] = n;
        }

        //else add at the beginning of linked list
        else
        {
            n->next = cursor;
            cursor = n;
            table[value] = n;
        }
        count++;
    }
    //close opened file!
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO - used global variable
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //TODO
    for (int i = 0; i < N; i++)
    {
        //if i'th element of the table is not empty yet
        if (table[i] != NULL)
        {
            node *cursor = table[i];
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}