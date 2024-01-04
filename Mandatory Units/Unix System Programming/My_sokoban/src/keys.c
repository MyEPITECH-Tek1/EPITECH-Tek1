/*
** EPITECH PROJECT, 2023
** keys.c
** File description:
** Keys used to move the player
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void key_up(player_t *player)
{
    if (verif_movement_u(player) == 0)
        return;
    player->arr[player->y][player->x] = ' ';
    --player->y;
    player->arr[player->y][player->x] = 'P';
    display_map(player);
}

void key_down(player_t *player)
{
    if (verif_movement_d(player) == 0)
        return;
    player->arr[player->y][player->x] = ' ';
    ++player->y;
    player->arr[player->y][player->x] = 'P';
    display_map(player);
}

void key_left(player_t *player)
{
    if (verif_movement_l(player) == 0)
        return;
    player->arr[player->y][player->x] = ' ';
    --player->x;
    player->arr[player->y][player->x] = 'P';
    display_map(player);
}

void key_right(player_t *player)
{
    if (verif_movement_r(player) == 0)
        return;
    player->arr[player->y][player->x] = ' ';
    ++player->x;
    player->arr[player->y][player->x] = 'P';
    display_map(player);
}
