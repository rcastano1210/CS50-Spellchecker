/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

//node *head = malloc(sizeof(node));
node *head;
int count;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node *trav = head;
    int i = 0;
    
    while(true)
    {
        if (word[i] == '\0')
            return trav->is_word;
        else
        {
            char low = tolower(word[i]);
            
            if (isalpha(low))
            {
                //move to next leg of trie if found
                if (trav->branch[low - 'a'] != NULL)
                {
                    trav = trav->branch[low - 'a'];
                    i++;
                }
                //return false if no more letter branches found
                else
                    return false;
            }
            //dealing with apostrophes
            else
            {
                if (trav->branch[26] != NULL)
                {
                    trav = trav->branch[26];
                    i++;
                }
                //return false if no more letters branches found
                else
                    return false;
            }
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //Open dictionary
    FILE* fp = fopen(dictionary, "r");
    
    //close if dictionary doesn't open
    if(fp == NULL)
    {
        fclose(fp);
        return false;
    }
    
    //set word counter and trav to point at the head of our trie
    count = 0;
    head = malloc(sizeof(node));
    node *trav = head;
    
    while(true)
    {
        //exit when you reach eof
        if (feof(fp))
        {
            fclose(fp);
            return true;
        }
        
        //read in character by character
        char c = fgetc(fp);
        
        //check to see if we're reading in a word
        if (isalpha(c) || c == '\'')
        {
            if (isalpha(c))
            {
                //move to next leg of trie if it's already there
                if (trav->branch[c - 'a'] != NULL)
                    trav = trav->branch[c - 'a'];
                //create new node if it exists
                else
                {
                    trav->branch[c - 'a'] = malloc(sizeof(node));
                    trav = trav->branch[c - 'a'];
                }
            }
            //dealing with apostrophes
            else
            {
                if (trav->branch[26] != NULL)
                    trav = trav->branch[26];
                //create new node if it doesn't exists
                else
                {
                    trav->branch[26] = malloc(sizeof(node));
                    trav = trav->branch[26];
                }
            }
        }
            
        //reset once we reach the end of a word
        else if (c == '\n')
        {
            trav->is_word = true;
            trav = head;
            count++;
        }
    }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    if (unload1(head))
        return true;
    return false;
}

bool unload1(node *trav)
{
    for(int i = 0; i<27; i++)
    {
        if(trav->branch[i] != NULL)
            unload1(trav->branch[i]);
    }
    
    free(trav);
    return true;
}
