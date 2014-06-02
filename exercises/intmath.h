/* 
 * The "intmath.h" header defines the following five integer arithmetic
 * functions:
 * int add(int x, int y) - returns the sum of x and y
 * int subtract(int x, int y) - returns the subtraction of y from x
 * int divide(int n, int d) - returns the integer division of n by d
 * int modulo(int n, int d) - returns the remainder when n is divided by d
 * int division(int n, int d, int *r) - returns the integer division of n by d
 *      and uses r to record the remainder
 *
 * Implementations of these functions check for overflow of the range of 
 * integers as described below.
 *
 * Implementors of these functions can only use the built-in arithmetic 
 * operators ++, -- and unary - negation.
 */

#ifndef _INTMATH_H      /* check if "intmath.h" is already included */ 
#define _INTMATH_H      /* it is not included; define it */

/*
 * int add(x, y)
 *
 * This function returns the sum of two integers (x and y) - adding y to x.
 *
 * The function checks for integer overflow. If the result of the addition of 
 * the two integers would exceed the defined range for integers then the value
 * of errno is set to ERANGE and the function returns -1.
 * 
 * It is the responsibility of users of this function to test for errno 
 * correctly and distinguish between the two cases: (1) where -1 is the valid 
 * result of the sum of two integers, and (2) when integer overflow would have
 * occurred.
 * See: http://man7.org/linux/man-pages/man3/errno.3.html for information on 
 *      errno
 * 
 * Parameters:
 *  x - the integer to add y to
 *  y - the integer to add to x
 * Return:
 *      the result of adding y to x
 */
int add(int x, int y);

/*
 * int subtract(int x, int y)
 *
 * This function returns the difference between two integers (x and y) - the 
 * result of subtracting y from x.
 *
 * The function checks for integer overflow. If the result of the subtraction of 
 * y from x would exceed the defined range for integers then the value
 * of errno is set to ERANGE and the function returns -1.
 * 
 * It is the responsibility of users of this function to test for errno 
 * correctly and distinguish between the two cases: (1) where -1 is the valid 
 * result of the subtraction of y from x, and (2) when integer overflow would
 * have occurred.
 * See: http://man7.org/linux/man-pages/man3/errno.3.html for information on 
 *
 * Parameters:
 *  x - the integer subtract y from
 *  y - the integer to subtract from x
 * Return:
 *      the result of subtracting y from x
 */
int subtract(int x, int y);

/*
 * int divide(int n, int d)
 *
 * This function returns the result of integer division of the numerator (n) by
 * the denominator (d).
 *
 * The function checks for division by 0. If d is 0 then the function 
 * returns -1 and errno is set to EDOM.
 * There is also one case when the division can cause integer 
 * overflow. In which case, the function returns -1 and errno is set to ERANGE.
 *
 * It is the responsibility of users of this function to test for errno 
 * correctly and distinguish between the two cases: (1) where -1 is the valid 
 * result of the division of n by d, and (2) when division by 0 or 
 * integer overflow would have occurred.
 * See: http://man7.org/linux/man-pages/man3/errno.3.html for information on 
 *
 * Parameters:
 *  n - the numerator of integer division
 *  d - the denominator of integer division
 * Return:
 *      the result of integer division of n by d
 */
int divide(int n, int d);

/*
 * int modulo(int n, int d)
 *
 * This function returns the remainder of integer after division of the 
 * numerator (n) by the denominator (d).
 *
 * The function checks for division by 0. If d is 0 then the function 
 * returns 0 and errno is set to EDOM.
 * There is also one case when the division can cause integer 
 * overflow. In which case, the function returns 0 and errno is set to ERANGE.
 *
 * It is the responsibility of users of this function to test for errno 
 * correctly and distinguish between the two cases: (1) where 0 is the valid 
 * result of n modulo d, and (2) when division by 0 or integer overflow would
 * have occurred.
 * See: http://man7.org/linux/man-pages/man3/errno.3.html for information on 
 *
 * Parameters:
 *  n - the numerator of integer division
 *  d - the denominator of integer division
 * Return:
 *      the remainder after integer division of n by d
 */
int modulo(int n, int d);

/*
 * int division(int n, int d, int *r)
 *
 * This function returns the result of integer division of the numerator (n) by
 * the denominator (d). In addition, it uses r to record the remainder of the
 * division.
 *
 * The function checks for division by 0. If d is 0 then the function 
 * returns -1, errno is set to EDOM and *r will be 0.
 * There is also one case when the division can cause integer 
 * overflow. In which case the function returns -1, errno is set to ERANGE and
 * *r will be 0.
 *
 * It is the responsibility of users of this function to test for errno 
 * correctly and distinguish between the two cases: (1) where -1 is the valid 
 * result of the division of n by d, and (2) when division by 0 or 
 * integer overflow would have occurred.
 * See: http://man7.org/linux/man-pages/man3/errno.3.html for information on 
 *
 * Parameters:
 *  n - the numerator of integer division
 *  d - the denominator of integer division
 *  r - the address of integer to record the remainder after integer division
 *      of n by d
 * Return:
 *      the result ofinteger division of n by d
 */
int division(int n, int d, int *r);

#endif /* _INTMATH_H */
