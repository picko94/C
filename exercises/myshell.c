#include <stdio.h>

#define TRUE 1
#define MAX_LINE 80
#define MAX_SUBS 10

void prompt(void)
{
    /* String array for user prompt */
    char string[] = "Enter a MINIX command: [Q = Quit]\n";
    int i = 0;

    while(string[i] != '\0')
    {
        putchar(string[i]);
        i++;
    }
}

int main(void)
{
    /* Variables for user input */
    char linebuf[MAX_LINE];
    char *substr[MAX_SUBS];
    char sep = ' ';
    int start;
    int count;
    int j = 0;

    while(TRUE)
    {
	prompt();

        /* get a string of characters of user input */
        if (getaline(linebuf, MAX_LINE) > 0)
        {
            /* If user inputs 'Q' then end process */
            if((linebuf[0] == 'Q') && (linebuf[1] == '\0'))
            {
                break;
            }
            /* trim leading and trailing spaces */
            start = trim(linebuf, sep);

            /* split input at each space character */
            count = split(linebuf, start, sep, substr, MAX_SUBS);

            printf("number of substrings: %d\n", count);

            /* if this is command line input from the user
             * substr[0] is the command
             * substr[1] ... substr[count-1] are the parameters
             */
            for (j = 0; j < count; j++)
            {
                    printf("substring %d: %s\n", j, substr[j]);
            }
        }
		
		/*
		if(fork() != 0)
		{
			wait(pid);
		}
		else
		{
			execve();
		}
		*/
    }
}
