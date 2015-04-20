#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>


#ifndef FORMAT_H_
#define FORMAT_H_

/***********************
 * Inputs:
 * printhelp is called to print out the usage interface and help description
 * Output: text on screen
 */
void printhelp(void);

/************************
 * Inputs: 
 * inputCheck checks the inputs given to work with for count and validity
 * Outputs: Possible Error print on screen
 */
int inputCheck(char **input);

/************************
 * Inputs: 2 int numbers
 * power computes the first number raised to the second
 * Outputs: unsigned long int holding the result
 */
unsigned long int power(int num1, int num2);

/************************
 * Inputs: 2 double numbers
 * dpower computes the first number raised to the second
 * Outpust: double holding the result
 */
double dpower(double num1, double num2);

/*****************************
 * Inputs: String representation of the number
 * convert returns the double representation of the number given
 * Output: double
 */
double convert(char *binaryString);

/****************************
 * Inputs: int number
 * print prints the decimal representation of the number
 * Output: print to screen
 */
void print(int number);

/****************************
 * Inputs: int number
 * printint flips the number around and prints
 * Output: print to screen
 */
void printint(int number);

/****************************
 * Inputs: float mantissa, int exponent
 * print  prints a number in standard form to the screen.
 * The printing should result to the mantissa * 10^exponent
 * Output: print to screen
 */
void printfloat(double decimal, int exp);

/******************************
 * Inputs: array of binary
 * inverbinary inverts each buckets value from 0 to 1 or 1 to 0.
 * Output:
 */
void invertbinary(int *arr);

/*****************************
 * Inputs: unsigned long int binary
 * complement computes the two's complement value of the input
 * Output: int
 */
int complement(unsigned long int binary);

/*****************************
 * Inputs: array of characters which represent numbers
 * getmantissa retrieves the mantissa with respect to normal IEEE floating point standard single precision
 * Output: double
 */
double getmantissa(char *input);

/******************************
 * Inputs: array of characters which represent numbers
 * getdenmatissa retrieves the mantissa with respect to a denormal IEEE floating point standard single precision
 * Output: double
 */
double getdenmantissa(char *input);

/**************************
 * Inputs: array of characters which represent numbers
 * getexp retrieves the exponent with respect to normal IEEE floating point standard single precision
 * Output: int
 */
int getexp(char *input);

/****************************
 * Inputs: array of characters which represent numbers
 * getsign retrieves the exponent with respect to normal IEEE floating point standard single precision
 * Output: int
 */
int getsign(char *input);

/**************************
 * rounds the number to 20 digits after decimal point
 */
double truncate(double decimal);



#endif /* FORMAT_H_ */
