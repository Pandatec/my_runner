/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct.h
*/

#ifndef MY_STRUCT_
#define MY_STRUCT_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct struct_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vector;
    sfIntRect rect;
} struct_t;

typedef struct running_s {
    sfSprite *s_run[7];
    sfTexture *t_run[7];
    sfVector2f vect_r;
} running_t;

typedef struct action_s {
    sfSprite *spg[6];
    sfTexture *tpg[6];
    sfTime timeg;
    sfClock *clockg;
    float secondsg;
    sfTime timej;
    sfClock *clockj;
    float secondsj;
    int countj;
    float y;
    int saut;
    int jg;
    int booleang;
    sfSprite *spj[6];
    sfTexture *tpj[6];
} action_t;

typedef struct score_s {
    int i;
    int j;
    int k;
    int start;
    int boolean;
    float seconds;
    sfRenderWindow *window;
    sfTime time;
    sfClock *clock;
    sfVector2f posplayer;
    sfEvent event;
    float xo[5];
    float yo[5];
    sfSprite *bgmenu;
    sfTexture *tmenu;
} score_t;

typedef struct obstacle_s {
    sfSprite *scactus;
    sfTexture *tcactus;
    sfSprite *scactus1;
    sfTexture *tcactus1;
    sfSprite *scactus2;
    sfTexture *tcactus2;
    sfSprite *scactus3;
    sfTexture *tcactus3;
    sfVector2f poscactus;
    sfVector2f poscactus1;
    sfVector2f poscactus2;
    sfVector2f poscactus3;
    sfFont *font;
    sfText *text;
} obstacle_t;

running_t initplayerrun(running_t , obstacle_t *);
action_t initplayerjump(action_t);
action_t initplayergliss(action_t);
score_t initvariable(score_t);
obstacle_t score(score_t, obstacle_t);
score_t menu(score_t);
score_t eventfunction2(score_t, struct_t **, running_t, action_t *);
score_t eventfunction(score_t, struct_t **, running_t, action_t *);
struct_t *create_object(const char *, sfVector2f, sfIntRect);
struct_t **tab(void);
void parallax(struct_t **);
void move(sfIntRect *, float, int);
score_t anim1(score_t, action_t *, running_t);
score_t drawplayer(score_t, running_t);
score_t analyseobstacle(char, float, float, score_t *);
score_t drawobstacle(score_t, obstacle_t *, action_t);
score_t drawobstacle2(score_t, obstacle_t *);
score_t map_reader(score_t, char *);
score_t map2char(char *, int, int, score_t);
char *readfile(char *);

#endif
