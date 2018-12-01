/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** peg_parser_tool
*/

#include "parser_peg.h"

void peg_print(peg_parser_control_t *control_peg)
{
    for (int i = 0; i <= control_peg->deep; i++) {
        my_putstr(control_peg->peg[i].part1);
        my_putchar(control_peg->peg[i].char_grammar);
        my_putchar('\n');
        my_putstr(control_peg->peg[i].part2);
    }
}

bool peg_is_grammar(char stri, peg_grammar_t *grammar)
{
    for (int i = 0; grammar->synthax_char[i]; i++) {
        if (stri == grammar->synthax_char[i])
            return (true);
    }
    return (false);
}

bool peg_is_allowed_char(char stri, peg_grammar_t *grammar)
{
    for (int i = 0; grammar->allowed_char[i]; i++) {
        if (stri == grammar->allowed_char[i])
            return (true);
    }
    return (false);
}