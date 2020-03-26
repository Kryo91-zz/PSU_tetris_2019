/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../inc/my.h"

void init_curse()
{
    initscr();
    notimeout(stdscr, FALSE);
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    curs_set(0);
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_GREEN, -1);
	init_pair(3, COLOR_YELLOW, -1);
	init_pair(4, COLOR_BLUE, -1);
	init_pair(5, COLOR_MAGENTA, -1);
	init_pair(6, COLOR_CYAN, -1);
    refresh();
}

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
    window_t *window = malloc(sizeof(window_t));
    check_args(ac, av, option);
    if (option->h == 1)
        return(desc());
    if (option->debug == 1)
        debug_mode(option);
    return (curse(option, window));
}