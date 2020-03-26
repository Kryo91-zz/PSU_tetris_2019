/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug.c
*/

#include "../inc/my.h"

char **check_chars(char **opts, option_t *option)
{
    char options[6] = {option->l, option->r, option->t, option->d\
, option->q, option->p};
    for (int i = 0; i < 6; i += 1) {
        if (options[i] < 90 && options[i] > 65)
            options[i] += 32;
        opts[i] = malloc(sizeof(char) * 4096);
        opts[i][0] = options[i];
        if (options[i] == ' ')
            opts[i] = "(space)";
        if (options[i] == 24)
            opts[i] = "^EOB";
        if (options[i] == 27)
            opts[i] = "^EOD";
        if (options[i] == 25)
            opts[i] = "^EOA";
        if (options[i] == 26)
            opts[i] = "^EOC";
    }
    return (opts);
}

void debug_mode(option_t *option)
{
    char *next = "Yes";
    char **opts = malloc(sizeof(char *) * 7);
    char buf = 0;

    opts = check_chars(opts, option);
    if (option->w == 1)
        next = "No";
    printw("*** DEBUG MODE ***\n");
    printw("Key Left :  %s\n", opts[0]);
    printw("Key Right :  %s\n", opts[1]);
    printw("Key Turn :  %s\n", opts[2]);
    printw("Key Drop :  %s\n", opts[3]);
    printw("Key Quit :  %s\n", opts[4]);
    printw("Key Pause :  %s\n", opts[5]);
    printw("Next :  %s\n", next);
    printw("Level :  %d\n", option->L);
    printw("Size :  %d*%d\n", option->map_size[0], option->map_size[1]);
    read_tetri();
    error_on_tetrimino();
    printw("Press any key to start Tetris");
    while(buf == 0)
        buf = getch();
}