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
node head;
int count;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node trav = head;
    int i = 0;
    
    while(true)
    {
        if (word[i] == '\0')
            return trav.is_word;
        else if (search(word[i], &trav))
            i++;
        else
            return false;
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
    node trav = head;
    
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
            search(c, &trav);
            
        //resset once we reach the end of a word
        else if (c == '\n')
        {
            trav.is_word = true;
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
    // TODO
    return true;
}

//iterate through trie to search and create it.
bool search(char letter, node* trav1)
{
    switch (letter)
    {
        case 'a':
        //move to next leg of trie if it's already there
            if (trav1->a != NULL)
            {
                trav1 = trav1->a;
                return true;
            }
            //create new node if it doesn't already exist.
            else if (trav1->a == NULL)
            {
                trav1->a = malloc(sizeof(node));
                trav1 = trav1->a;
                return false;
            }
        case 'b':
            if (trav1->b != NULL)
            {
                trav1 = trav1->b;
                return true;
            }
            else if (trav1->b == NULL)
            {
                trav1->b = malloc(sizeof(node));
                trav1 = trav1->b;
                return false;
            }
        case 'c':
            if (trav1->c != NULL)
            {
                trav1 = trav1->c;
                return true;
            }
            else if (trav1->c == NULL)
            {
                trav1->c = malloc(sizeof(node));
                trav1 = trav1->c;
                return false;
            }
        case 'd':
            if (trav1->d != NULL)
            {
                trav1 = trav1->d;
                return true;
            }
            else if (trav1->d == NULL)
            {
                trav1->d = malloc(sizeof(node));
                trav1 = trav1->d;
                return false;
            }
        case 'e':
            if (trav1->e != NULL)
            {
                trav1 = trav1->e;
                return true;
            }
            else if (trav1->e == NULL)
            {
                trav1->e = malloc(sizeof(node));
                trav1 = trav1->e;
                return false;
            }
        case 'f':
            if (trav1->f != NULL)
            {
                trav1 = trav1->f;
                return true;
            }
            else if (trav1->f == NULL)
            {
                trav1->f = malloc(sizeof(node));
                trav1 = trav1->f;
                return false;
            }
        case 'g':
            if (trav1->g != NULL)
            {
                trav1 = trav1->g;
                return true;
            }
            else if (trav1->g == NULL)
            {
                trav1->g = malloc(sizeof(node));
                trav1 = trav1->g;
                return false;
            }
        case 'h':
            if (trav1->h != NULL)
            {
                trav1 = trav1->h;
                return true;
            }
            else if (trav1->h == NULL)
            {
                trav1->h = malloc(sizeof(node));
                trav1 = trav1->h;
                return false;
            }
        case 'i':
            if (trav1->i != NULL)
            {
                trav1 = trav1->i;
                return true;
            }
            else if (trav1->i == NULL)
            {
                trav1->i = malloc(sizeof(node));
                trav1 = trav1->i;
                return false;
            }
        case 'j':
            if (trav1->j != NULL)
            {
                trav1 = trav1->j;
                return true;
            }
            else if (trav1->j == NULL)
            {
                trav1->j = malloc(sizeof(node));
                trav1 = trav1->j;
                return false;
            }
        case 'k':
            if (trav1->k != NULL)
            {
                trav1 = trav1->k;
                return true;
            }
            else if (trav1->k == NULL)
            {
                trav1->k = malloc(sizeof(node));
                trav1 = trav1->k;
                return false;
            }
        case 'l':
            if (trav1->l != NULL)
            {
                trav1 = trav1->l;
                return true;
            }
            else if (trav1->l == NULL)
            {
                trav1->l = malloc(sizeof(node));
                trav1 = trav1->l;
                return false;
            }
        case 'm':
            if (trav1->m != NULL)
            {
                trav1 = trav1->m;
                return true;
            }
            else if (trav1->m == NULL)
            {
                trav1->m = malloc(sizeof(node));
                trav1 = trav1->m;
                return false;
            }
        case 'n':
            if (trav1->n != NULL)
            {
                trav1 = trav1->n;
                return true;
            }
            else if (trav1->n == NULL)
            {
                trav1->n = malloc(sizeof(node));
                trav1 = trav1->n;
                return false;
            }
        case 'o':
            if (trav1->o != NULL)
            {
                trav1 = trav1->o;
                return true;
            }
            else if (trav1->o == NULL)
            {
                trav1->o = malloc(sizeof(node));
                trav1 = trav1->o;
                return false;
            }
        case 'p':
            if (trav1->p != NULL)
            {
                trav1 = trav1->p;
                return true;
            }
            else if (trav1->p == NULL)
            {
                trav1->p = malloc(sizeof(node));
                trav1 = trav1->p;
                return false;
            }
        case 'q':
            if (trav1->q != NULL)
            {
                trav1 = trav1->q;
                return true;
            }
            else if (trav1->q == NULL)
            {
                trav1->q = malloc(sizeof(node));
                trav1 = trav1->q;
                return false;
            }
        case 'r':
            if (trav1->r != NULL)
            {
                trav1 = trav1->r;
                return true;
            }
            else if (trav1->r == NULL)
            {
                trav1->r = malloc(sizeof(node));
                trav1 = trav1->r;
                return false;
            }
        case 's':
            if (trav1->s != NULL)
            {
                trav1 = trav1->s;
                return true;
            }
            else if (trav1->s == NULL)
            {
                trav1->s = malloc(sizeof(node));
                trav1 = trav1->s;
                return false;
            }
        case 't':
            if (trav1->t != NULL)
            {
                trav1 = trav1->t;
                return true;
            }
            else if (trav1->t == NULL)
            {
                trav1->t = malloc(sizeof(node));
                trav1 = trav1->t;
                return false;
            }
        case 'u':
            if (trav1->u != NULL)
            {
                trav1 = trav1->u;
                return true;
            }
            else if (trav1->u == NULL)
            {
                trav1->u = malloc(sizeof(node));
                trav1 = trav1->u;
                return false;
            }
        case 'v':
            if (trav1->v != NULL)
            {
                trav1 = trav1->v;
                return true;
            }
            else if (trav1->v == NULL)
            {
                trav1->v = malloc(sizeof(node));
                trav1 = trav1->v;
                return false;
            }
        case 'w':
            if (trav1->w != NULL)
            {
                trav1 = trav1->w;
                return true;
            }
            else if (trav1->w == NULL)
            {
                trav1->w = malloc(sizeof(node));
                trav1 = trav1->w;
                return false;
            }
        case 'x':
            if (trav1->x != NULL)
            {
                trav1 = trav1->x;
                return true;
            }
            else if (trav1->x == NULL)
            {
                trav1->x = malloc(sizeof(node));
                trav1 = trav1->x;
                return false;
            }
        case 'y':
            if (trav1->y != NULL)
            {
                trav1 = trav1->y;
                return true;
            }
            else if (trav1->y == NULL)
            {
                trav1->y = malloc(sizeof(node));
                trav1 = trav1->y;
                return false;
            }
        case 'z':
            if (trav1->z != NULL)
            {
                trav1 = trav1->z;
                return true;
            }
            else if (trav1->z == NULL)
            {
                trav1->z = malloc(sizeof(node));
                trav1 = trav1->z;
                return false;
            }
        case '\'':
            if (trav1->aps != NULL)
            {
                trav1 = trav1->aps;
                return true;
            }
            else if (trav1->aps == NULL)
            {
                trav1->aps = malloc(sizeof(node));
                trav1 = trav1->aps;
                return false;
            }
    }
     return false;
    
/**    
    *if (trav1->letter != NULL)
    *{
    *    trav1 = trav1->letter;
    *    return;
    *}
    *else if (trav1->letter == NULL)
    *{
    *    trav1->letter = malloc(sizeof(node));
    *    trav1 = trav1->letter;
    *    return;
    *}
    */
}