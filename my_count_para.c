/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** my_count_para
*/

int count_para(char const *str, char c)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++)
        if (str[i] == c)
            count++;
    return (count);
}