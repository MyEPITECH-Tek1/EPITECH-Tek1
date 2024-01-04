/*
** EPITECH PROJECT, 2023
** load_map.c
** File description:
** Load the maps
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat data;
    char *buff;

    if (fd == -1)
        return NULL;
    stat(filepath, &data);
    buff = malloc(sizeof(char) * (data.st_size + 1));
    read(fd, buff, data.st_size);
    buff[data.st_size] = '\0';
    close(fd);
    return buff;
}

char **load_2d_arr_from_file(char *buffer)
{
    char **arr;
    int nb_rows = 0;
    int nb_cols;
    int pos = 0;

    nb_rows += get_rows(buffer);
    arr = malloc(sizeof(char *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++) {
        nb_cols = 0;
        for (; buffer[pos + nb_cols] != '\n' &&
            buffer[pos + nb_cols] != '\0'; nb_cols++);
        arr[i] = malloc(sizeof(char) * (nb_cols + 1));
        for (int j = 0; j < nb_cols; j++)
            arr[i][j] = buffer[pos + j];
        arr[i][nb_cols] = '\0';
        pos += nb_cols + 1;
    }
    arr[nb_rows] = NULL;
    return arr;
}
