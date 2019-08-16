/*
** EPITECH PROJECT, 2019
** jump_gestion.c
** File description:
** jump_gestion.c
*/

#include "../include/struct.h"

score_t anim5(score_t score, action_t *pg, sfVector2f *ppj)
{
    pg->timej = sfClock_getElapsedTime(pg->clockj);
    pg->secondsj = pg->timej.microseconds / 1000000.0;
    if (pg->secondsj > 0.06) {
        pg->countj = pg->countj + 1;
        if (pg->countj == 12)
            pg->countj = 0;
        sfClock_restart(pg->clockj);
    }
    sfSprite_setPosition(pg->spj[pg->countj], *ppj);
    sfRenderWindow_drawSprite(score.window, pg->spj[pg->countj], NULL);
    return (score);
}

score_t anim4(score_t score, action_t *pg, sfVector2f *ppj)
{
    if ((pg->y == 209 && pg->saut == 4) ||
        (pg->saut == 5 && pg->y < 362)) {
        pg->saut = 5;
        pg->y = pg->y + 1.4;
        ppj->y = pg->y;
    }
    if (pg->y > 362 && pg->saut == 5) {
        pg->saut = 1;
        score.boolean = 0;
        pg->jg = 0;
        pg->booleang = 0;
        pg->y = 362;
        pg->countj = 0;
    }
    score = anim5(score, pg, ppj);
    return (score);
}

score_t anim3(score_t score, action_t *pg, sfVector2f *ppj)
{
    if ((pg->y == 180 || pg->saut == 4) && pg->y < 209) {
        pg->saut = 4;
        pg->y = pg->y + 0.5;
        ppj->y = pg->y;
    }
    score = anim4(score, pg, ppj);
    return (score);
}

score_t anim2(score_t score, action_t *pg, sfVector2f *ppj)
{
    if (score.boolean == 2) {
        if (pg->y > 250 && pg->saut == 1) {
            pg->y = pg->y - 3;
            ppj->y = pg->y;
        } else if ((pg->y == 248 || pg->saut == 2) &&
            pg->y > 210 && pg->saut != 5) {
            pg->saut = 2;
            pg->y = pg->y - 1;
            ppj->y = pg->y;
        } else if ((pg->y == 210 || pg->saut == 3) &&
            pg->y > 180 && pg->saut != 5) {
            pg->saut = 3;
            pg->y = pg->y - 0.5;
            ppj->y = pg->y;
        }
        score = anim3(score, pg, ppj);
    }
    return (score);
}

score_t anim1(score_t score, action_t *pg, running_t runner)
{
    sfVector2f ppg = {0, 0};
    sfVector2f ppj = {0, pg->y};

    if (score.boolean == 0)
        score = drawplayer(score, runner);
    if (score.boolean == 1) {
        pg->timeg = sfClock_getElapsedTime(pg->clockg);
        pg->secondsg = pg->timeg.microseconds / 1000000.0;
        if (pg->secondsg > 0.06) {
            if (pg->jg != 3)
                pg->jg = pg->jg + 1;
            else {
                pg->jg = 0;
                pg->booleang = pg->booleang + 1;;
            }
            if (pg->booleang == 2 && pg->jg == 3) {
                pg->jg = 0;
                score.boolean = 0;
                pg->booleang = 0;
                pg->y = 362;
                pg->saut = 1;
            }
            sfClock_restart(pg->clockg);
        }
        sfSprite_setPosition(pg->spg[pg->jg], ppg);
        sfRenderWindow_drawSprite(score.window, pg->spg[pg->jg], NULL);
    }
    score = anim2(score, pg, &ppj);
    return (score);
}
