/*
** EPITECH PROJECT, 2023
** pos_o.c
** File description:
** Position of the 'O'
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int get_o_position_bis(player_t *player, int i, int j, int nb_o)
{
    if (player->arr[i][j] == 'O') {
        player->o_pos[nb_o].x = j;
        player->o_pos[nb_o].y = i;
        nb_o++;
    }
    return nb_o;
}

int get_o_position(player_t *player)
{
    int nb_o = 0;

    player->o_pos = malloc(sizeof(pos_o_t) * 100);
    if (player->o_pos == NULL) {
        return -1;
    }
    for (int i = 0; player->arr[i]; i++) {
        for (int j = 0; player->arr[i][j] && player->arr[i][j] != '\0'; j++) {
            nb_o = get_o_position_bis(player, i, j, nb_o);
        }
    }
    player->o_pos[nb_o].x = -1;
    player->o_pos[nb_o].y = -1;
    return (nb_o);
}

void replace_o(player_t *player)
{
    for (int i = 0; player->o_pos[i].x != -1; i++) {
        if (player->arr[player->o_pos[i].y][player->o_pos[i].x] == ' ') {
            player->arr[player->o_pos[i].y][player->o_pos[i].x] = 'O';
        }
    }
}
