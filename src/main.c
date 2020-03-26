/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../inc/my.h"

option_t *assign_default(void)
{
    option_t *option = malloc(sizeof(option_t));

    option->h = 0;
    option->L = 1;
    option->l = 27;
    option->r = 26;
    option->t = 24;
    option->d = 25;
    option->q = 81;
    option->p = 32;
    option->map_size[0] = 20;
    option->map_size[1] = 10;
    option->w = 0;
    option->debug = 0;
}

int main(int ac, char **av)
{
    option_t *option = assign_default();
    check_args(ac, av, option);
    if (option->h == 1)
        return(desc());
    initscr();
    notimeout(stdscr, FALSE);
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    if (option->debug == 1)
        debug_mode(option);
    clear();
    endwin();
    return (0);
}