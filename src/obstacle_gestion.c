/*
** EPITECH PROJECT, 2019
** obstacle_gestion.c
** File description:
** obstacle_gestion.c
*/

#include "../include/struct.h"

score_t drawobstacle2(score_t score, obstacle_t *obs)
{
    sfSprite_setPosition(obs->scactus, obs->poscactus);
    sfSprite_setTexture(obs->scactus, obs->tcactus, sfTrue);
    sfRenderWindow_drawSprite(score.window, obs->scactus, NULL);
    sfSprite_setPosition(obs->scactus1, obs->poscactus1);
    sfSprite_setTexture(obs->scactus1, obs->tcactus1, sfTrue);
    sfRenderWindow_drawSprite(score.window, obs->scactus1, NULL);
    sfSprite_setPosition(obs->scactus2, obs->poscactus2);
    sfSprite_setTexture(obs->scactus2, obs->tcactus2, sfTrue);
    sfRenderWindow_drawSprite(score.window, obs->scactus2, NULL);
    sfSprite_setPosition(obs->scactus3, obs->poscactus3);
    sfSprite_setTexture(obs->scactus3, obs->tcactus3, sfTrue);
    sfRenderWindow_drawSprite(score.window, obs->scactus3, NULL);
    sfRenderWindow_display(score.window);
    return (score);
}

score_t positioncactus(score_t score, obstacle_t *obs)
{
    float c = 110;

    obs->poscactus.x = (score.xo[0] * c);
    obs->poscactus.y = (score.yo[0] * c);
    obs->poscactus1.x = (score.xo[1] * c);
    obs->poscactus1.y = (score.yo[1] * c);
    obs->poscactus2.x = (score.xo[2] * c);
    obs->poscactus2.y = (score.yo[2] * c);
    obs->poscactus3.x = (score.xo[3] * c);
    obs->poscactus3.y = (score.yo[3] * c);
    return (score);
}

int ifobstacle(obstacle_t *obs, action_t pg, score_t score)
{
    int saut = 0;

    if (obs->poscactus.x < 180 && obs->poscactus.x > 150) {
        if (pg.y < 220)
            saut = 1;
        else
            saut = 2;
    }
    if (obs->poscactus1.x < 180 && obs->poscactus1.x > 150) {
        if (pg.y < 220)
            saut = 1;
        else
            saut = 2;
    }
    if (obs->poscactus2.x < 180 && obs->poscactus2.x > 150) {
        if (pg.y < 220)
            saut = 1;
        else
            saut = 2;
    }
    if (obs->poscactus3.x < 180 && obs->poscactus3.x > 150) {
        if (pg.y < 220)
            saut = 1;
        else
            saut = 2;
    }
    if (saut == 2) {
        sfRenderWindow_close(score.window);
        return (0);
    }
}

score_t drawobstacle(score_t score, obstacle_t *obs, action_t pg)
{
    score = positioncactus(score, obs);
    score.xo[0] = score.xo[0] - 0.01;
    score.xo[1] = score.xo[1] - 0.01;
    score.xo[2] = score.xo[2] - 0.01;
    score.xo[3] = score.xo[3] - 0.01;
    score = drawobstacle2(score, obs);
    ifobstacle(obs, pg, score);
    return (score);
}

score_t analyseobstacle(char c, float i, float j, score_t *score)
{
    static int nbo = 0;

    if (c == '2') {
        score->xo[nbo] = i;
        score->yo[nbo] = j;
        nbo += 2;
    }
    return (*score);
}
