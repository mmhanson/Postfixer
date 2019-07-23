/*
 * A simple infix to postfix translator.
 * This is based heavily off of the dragon book's introduction to parsing theory
 * in chapter 2. See wikipedia for the jargon if you don't have a copy.
 *
 * Right now it can only handle binary digits (0 & 1) and addition/subtraction
 * (+ & -).
 * TODO add support for deicmal digits and multiplication/division.
 * 
 * This is based off of the following context-free grammar:
 *   expr -> term + expr1 | term - expr1 | term
 *   term -> 0 | 1
 * And they are implemented with a recursive descent parser.
 * TODO add example syntax tree for '9-5+3'.
 *
 * Written by Max Hanson, July 2019.
 * Licensed under MIT, see LICENSE.md for more details.
 */

#include <stdio.h>


int main(int argc, char *argv[])
{
    // TODO
}
