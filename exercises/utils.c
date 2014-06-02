#include <stdio.h>
#include "utils.h"

/* constant buffer sizes - define appropriate values */
#define MAX_LINE 80
#define MAX_SUBS 10

int getaline(char* linebuf, int bufsize)
{
    /* Variable used to find the amount of characters entered */
    int total = 0;

    /* User input */
    linebuf[total] = getchar();

    /* While loop to add up the total amount of characters inputted */
    while((linebuf[total] != EOF) && (linebuf[total] != '\n'))
    {
        /* If the amount of characters entered is over MAX_LINE */
        if(total >= bufsize)
        {
            total--;
            linebuf[total] = '\0';
            break;
        }
        total++;
        linebuf[total] = getchar();
    }

    linebuf[total] = '\0';
    return total;
}

int split(char *s, int start, char sep, char **substrings, int max)
{
    /* Variables used to identify elements in the array */
    int i = 0;
    int index = 0;

    /* While loop to iterate while there are still characters and not over max */
    while((s[i] != '\0') && (index < max))
    {
        /* While loop to take seperator characters and change them to \0 */
        while(s[i] == sep)
        {
            s[i] = '\0';
            i++;
        }

        /* Set start to the next non-seperator character */
        start = i;

        /* Add pointer of substring */
        substrings[index] = &s[start];
        index++;

        /* While loop to find next non-seperator character */
        while((s[i] != sep) && (s[i] != '\0'))
        {
            i++;
        }

        /* If there are no more characters left, break out of loop */
        if(s[i] == '\0')
        {
            break;
        }
    }

    /* If the number of substrings is less than max, then the other elements of substrings will be NULL */
    for(i = index; i < max; i++)
    {
        substrings[i] = NULL;
    }

    return index;
}

int trim(char *s, char c)
{
    /* Variable to find the size of s */
    int size = 0;

    /* Variable used to find the position of the first non-seperator character */
    int pos = 0;

    /* Varaible used to check if s contains no other character than c */
    int check = 0;
    int i;

    /* While loop to find the size of s */
    while(s[size] != '\0')
    {
        size++;
    }

    /* For loop to go through s until it finds a non-seperator character */
    for(i = 0; i < size; i++)
    {
        if(s[i] == c)
        {
            pos++;
        }
        else
        {
            break;
        }
        check++;
    }

    /* For loop to back track through s until it finds a non-seperator character */
    for(i = size -1; i > 0; i--)
    {
        if(s[i] != c)
        {
            s[i+1] = '\0';
            break;
        }
    }

    /* If s contains no other characters than c, then return -1 */
    if(check == size)
    {
        pos = -1;
    }

    return pos;
}

