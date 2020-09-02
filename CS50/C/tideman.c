#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);
        printf("\n");
    }
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0) //if the candidate exists
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int difference1, difference2;
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            difference1 = preferences[pairs[j].winner][pairs[j].loser] -
                          preferences[pairs[j].loser][pairs[j].winner]; //difference in preference "points" between 1st pair
            difference2 = preferences[pairs[j + 1].winner][pairs[j + 1].loser] - preferences[pairs[j + 1].loser][pairs[j + 1].winner];
            if (difference1 < difference2)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    //qsort(pairs, pair_count, sizeof(pair), compare);
    return;
}

bool cycle_help(int i, bool checked[]) //do we have a graph or not
{
    if (checked[i]) //been there already
    {
        return true;
    }
    checked[i] = true; //here for the first time
    for (int j = 0; j < candidate_count; j++) //check i's neighbors in locked
    {
        if (locked[i][j] && cycle_help(j, checked)) // if there's edge from i to j and we check j's neighbors - recursively
        {
            return true;
        }
    }
    return false; //when we already searched all candidates and don't find any cycles
}

bool cycle(int start)
{
    bool checked[candidate_count]; //there's cycle if we come back to true
    for (int i = 0; i < candidate_count; i++)
    {
        checked[i] = false; //no one was checked yet at the beginning
    }
    return cycle_help(start, checked);
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        if (cycle(pairs[i].winner)) //if there's cycle beginning with this winner of pair
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    return;
}

bool is_source(int i)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (locked[j][i]) //if there is someone above i
        {
            return false;
        }
    }
    return true;
}

int source() //if there vas a candidate with no incoming edges
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (is_source(i)) //if i is a source
        {
            return i;
        }
    }
    return -1;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int winner = source();
    if (winner != -1)
    {
        printf("%s\n", candidates[winner]);
    }
    return;
}

