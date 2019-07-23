/*
 * A simple infix to postfix translator.
 * This is based heavily off of the dragon book's introduction to parsing theory
 * in chapter 2. See wikipedia for the jargon if you don't have a copy.
 *
 * It can only handle single-digit numbers and addition, subtraction,
 * multiplication, and division.
 * 
 * This is based off of the following context-free grammar:
 *   expr -> term + expr1 | term - expr1 | term
 *   term -> 0 | 1
 * Which is intentionally right-recursive to avoid infinite recursion.
 * And they are implemented with a recursive descent parser.
 * TODO add example syntax tree for '9-5+2'.
 *
 * Written by Max Hanson, July 2019.
 * Licensed under MIT, see LICENSE.md for more details.
 */

#include <stdio.h>

/*
 * Translate an infix expression to a postfix expression and print it to stdout.
 * CAUTION: @postfix_expr must have at least as much capacity as @infix_expr.
 *
 * @infix_expr: the infix expression to translate.
 */
void translate(const char *infix_expr);

void match_expr(const char *expr, int *scan_idx);

void match_term(const char *expr, int *scan_idx);


int main(int argc, char *argv[])
{
    const char infix_expr[] = "9*5+2";
    const char postfix_expr[6]; // exactly as big as infix_expr

    printf("infix expression: %s \n", infix_expr);
    printf("postfix expression: ");
    translate(&(infix_expr[0])); // TODO fix
    printf("\n");
}

void translate(const char *infix_expr)
{
    // Since 'expr' is the starting nonterminal symbol in the grammar.
    // TODO fix bad plumbing
    int scan_idx = 0;
    match_expr(infix_expr, &scan_idx);
}

void match_expr(const char *expr, int *scan_idx)
{
    match_term(expr, scan_idx);

    char operator = expr[*scan_idx]; // get op for later printing
    *scan_idx += 1;

    // print op after two terms have been printed
    printf("%c", operator);

    // If there is any expression left to parse.
    if (expr[*scan_idx] != 0)
    {
        match_expr(expr, scan_idx);
    }
}

void match_term(const char *expr, int *scan_idx)
{
    char lookahead = expr[*scan_idx];
    if (lookahead >= '0' && lookahead <= '9')
    {
        *scan_idx += 1;
        printf("%c", lookahead);
    }
    else
    {
        // TODO report syntax error
        printf("Syntax error. Expected a digit. \n");
    }
}
