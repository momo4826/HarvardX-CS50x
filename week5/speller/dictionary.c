// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>//strcspn
#include <strings.h>//strcasecmp

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

void free_llist(node *llist);

//onst unsigned int N = 26; //original
//const unsigned int N = 33; //djb2
const unsigned int N = 50000; //mine
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int hash_code = hash(word);

    for (node *tmp = table[hash_code]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // original
    //printf("%d\n", toupper(word[0]) - 'A');
    //return toupper(word[0]) - 'A';

    //djb2
    // printf("%s:", word);
    // unsigned int hash = 5381;
    // int c;

    // while ((c = *word++))
    // {
    //     if (isupper(c))
    //     {
    //         c = c + 32;
    //     }
    //     hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    // }

    // printf("%d\n", hash);
    // return hash;

    //mine
    //plan 1: too much time for loading, 0.59
    // unsigned int res = toupper(word[0]) - 'A';
    // int i = 1;
    // while(i < LENGTH && word[i] != '\0')
    // {
    //     if (word[i] != '\'')
    //     {
    //         res += toupper(word[i]) - 'A';
    //         break;
    //     }
    //     i++;
    // }
    // printf("%s: %d\n", word, res);
    // return res;
    //plan 2:
    unsigned int res = toupper(word[0]);
    int i = 1;
    while (word[i] != '\0')
    {
        res *= toupper(word[i]);
        i++;
    }
    return res % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *fd = fopen(dictionary, "r");
    if (fd == NULL)
    {
        return false;
    }
    char current_word[LENGTH + 2];
    unsigned int hash_code;
    node *new;
    while (fgets(current_word, LENGTH + 2, fd))
    {
        current_word[strcspn(current_word, "\n")] = 0;
        //printf("%s\n", current_word);
        hash_code = hash(current_word);
        new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }
        strcpy(new->word, current_word);
        //printf("here\n");
        if (table[hash_code] == NULL)
        {
            new->next = NULL;
        }
        else
        {
            //printf("load:  %s\n", table[hash_code]->word);
            new->next = table[hash_code];
        }
        table[hash_code] = new;

    }
    fclose(fd);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
        {
            //printf("size:  %s\n", tmp->next->word);
            res++;
        }
    }
    return res;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        free_llist(table[i]);
    }
    return true;
}
void free_llist(node *llist)
{
    if (llist == NULL)
    {
        return;
    }
    if (llist->next == NULL)
    {
        free(llist);
        return;
    }
    else
    {
        free_llist(llist->next);
        free(llist);
    }
}
