/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** Main of the my_sokoban
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void usage(int ac, char **av)
{
    ac = ac;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("     ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("     map file representing the warehouse map, containing");
        my_putstr(" '#' for walls,\n");
        my_putstr("         'P' for the player, 'X' for boxes and 'O' for");
        my_putstr(" storage locations.\n");
    }
}

void display_map(player_t *player)
{
    refresh();
    clear();
    replace_o(player);
    for (int i = 0; player->arr[i] != NULL; i++) {
        printw("%s", player->arr[i]);
        printw("\n");
    }
}

static void main_bis(player_t *player, int key)
{
    while (1) {
        key = getch();
        if (key == KEY_UP)
            key_up(player);
        if (key == KEY_DOWN)
            key_down(player);
        if (key == KEY_LEFT)
            key_left(player);
        if (key == KEY_RIGHT)
            key_right(player);
        if (key == 36)
            break;
    }
}

static void is_file_valid(char *buffer)
{
    int nb_p = 0;
    int nb_o = 0;
    int nb_x = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'P')
            nb_p++;
        if (buffer[i] == 'O')
            nb_o++;
        if (buffer[i] == 'X')
            nb_x++;
        if (buffer[i] != 'P' && buffer[i] != 'O' && buffer[i] != 'X'
            && buffer[i] != '#' && buffer[i] != ' ' && buffer[i] != '\n')
            exit(84);
    }
    if (nb_p != 1 || nb_o < 1 || nb_x < 1 || nb_o != nb_x) {
        exit(84);
        endwin();
    }
}

static int is_arg_valid(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;

    if (fd == -1) {
        exit(84);
        endwin();
    }
    stat(filepath, &st);
    if (st.st_size == 0) {
        endwin();
        exit(84);
    }
    close(fd);
    return 0;
}

static void free_all(char *buffer, player_t *player)
{
    free(buffer);
    for (int i = 0; player->arr[i] != NULL; i++)
        free(player->arr[i]);
    free(player->arr);
}

static void get_pos_all(player_t *player)
{
    get_player_position(player);
    get_o_position(player);
}

static void check_validity(int ac, char **av, char *buffer)
{
    ac = ac;
    is_arg_valid(av[1]);
    is_file_valid(buffer);
}

int main(int ac, char **av)
{
    char *buffer;
    player_t *player = malloc(sizeof(player_t));
    int key = 0;

    if (ac != 2)
        return 84;
    usage(ac, av);
    buffer = load_file_in_mem(av[1]);
    check_validity(ac, av, buffer);
    player->arr = load_2d_arr_from_file(buffer);
    get_pos_all(player);
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    display_map(player);
    main_bis(player, key);
    endwin();
    free_all(buffer, player);
    free(player);
    return 0;
}
