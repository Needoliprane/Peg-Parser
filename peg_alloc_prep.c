/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** peg_alloc_prep
*/

#include <stdlib.h>
#include "parser_peg.h"

int peg_count_recurence(char *str, peg_grammar_t *grammar)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (peg_is_grammar(str[i], grammar) == true && peg_is_grammar(str[i + 1], grammar) == false) {
            count++;
        }
    }
    return (count / 2);
}

char *peg_malloc_part(int size)
{
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL) {
        my_putstr("Error : Malloc of part fail");
        return (NULL);
    }
    for (int i = 0; i <= size; i++)
        str[i] = '\0';
    return (str);
}

peg_grammar_t *peg_set_grammar(char const *synthax_char, char const *allowed_char)
{
    peg_grammar_t *grammar = malloc(sizeof(peg_grammar_t));
    int len_synthax = my_strlen(synthax_char);

    if (grammar == NULL) {
        my_putstr("Error : Malloc of grammar fail");
        return (NULL);
    }
    if (len_synthax < 1) {
        my_putstr("Error : Should have more params for synthax_char");
        return (NULL);
    }
    grammar->allowed_char = my_strdup(allowed_char);
    grammar->synthax_char = my_strdup(synthax_char);
    return (grammar);
}

peg_parser_control_t *peg_alloc(char *str, peg_grammar_t *grammar)
{
    peg_parser_control_t *peg_control = malloc(sizeof(peg_parser_control_t));

    if (peg_control == NULL) {
        my_putstr("Error : Malloc of peg_control fail");
        return (NULL);
    }
    peg_control->deep = peg_count_recurence(str, grammar);
    peg_control->write = 0;
    peg_control->peg = malloc(sizeof(peg_parser_t) * (peg_control->deep + 1));
    if (peg_control->peg == NULL) {
        my_putstr("Error : Malloc of peg fail");
        return (NULL);
    }
    for (int i = 0; i <= peg_control->deep; i++) {
        peg_control->peg[i].part1 = peg_malloc_part(64);
        peg_control->peg[i].part2 = peg_malloc_part(64);
        if (peg_control->peg[i].part1 == NULL || peg_control->peg[i].part2 == NULL)
            return (NULL);
    }
    return (peg_control);
}