/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** peg_destroy
*/

#include <stdlib.h>
#include "parser_peg.h"

void peg_destroy(peg_grammar_t *grammar, peg_parser_control_t *peg_control)
{
    free(grammar->allowed_char);
    free(grammar->synthax_char);
    free(grammar);
    for (int i = 0; i <= peg_control->deep; i++) {
        free(peg_control->peg[i].part1);
        free(peg_control->peg[i].part2);
    }
    free(peg_control->peg);
    free(peg_control);
}