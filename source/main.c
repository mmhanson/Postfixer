/*
 * A simple infix to postfix translator.
 * This is based heavily off of the dragon book's introduction to parsing theory
 * in chapter 2. See wikipedia for the jargon if you don't have a copy.
 * 
 * This is based off of the following context-free grammar:
 *   expr -> term rest
 *   rest -> + term {print('+')} rest
 *         | - term {print('-')} rest
 *         | * term {print('*')} rest
 *         | / term {print('/')} rest
 *         | EMPTY_STRING
 *   term -> 0 {print('0')}
 *         | ...
 *         | 9 {print('9')}
 * Note this means that it can only handle single-digit decimal numbers and
 * addition, subtraction, multiplication, and division.
 *
 * Written by Max Hanson, July 2019.
 * Licensed under MIT, see LICENSE.md for more details.
 */

#include <stdio.h>

/*
 * Translate an infix expression to a postfix expression and print it to stdout.
 *
 * @infix_expr: the infix expression to translate.
 */
void translate(const char *infix_expr);

/*
 * Parse an 'expr' production.
 *
 * @expr: string to parse.
 * @scan_idx: where to start parsing. Pointer so recursive calls can modify.
 */
void parse_expr(const char *expr, int *scan_idx);

/*
 * Parse a 'rest' production.
 *
 * @rest: string to parse.
 * @scan_idx: where to start parsing. Pointer so recursive calls can modify.
 */
void parse_rest(const char *rest, int *scan_idx);

/*
 * Parse a 'term' production.
 *
 * @term: string to parse.
 * @scan_idx: where to start parsing. Pointer so recursive calls can modify.
 */
void parse_term(const char *term, int *scan_idx);


int main(int argc, char *argv[])
{
    const char infix_expr[] = "9*5+2/8-3";

    printf("infix expression: %s \n", infix_expr);
    printf("postfix expression: ");
    translate((const char*)&infix_expr);
    printf("\n");
}

void translate(const char *infix_expr)
{
    // Since 'expr' is the starting nonterminal symbol in the grammar.
    int scan_idx = 0;
    parse_expr(infix_expr, &scan_idx);
}

void parse_expr(const char *expr, int *scan_idx)
{
    // since the 'expr' production consists of a 'term' and the 'rest'
    parse_term(expr, scan_idx);
    parse_rest(expr, scan_idx);
}

void parse_rest(const char *rest, int *scan_idx)
{
    // See the 'rest' production in the grammar up top for clarification.

    char operator = rest[*scan_idx];
    *scan_idx += 1;
    parse_term(rest, scan_idx);
    printf("%c", operator); // print op after two terms have been printed

    // If there is any expression left to parse.
    if (rest[*scan_idx] != 0)
    {
        parse_rest(rest, scan_idx);
    }
}

void parse_term(const char *expr, int *scan_idx)
{
    char lookahead = expr[*scan_idx];
    if (lookahead >= '0' && lookahead <= '9')
    {
        *scan_idx += 1;
        printf("%c", lookahead);
    }
    else
    {
        printf("Syntax error. Expected a digit. \n");
    }
}
