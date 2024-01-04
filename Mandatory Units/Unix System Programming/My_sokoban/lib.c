/*
** EPITECH PROJECT, 2023
** lib.c
** File description:
** Functions needed for the my_sokoban
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
}
