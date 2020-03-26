/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../inc/my.h"

void error_on_tetrimino(void)
{
    DIR *rep = opendir("./tetrimino");
    struct dirent *directo;
    char **tetris = malloc(sizeof(char *) * 4096);
    char *str = malloc(sizeof(char) * 4096);
    int fd;
    int red;
    char *dest = "./tetrimino/";
    char src[1024];
    int cmp = 0;
    int cmp2 = 0;
    int count2 = 0;
    int count = 0;
    char **map = malloc(sizeof(char *) * 4096);

    while ((directo = readdir(rep)) != NULL) {
        if ((directo->d_name[0] != '.')) {
            tetris = my_str_to_word_array(directo->d_name, ".\0\n");
            my_strcpy(src, dest);
            my_strcat(src, directo->d_name);
            fd = open(src, O_RDONLY);
            red = read(fd, str, 4069);
            str[red] = '\0';
            map = my_str_to_word_array(str, " \n");
            cmp = my_getnbr(map[0]);
            for (int i = 6; str[i] != '\n' && str[i] != '\0'; ++i)
                ++count;
            for (int i = 6; str[i] != '\0'; ++i)
                if (str[i] == '\n')
                    ++count2;
            if (cmp != count && cmp != (count-1))
                exit(84);
            if (map[1] != NULL) {
                cmp2 = my_getnbr(map[1]);
                if (cmp2 != count2 && cmp2 != (count2+1))
                    exit(84);
            }
            cmp = 0;
            count = 0;
            cmp2 = 0;
            count2 = 0;
        }
    }
}

void read_tetri(void)
{
    DIR *rep = opendir("./tetrimino");
    char **tetris = malloc(sizeof(char *) * 4096);
    DIR *oth = opendir("./tetrimino");
    int count = 0;
    char *str = malloc(sizeof(char) * 4096);
    int fd;
    int red;
    char *dest = "./tetrimino/";
    char src[1024];
    char **map;
    int i = 6;

    struct dirent  *directo;

    while ((directo = readdir(rep)) != NULL) {
        if ((directo->d_name[0] != '.'))
            ++count;
    }
    printw("Tetriminos : %d\n", count);
    while ((directo = readdir(oth)) != NULL) {
        if ((directo->d_name[0] != '.')) {
            tetris = my_str_to_word_array(directo->d_name, ".\0\n");
            my_strcpy(src, dest);
            my_strcat(src, directo->d_name);
            fd = open(src, O_RDONLY);
            red = read(fd, str, 4069);
            str[red] = '\0';
            map = my_str_to_word_array(str, "\n");
            if (map[1] == NULL)
                printw("Tetriminos : Name : %s : Error\n", tetris[0]);
            else {
                printw("Tetriminos : Name : %s : Size %c*%c : Color %c\n", tetris[0], str[0], str[2], str[4]);
                for (; str[i] != '\0'; ++i)
                    printw("%c", str[i]);
                if (str[i-1] != '\n')
                    printw("\n");
            }
            i = 6;
            src[0] = '\0';
        }
    }
}