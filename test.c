#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // char *src = ",";
    // char *str = " Je suis, un kiwi, qui parle, le francais";
    // char **tab = malloc(sizeof(char *) * 4096);
    // int j = 0;
    // int k = 0;
    // tab[0] = malloc(sizeof(char) * 4096);

    // for (int i = 0; str[i] != '\0';) {
    //     if (str[i] == src[0]) {
    //         tab[j][k] = '\0';
    //         ++j;
    //         ++i;
    //         tab[j] = malloc(sizeof(char) * 4096);
    //         k = 0;
    //     } else {
    //         // printf("[%d] = [%c]\n", i, str[i]);
    //         // printf("tab[%d][%d]\n", j, k);
    //         tab[j][k] = str[i];
    //         ++i;
    //         // printf("tab[%c]\n", tab[j][k]);
    //         ++k;
    //     }
    // }
    // tab[j+1] = NULL;
    // for (int i = 0; tab[i] != NULL; ++i)
    //     printf("%s\n", tab[i]);

    char *str = "couocu pd";
    int i = 452;
    my_printf("%s\n%d\n", str, i);
}