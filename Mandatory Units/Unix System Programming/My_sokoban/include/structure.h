/*
** EPITECH PROJECT, 2023
** structure.h
** File description:
** Structure of the Setting Up project
*/

#pragma once

typedef struct pos_o_s {
    int x;
    int y;
} pos_o_t;

typedef struct pos_x_s {
    int x;
    int y;
} pos_x_t;

typedef struct player_s {
    int x;
    int y;
    char **arr;
    int nb_rows;
    int nb_cols;
    pos_o_t *o_pos;
    pos_x_t *x_pos;
} player_t;
