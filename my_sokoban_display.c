/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_display
*/

#include "my.h"

int left_main_check_last_pos(char **map_2d, struct position *pos,
struct number *num)
{
    for (int i = 0; i < num->numberZeroConst; i++) {
        if (pos->answery[i] == pos->rows &&
            pos->answerx[i] == pos->columns - 1) {
            num->numberZero++;
            map_2d[pos->rows][pos->columns - 1] = 'O';
            map_2d[pos->rows][pos->columns - 2] = 'X';
            pos->columns--;
            num->numberCase -= check_moves_left(map_2d, pos);
            return (0);
        }
    }
    map_2d[pos->rows][pos->columns - 1] = ' ';
    map_2d[pos->rows][pos->columns - 2] = 'X';
    pos->columns--;
    num->numberCase -= check_moves_left(map_2d, pos);
    return (0);
}

int right_main_check_last_pos(char **map_2d, struct position *pos,
struct number *num)
{
    for (int i = 0; i < num->numberZeroConst; i++) {
        if (pos->answery[i] == pos->rows &&
            pos->answerx[i] == pos->columns + 1) {
            num->numberZero++;
            map_2d[pos->rows][pos->columns + 1] = 'O';
            map_2d[pos->rows][pos->columns + 2] = 'X';
            pos->columns++;
            num->numberCase -= check_moves_right(map_2d, pos);
            return (0);
        }
    }
    map_2d[pos->rows][pos->columns + 1] = ' ';
    map_2d[pos->rows][pos->columns + 2] = 'X';
    pos->columns++;
    num->numberCase -= check_moves_right(map_2d, pos);
    return (0);
}

int up_main_check_last_pos(char **map_2d, struct position *pos,
struct number *num)
{
    for (int i = 0; i < num->numberZeroConst; i++) {
        if (pos->answery[i] == pos->rows - 1 &&
            pos->answerx[i] == pos->columns) {
            num->numberZero++;
            map_2d[pos->rows - 1][pos->columns] = 'O';
            map_2d[pos->rows - 2][pos->columns] = 'X';
            pos->rows--;
            num->numberCase -= check_moves_up(map_2d, pos);
            return (0);
        }
    }
    map_2d[pos->rows - 1][pos->columns] = ' ';
    map_2d[pos->rows - 2][pos->columns] = 'X';
    pos->rows--;
    num->numberCase -= check_moves_up(map_2d, pos);
    return (0);
}

int down_main_check_last_pos(char **map_2d, struct position *pos,
struct number *num)
{
    for (int i = 0; i < num->numberZeroConst; i++) {
        if (pos->answery[i] == pos->rows + 1 &&
            pos->answerx[i] == pos->columns) {
            num->numberZero++;
            map_2d[pos->rows + 1][pos->columns] = 'O';
            map_2d[pos->rows + 2][pos->columns] = 'X';
            pos->rows++;
            num->numberCase -= check_moves_down(map_2d, pos);
            return (0);
        }
    }
    map_2d[pos->rows + 1][pos->columns] = ' ';
    map_2d[pos->rows + 2][pos->columns] = 'X';
    pos->rows++;
    num->numberCase -= check_moves_down(map_2d, pos);
    return (0);
}