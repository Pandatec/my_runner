/*
** EPITECH PROJECT, 2019
** inti_struct.c
** File description:
** init_struct.c
*/

#include "../include/struct.h"

void initobstacle(obstacle_t *obs)
{
    obs->scactus = sfSprite_create();
    obs->tcactus = sfTexture_createFromFile("./assets/Cactus.png", NULL);
    obs->scactus1 = sfSprite_create();
    obs->tcactus1 = sfTexture_createFromFile("./assets/Cactus.png", NULL);
    obs->scactus2 = sfSprite_create();
    obs->tcactus2 = sfTexture_createFromFile("./assets/Cactus.png", NULL);
    obs->scactus3 = sfSprite_create();
    obs->tcactus3 = sfTexture_createFromFile("./assets/Cactus.png", NULL);
}

running_t initplayerrun(running_t runner, obstacle_t *obs)
{
    for (int i = 0; i != 7; i++)
        runner.s_run[i] = sfSprite_create();
    runner.t_run[0] = sfTexture_createFromFile("./assets/run/run1.png", NULL);
    runner.t_run[1] = sfTexture_createFromFile("./assets/run/run2.png", NULL);
    runner.t_run[2] = sfTexture_createFromFile("./assets/run/run3.png", NULL);
    runner.t_run[3] = sfTexture_createFromFile("./assets/run/run4.png", NULL);
    runner.t_run[4] = sfTexture_createFromFile("./assets/run/run5.png", NULL);
    runner.t_run[5] = sfTexture_createFromFile("./assets/run/run6.png", NULL);
    runner.t_run[6] = sfTexture_createFromFile("./assets/run/run7.png", NULL);
    for (int i = 0; i != 7; i++)
        sfSprite_setTexture(runner.s_run[i], runner.t_run[i], sfTrue);
    initobstacle(obs);
    return (runner);
}

action_t initplayerjump(action_t pj)
{
    pj.y = 362;
    pj.saut = 1;
    for (int i = 0; i != 6; i++)
        pj.spj[i] = sfSprite_create();
    pj.tpj[0] = sfTexture_createFromFile("./assets/jump/jump1.png", NULL);
    pj.tpj[1] = sfTexture_createFromFile("./assets/jump/jump2.png", NULL);
    pj.tpj[2] = sfTexture_createFromFile("./assets/jump/jump3.png", NULL);
    pj.tpj[3] = sfTexture_createFromFile("./assets/jump/jump4.png", NULL);
    pj.tpj[4] = sfTexture_createFromFile("./assets/jump/jump5.png", NULL);
    pj.tpj[5] = sfTexture_createFromFile("./assets/jump/jump6.png", NULL);
    for (int i = 0; i != 6; i++)
        sfSprite_setTexture(pj.spj[i], pj.tpj[i], sfTrue);
    return (pj);
}

action_t initplayergliss(action_t pg)
{
    pg.secondsg = 0;
    pg.secondsj = 0;
    pg.countj = 0;
    pg.jg = 0;
    pg.booleang = 0;
    pg.clockj = sfClock_create();
    pg.clockg = sfClock_create();
    for (int i = 0; i != 6; i++)
        pg.spg[i] = sfSprite_create();
    pg.tpg[0] = sfTexture_createFromFile("./assets/slide/slide1.png", NULL);
    pg.tpg[1] = sfTexture_createFromFile("./assets/slide/slide2.png", NULL);
    pg.tpg[2] = sfTexture_createFromFile("./assets/slide/slide3.png", NULL);
    pg.tpg[3] = sfTexture_createFromFile("./assets/slide/slide4.png", NULL);
    pg.tpg[4] = sfTexture_createFromFile("./assets/slide/slide5.png", NULL);
    pg.tpg[5] = sfTexture_createFromFile("./assets/slide/slide6.png", NULL);
    for (int i = 0; i != 6; i++)
                sfSprite_setTexture(pg.spg[i], pg.tpg[i], sfTrue);
    pg = initplayerjump(pg);
    return (pg);
}

score_t initvariable(score_t score)
{
    score.i = 0;
    score.j = 0;
    score.k = 0;
    score.start = 1;
    score.boolean = 0;
    score.seconds = 0;
    score.clock = sfClock_create();
    score.posplayer.x = 200;
    score.posplayer.y = 360;
    return (score);
}
