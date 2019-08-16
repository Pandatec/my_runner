/*
** EPITECH PROJECT, 2019
** readmap.c
** File description:
** readmap.c
*/

#include "../include/struct.h"

char *readfile(char *path)
{
    char *file = NULL;
    struct stat buf;
    int fd;
    int ret = 0;

    stat(path, &buf);
    file = malloc(sizeof(char) * (buf.st_size + 1));
    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    ret = read(fd, file, buf.st_size);
    if (ret == -1)
        return (NULL);
    file[ret] = '\0';
    close(fd);
    return (file);
}

score_t map2char_bis(char **map2, int nbLin, int nbCol, score_t score)
{
    float x = 0;
    float y = 0;
    int i = 0;

    for (int j = 0; j != nbLin;) {
        analyseobstacle(map2[j][i], x, y, &score);
        if (i != nbCol) {
            x += 1;
        } else if (i == nbCol) {
            i = 0;
            x = 0;
            j += 1;
            y += 1;
        }
    }
    free(map2);
    return (score);
}

score_t map2char(char *map, int nbLin, int nbCol, score_t score)
{
    char **map2 = malloc(sizeof(char*) * nbLin);
    char *map1 = malloc(sizeof(char) * nbCol * nbLin);
    int a = 0;
    int i = 0;
    int j = 0;

    for (i = 0 ; i < nbLin ; i++)
        map2[i] = &map1[i * nbCol];
    for (j = 0; j != nbLin; i += 1) {
        if (map[i] != '\n') {
            map2[j][a] = map[i];
            a += 1;
        } else if (map[i] == '\n') {
            a = 0;
            j += 1;
        }
    }
    map2char_bis(map2, nbLin, nbCol, score);
    free(map1);
    return (score);
}

score_t map_reader(score_t score, char *file)
{
    int nbLin = 9;
    int nbCol = 39;
    char *map = readfile(file);

    //score = map2char(map, nbLin, nbCol, score);
    return (score);
}
