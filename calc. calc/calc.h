#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#ifndef CALC_H_
#define CALC_H_

/*****************************
 * linked list structure which holds the large numbers
 */
struct node{
    struct node *next;
    struct node *prev;
    unsigned num;
};


/****************************
 * Inputs: character which represents a number in either decimal, binary, hex or octal.
 * valueOf looks at the character and returns an int equivalent to the input character in int form
 * Output: int
 */
int valueOf(char current);


/*****************************
 * Inputs: linked list which represents a large number
 * makePositive changes the sign of the number by adding a negative sign to the
 * beggining of the list or removing one. In this implementation the negative sign is held
 * as a zero
 * Outpus: resulting list with negated sign
 */
struct node* makePostitive(struct node *number);


/*****************************
 * Inputs: String representation of the number
 * convert returns the linked list representation of the number given
 * Output: linked list representation of the number
 */
struct node* convert(char *numberString);


/******************************
 * Inputs: 2 numbers in linked list form
 * add performs an addition of the two given numbers. The result is put into another linked list
 * Output: linked list representation of the sum of the two inputs
 */
struct node* add(struct node *number1, struct node *number2);


/*******************************
 * Inputs: 2 numbers in linked list form
 * subtract performs a subtraction between the two given numbers, subtracting the second from the first.
 * Output: linked list representation of the difference between the first and second input.
 */
struct node* subtract(struct node *number1, struct node *number2);


/*******************************
 * Inputs: 2 numbers in linked list form
 * quicksum is used when the output is guaranteed to be equal to or less than 32 bits. This returns the sum of
 * the two given inputs which would each be one single node.
 * The result will also be guaranteed to be held in 32 bits or less.
 * Output: Node of linked list representation of a number.
 */
struct node* quicksum(struct node *number1, struct node *number2);


/********************************
 * Inputs; 2 numebrs in linked list form
 * quicksub is used when the output is guaranteed to be equal to or less than 32 bits. This returns the difference
 * between the first and second numbers which would each be in one single node.
 * The result will also be guaranteed to be held in 32 bits or less.
 * Output: Node of lniked list representation of a number
 */
struct node* quicksub(struct node *number1, struct node *number2);





#endif /* CALC_H_ */
