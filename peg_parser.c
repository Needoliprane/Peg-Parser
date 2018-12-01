/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** peg
*/

#include <stdlib.h>
#include <stdbool.h>
#include "parser_peg.h"

void peg_parser_part(peg_grammar_t * grammar, peg_parser_control_t *control_peg, char *str, int i)
{
    if (peg_is_allowed_char(str[i], grammar) == true && control_peg->bol == true) {
        control_peg->peg[control_peg->state].part2[control_peg->write] = str[i];
        control_peg->write++;
        (peg_is_grammar(str[i + 1], grammar) == true) ? (control_peg->bol = false) : (control_peg->bol = true);
    }
    else if (peg_is_allowed_char(str[i], grammar) == true && control_peg->bol == false) {
        control_peg->peg[control_peg->state].part1[control_peg->write] = str[i];
        control_peg->write++;
        (peg_is_grammar(str[i + 1], grammar) == true) ? (control_peg->bol = true) : (control_peg->bol = false);
    }
}

void peg_parser(peg_grammar_t *grammar, peg_parser_control_t *control_peg, char *str)
{
    control_peg->bol = false;
    control_peg->state = 0;

    for (int i = 0, count = 0; str[i]; i++) {
        if (peg_is_grammar(str[i], grammar) == true) {
            count++;
            (count % 2 == 0) ? control_peg->state++, control_peg->write = 0 : (control_peg->write = 0);
            control_peg->peg[control_peg->state].char_grammar = str[i];
        }
        else {
            peg_parser_part(grammar, control_peg, str, i);
        }
    }
}

int main(int ac, char **argv)
{
    peg_grammar_t *grammar = peg_set_grammar("+-*/", "0123456789");
    peg_parser_control_t *peg_control = NULL;

    if (grammar == NULL || ac != 2)
        return (84);
    peg_control = peg_alloc(argv[1], grammar);
    if (peg_control == NULL)
        return (84);
    peg_parser(grammar, peg_control, argv[1]);
    peg_print(peg_control);
    peg_destroy(grammar, peg_control);
    return (0);
}