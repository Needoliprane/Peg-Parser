/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *tmp = NULL;
    int len = 0;
    int i = 0;

    for(; str[len]; len++);
    tmp = malloc(sizeof(char) * len + 1);
    for (; str[i]; i++)
        tmp[i] = str[i];
    tmp[i] = '\0';
    return (tmp);
}