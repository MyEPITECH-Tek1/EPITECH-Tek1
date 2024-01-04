/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Header
*/

#pragma once
#include "structure.h"

void my_putstr(char const *str);
int get_rows(char *buffer);
int get_max_cols(char *buffer, int k);
int get_player_position(player_t *player);
char *load_file_in_mem(char const *filepath);
char **load_2d_arr_from_file(char *buffer);
void display_map(player_t *player);
void key_up(player_t *player);
void key_down(player_t *player);
void key_left(player_t *player);
void key_right(player_t *player);
int move_box_r(player_t *player);
int verif_movement_r(player_t *player);
int move_box_l(player_t *player);
int verif_movement_l(player_t *player);
int move_box_u(player_t *player);
int verif_movement_u(player_t *player);
int move_box_d(player_t *player);
int verif_movement_d(player_t *player);
int get_o_position(player_t *player);
void replace_o(player_t *player);
void verif_o(player_t *player);
