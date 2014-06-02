/* 
 * The "utils.h" header defines the following three utility functions:
 * int getaline(char *linebuf, int bufsize) - read a line of user input into 
 *      the buffer linebuf
 * int split(char *s, int start, char sep, char **substrings, int max) - split
 *      a string at the separator character sep into at most max substrings, 
 *      starting at position start
 * int trim(char *s, char c) - trim a string of leading and trailing sequences
 *      of the character c, returning the position of the first non-c character
 *
 * Implementors of these functions should only use the C library function
 * getchar.
 */

#ifndef _UTILS_H      /* check if "utils.h" is already included */ 
#define _UTILS_H      /* it is not included; define it */

/*
 * int getaline(char* linebuf, int bufsize)
 *
 * Read a line of user input from stdin into the buffer linebuf a character at 
 * a time.
 *
 * After successful execution of the function, linebuf will contain up to  
 * bufsize - 1 characters from user input and will be terminated by the '\0' 
 * character. That is, linebuf can be treated as a string of up to busize -1 
 * characters not including the terminator character. The buffer must NOT
 * contain the end of line character ('\n'). 
 * 
 * The library function getchar can be used to read a character at a time from
 * stdin.
 *
 * Parameters:
 *  linebuf - the buffer to fill with characters from the stdin stream. linebuf
 *      is modified by this function.
 *  bufsize - the size of the linebuf buffer 
 * Return:
 *  The number of characters read from user input, -1 if there is an error. If 
 *  linebuf is filled, the number returned will be bufsize - 1 and there may be
 *  more user input. If the number returned is 0, there was in effect no 
 *  user input (e.g. the only character entered was the new line character)
 */
int getaline(char* linebuf, int bufsize);

/*	
 * int split(char *s, int start, char sep, char **substrings, int max)
 * 
 * Split a string, s, into at most max substrings at the given separator
 * character. The substrings array is used to hold pointers to the 
 * resulting substrings of s. If s does not contain the separator character then
 * a pointer to the single string s will be in the substrings array. Unused 
 * elements of the substrings buffer will be set to NULL.
 * 
 * If s contains sequences of more than one separator between sequences of 
 * non-separator characters, this function will terminate a substring at the 
 * first separator and skip to the next non-separator character to start the 
 * next substring. This function does *not* treat sequences of leading or
 * trailing separator characters as special cases. This means that, after
 * calling split, the first and/or last elements of the substrings array may 
 * point to the empty string. For example, for the following inputs:
 *      char s[]:     "--ab--c--" 
 *      int start:    0
 *      char sep:     '-'
 *      int max:      4
 *      The substrings buffer will have points to the following strings:
 *      { "", "ab", "c", "" }
 * 
 * Other variations of the input string can result in empty strings at the
 * beginning and/or end of the substrings buffer.
 *      
 * To skip leading and trailing separator characters, use trim before calling
 * split. If trim is used before split, and the return value of trim is used for
 * the start value of split, this function will correctly return 0 for a string
 * s that only contains separator characters.
 *
 * Parameters:
 *  s - the input string. This function may modify s. There is no copying of 
 *      characters.
 *  start - the position in s to start the search for separator characters. The 
 *      first substring will start from this position in s. If start is less 
 *      than 0, the number of substrings will be 0.
 *  sep - the character at which substrings should be created
 *  substrings - the array to populate with pointers to substrings of s.
 *      substrings is modified by this function. Neither characters nor strings 
 *      are copied to substrings. The elements of substrings are simply pointers
 *      to substrings of s. If there are less than max substrings, then the
 *      remaining elements of the substrings buffer will be set to NULL.
 *  max - the maximum number of substrings required. This should be less than 
 *      or equal to the size of the substrings buffer. 
 *      It is possible for s to contain more than max substrings, in
 *      which case the final pointer in the substrings buffer will point to a 
 *      substring that contains one or more separator characters.
 * Return:
 *      the number of pointers to strings in substrings. If s contains at 
 *      least one non-separator character and max is at least 1, the number 
 *      of substrings will be at least 1. If the number of 
 *      substrings is less than max, then the elements of substrings from
 *      number to max - 1 will be NULL.
*/
int split(char *s, int start, char sep, char **substrings, int max);


/*	
 * int trim(char *s, char c)
 *
 * Trim the input string of leading and trailing sequences of the specified
 * character c. The return value is the position of the first character in s
 * that is not c. 
 *
 * Parameters:
 *  s - the input string. s may be modified by this function, there is no
 *      copying of characters. 
 *  c - the character to trim from the beginning and end of s
 * Return:
 *      the position of the first character in s that is not c. -1 if s 
 *      contains no other character than c (not including the terminator
 *      character).
 */
int trim(char *s, char c);

#endif /* _UTILS_H */

