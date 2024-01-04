/*
** EPITECH PROJECT, 2023
** verif_move.c
** File description:
** Check the errors of the boxes' movements of my_sokoban
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int verif_movement_r(player_t *player)
{
    if (player->arr[player->y][player->x + 1] == '#')
        return (0);
    if (player->arr[player->y][player->x + 1] == 'X' &&
        player->arr[player->y][player->x + 2] == '#')
        return (0);
    if (player->arr[player->y][player->x + 1] == 'X' &&
        player->arr[player->y][player->x + 2] == 'X')
        return (0);
    if (player->arr[player->y][player->x + 1] == 'X' &&
        player->arr[player->y][player->x + 2] == ' ')
        move_box_r(player);
    if (player->arr[player->y][player->x + 1] == 'X' &&
        player->arr[player->y][player->x + 2] == 'O')
        move_box_r(player);
    return (1);
}

int verif_movement_l(player_t *player)
{
    if (player->arr[player->y][player->x - 1] == '#')
        return (0);
    if (player->arr[player->y][player->x - 1] == 'X' &&
        player->arr[player->y][player->x - 2] == '#')
        return (0);
    if (player->arr[player->y][player->x - 1] == 'X' &&
        player->arr[player->y][player->x - 2] == 'X')
        return (0);
    if (player->arr[player->y][player->x - 1] == 'X' &&
        player->arr[player->y][player->x - 2] == ' ')
        move_box_l(player);
    if (player->arr[player->y][player->x - 1] == 'X' &&
        player->arr[player->y][player->x - 2] == 'O')
        move_box_l(player);
    return (1);
}

int verif_movement_u(player_t *player)
{
    if (player->arr[player->y - 1][player->x] == '#')
        return (0);
    if (player->arr[player->y - 1][player->x] == 'X' &&
        player->arr[player->y - 2][player->x] == '#')
        return (0);
    if (player->arr[player->y - 1][player->x] == 'X' &&
        player->arr[player->y - 2][player->x] == 'X')
        return (0);
    if (player->arr[player->y - 1][player->x] == 'X' &&
        player->arr[player->y - 2][player->x] == ' ')
        move_box_u(player);
    if (player->arr[player->y - 1][player->x] == 'X' &&
        player->arr[player->y - 2][player->x] == 'O')
        move_box_u(player);
    return (1);
}

int verif_movement_d(player_t *player)
{
    if (player->arr[player->y + 1][player->x] == '#')
        return (0);
    if (player->arr[player->y + 1][player->x] == 'X' &&
        player->arr[player->y + 2][player->x] == '#')
        return (0);
    if (player->arr[player->y + 1][player->x] == 'X' &&
        player->arr[player->y + 2][player->x] == 'X')
        return (0);
    if (player->arr[player->y + 1][player->x] == 'X' &&
        player->arr[player->y + 2][player->x] == ' ')
        move_box_d(player);
    if (player->arr[player->y + 1][player->x] == 'X' &&
        player->arr[player->y + 2][player->x] == '0')
        move_box_d(player);
    return (1);
}
