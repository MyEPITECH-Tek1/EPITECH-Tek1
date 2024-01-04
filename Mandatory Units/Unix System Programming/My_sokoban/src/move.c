/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** Movements of the boxes for my_sokoban
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int move_box_r(player_t *player)
{
    if (player->arr[player->y][player->x + 1] == 'X' &&
        player->arr[player->y][player->x + 2] == ' ') {
        player->arr[player->y][player->x + 2] = 'X';
        player->arr[player->y][player->x + 1] = 'P';
        player->arr[player->y][player->x] = ' ';
        return (0);
    }
    if (player->arr[player->y][player->x + 1] == 'X' &&
        player->arr[player->y][player->x + 2] == 'O') {
        player->arr[player->y][player->x + 2] = 'X';
        player->arr[player->y][player->x + 1] = 'P';
        player->arr[player->y][player->x] = ' ';
        return (0);
    }
    return (1);
}

int move_box_u(player_t *player)
{
    if (player->arr[player->y - 1][player->x] == 'X' &&
        player->arr[player->y - 2][player->x] == ' ') {
        player->arr[player->y - 2][player->x] = 'X';
        player->arr[player->y - 1][player->x] = 'P';
        player->arr[player->y][player->x] = ' ';
        return (0);
    }
    if (player->arr[player->y - 1][player->x] == 'X' &&
        player->arr[player->y - 2][player->x] == 'O') {
        player->arr[player->y - 2][player->x] = 'X';
        player->arr[player->y - 1][player->x] = 'P';
        player->arr[player->y][player->x] = ' ';
        return (0);
    }
    return (1);
}

int move_box_l(player_t *player)
{
    if (player->arr[player->y][player->x - 1] == 'X' &&
        player->arr[player->y][player->x - 2] == ' ') {
        player->arr[player->y][player->x - 2] = 'X';
        player->arr[player->y][player->x - 1] = 'P';
        player->arr[player->y][player->x] = ' ';
        return (0);
    }
    if (player->arr[player->y][player->x - 1] == 'X' &&
        player->arr[player->y][player->x - 2] == 'O') {
        player->arr[player->y][player->x - 2] = 'X';
        player->arr[player->y][player->x - 1] = 'P';
        player->arr[player->y][player->x] = ' ';
        return (0);
    }
    return (1);
}

int move_box_d(player_t *player)
{
    if (player->arr[player->y + 1][player->x] == 'X' &&
        player->arr[player->y + 2][player->x] == ' ') {
        player->arr[player->y + 2][player->x] = 'X';
        player->arr[player->y + 1][player->x] = 'P';
        player->arr[player->y][player->x] = ' ';
        return (0);
    }
    if (player->arr[player->y + 1][player->x] == 'X' &&
        player->arr[player->y + 2][player->x] == 'O') {
        player->arr[player->y + 2][player->x] = 'X';
        player->arr[player->y + 1][player->x] = 'P';
        player->arr[player->y][player->x] = ' ';
        return (0);
    }
    return (1);
}
