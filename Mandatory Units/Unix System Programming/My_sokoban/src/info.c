/*
** EPITECH PROJECT, 2023
** info.c
** File description:
** Getting infos for the my_sokoban
*/

#include <ncurses.h>
#include "../include/my.h"
#include "../include/structure.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int get_rows(char *buffer)
{
    int j = 0;
    int nb_rows = 0;

    for (; buffer[j] && buffer[j] != '\0'; j++) {
        if (buffer[j] == '\n')
            nb_rows++;
    }
    return nb_rows + 1;
}

int get_max_cols(char *buffer, int k)
{
    int nb_cols = 0;

    for (; buffer[k] != '\n' && buffer[k] != '\0'; k++)
        nb_cols++;
    return nb_cols;
}

static void get_player_position_bis(player_t *player, int i, int j)
{
    if (player->arr[i][j] == 'P') {
        player->x = j;
        player->y = i;
    }
}

int get_player_position(player_t *player)
{
    for (int i = 0; player->arr[i]; i++)
        for (int j = 0; player->arr[i][j] && player->arr[i][j] != '\0'; j++)
            get_player_position_bis(player, i, j);
    return (0);
}
