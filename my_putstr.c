/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
    write(1, "\n", 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}