#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "intmath.h"

/* Method to add two integers */
int add(int x, int y)
{
    /* For loop which increments x, y times */
    int i;
    for(i = 0; i < y; i++)
    {
        x++;

        /* Check whether integer overflow has occurred */
        if(x == INT_MAX || x == INT_MIN)
        {
            errno = ERANGE;
            return -1;
        }
    }

    /* Check whether y is negative */
    if(y < 0)
    {
        /* For loop which increments x backwards, y times */
        for(i = 0; i > y; i--)
        {
            x--;

            /* Check whether integer overflow has occurred */
            if(x == INT_MAX || x == INT_MIN)
            {
                errno = ERANGE;
                return -1;
            }
        }
    }

    /* Return result */
    return x;
}

/* Method to subtract two integers */
int subtract(int x, int y)
{
    /* For loop to increment x backwards, y times */
    int i;
    for(i = 0; i < y; i++)
    {
        x--;

        /* Check whether integer overflow has occurred */
        if(x == INT_MAX || x == INT_MIN)
        {
            errno = ERANGE;
            return -1;
        }
    }

    /* Check to see whether y is negative */
    if(y < 0)
    {
        /* For loop which increments x, y times */
        for(i = 0; i > y; i--)
        {
            x++;

            /* Check whether integer overflow has occurred */
            if(x == INT_MAX || x == INT_MIN)
            {
                errno = ERANGE;
                return -1;
            }
        }
    }

    /* Return result */
    return x;
}

/* Method to divide two integers */
int divide(int n, int d)
{
    /* Initialise count, to count the number of times d goes into n */
    int count = 0;
    /* Initialise temp, which holds d */
    int temp = d;
    int i;

    /* Check to see whether d = 0 */
    if(d == 0)
    {
        errno = EDOM;
        return -1;
    }

    /* Check to see whether an integer overflow will occur under special case */
    if(n == INT_MIN && d == -1)
    {
        errno = ERANGE;
        return -1;
    }

    /* If n is positive */
    if(n > 0)
    {
        /* If n and d are both positive */
        if(d > 0)
        {
            /* For loop to calculate the division */
            for(i = 0; i < 1000; i++)
            {
                /* Add d and it's original value */
                d = add(d, temp);

                if(n == d)
                {
                    count++;
                }
                else if(d > n)
                {
                    count++;
                    return count;
                }
                else
                {
                    count++;
                }
            }
            count++;
            return count;
        }
        /* If n is positive and d is negative */
        else
        {
            for(i = 0; i < 1000; i++)
            {
                d = add(d, temp);

                if(-n == d)
                {
                    count--;
                    count--;
                    return count;
                }
                else if(-d > n)
                {
                    count--;
                    return count;
                }
                else
                {
                    count--;
                }
            }
            count--;
            return count;
        }
    }
    else if(n < 0)
    {
        /* If n is negative and d is positive */
        if(d > 0)
        {
            for(i = 0; i < 1000; i++)
            {
                d = add(d, temp);

                if(n == -d)
                {
                    count--;
                    count--;
                    return count;
                }
                else if(-d < n)
                {
                    count--;
                    return count;
                }
                else
                {
                    count--;
                }
            }
            count--;
            return count;
        }
        /* If n is negative and d is negative */
        else
        {
            for(i = 0; i < 1000; i++)
            {
                d = add(d, temp);

                if(n == d)
                {
                    count++;
                    count++;
                    return count;
                }
                else if(d < n)
                {
                    count++;
                    return count;
                }
                else
                {
                    count++;
                }
            }
            count++;
            return count;
        }
    }
}

/* Method to modulo two integers */
int modulo(int n, int d)
{
    /* Initialise count, to count the number of times d goes into n */
    int count = 0;
    /* Initialise temp, which holds d */
    int temp = d;
    int i;

    /* Check to see whether d = 0s */
    if(d == 0)
    {
        errno = EDOM;
        return 0;
    }

    /* Check to see whether an integer overflow will occur under special case */
    if(n == INT_MIN && d == -1)
    {
        errno = ERANGE;
        return -1;
    }

    if(n > 0)
    {
        /* If n is positive and d is positive */
        if(d > 0)
        {
            for(i = 0; i < 1000; i++)
            {
                d = add(d, temp);

                if(n == d)
                {
                    return 0;
                }
                else if(d > n)
                {
                    d = subtract(d, temp);
                    return subtract(n, d);
                }
            }
        }
        /* If n is positive and d is negative */
        else
        {
            for(i = 0; i < 1000; i++)
            {
                d = add(d, temp);

                if(-n == d)
                {
                    return 0;
                }
                else if(d < -n)
                {
                    d = subtract(d, temp);
                    return subtract(n, -d);
                }
            }
        }
    }
    else if(n < 0)
    {
        /* If n is negative and d is positive */
        if(d > 0)
        {
            for(i = 0; i < 1000; i++)
            {
                d = add(d, temp);

                if(n == -d)
                {
                    return 0;
                }
                else if(-d < n)
                {
                    d = subtract(d, temp);
                    return subtract(n, -d);
                }
            }
        }
        /* If n is negative and d is negative */
        else
        {
            for(i = 0; i < 1000; i++)
            {
                d = add(d, temp);

                if(n == d)
                {
                    return 0;
                }
                else if(d < n)
                {
                    d = subtract(d, temp);
                    return subtract(n, d);
                }
            }
        }
    }
}

/* Method for division */
int division(int n, int d, int *r)
{
    if(d == 0)
    {
        errno = EDOM;
        *r = 0;
        return -1;
    }

    /* Check to see whether an integer overflow will occur under special case */
    if(n == INT_MIN && d == -1)
    {
        errno = ERANGE;
        *r = 0;
        return -1;
    }

    *r = modulo(n, d);
    return divide(n, d);
}