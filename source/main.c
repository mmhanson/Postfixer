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

/*
 * Translate an infix expression to a postfix expression.
 * CAUTION: @postfix_expr must have at least as much capacity as @infix_expr.
 *
 * @infix_expr: the infix expression to translate.
 * @postfix_expr: points to storage for the translated postfix expression.
 */
void translate(char *infix_expr, char *postfix_expr);


int main(int argc, char *argv[])
{
    const char[] infix_expr = "9+5-3";
    const char[6] postfix_expr; // exactly as big as infix_expr
    translate(&infix_expr, &postfix_expr);

    printf("infix expression: %s \n", infix_expr);
    printf("postfix expression: %s \n", postfix_expr);
}

void translate(char *infix_expr, char *postfix_expr)
{
    // TODO
}
