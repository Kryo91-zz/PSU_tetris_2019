/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** n-curse.c
*/

#include "../inc/my.h"

WINDOW *create_new_board(int height, int width, int start_y, int start_x)
{
    WINDOW	*win;

    if (!(win = newwin(height, width, start_y, start_x)))
        return (NULL);
    wborder(win, '|', '|', '-', '-', '-', '-', '-', '-');
    return (win);
}

int create_all_win(window_t *win)
{
    if (!(win->title = create_new_board(6, 30, 0, 0)) ||
(!(win->score = create_new_board(10, 25, 8, 4))) ||
(!(win->board = create_new_board(50, 50, 1, 32))) ||
(!(win->next = create_new_board(10 , 10, 1 ,90))))
        return (1);
    return (0);
}

void display_interface(window_t *win)
{
    wrefresh(win->title);
    wrefresh(win->score);
    wrefresh(win->board);
    wrefresh(win->next);
}

int curse(option_t *option, window_t *win)
{
    init_curse();
    if (create_all_win(win) == 1)
        return (84);
    while (1) {
        display_interface(win);
    }
    endwin();
    return(0);
}