/*
** EPITECH PROJECT, 2019
** my_runner.c
** File description:
** my_runner.c
*/

#include "../include/struct.h"

void move(sfIntRect *rect, float offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left > max_value)
        rect->left = 0;
}

score_t drawplayer(score_t score, running_t runner)
{
    score.time = sfClock_getElapsedTime(score.clock);
    score.seconds = score.time.microseconds / 1000000.0;
    if (score.seconds > 0.06) {
        if (score.j != 8)
            score.j = score.j + 1;
        else
            score.j = 0;
        sfClock_restart(score.clock);
    }
    sfSprite_setPosition(runner.s_run[score.j], score.posplayer);
    sfRenderWindow_drawSprite(score.window, runner.s_run[score.j], NULL);
    return (score);
}

score_t menu(score_t score)
{
    score.bgmenu = sfSprite_create();
    score.tmenu = sfTexture_createFromFile("./assets/Desert.png", NULL);
    sfSprite_setTexture(score.bgmenu, score.tmenu, sfTrue);
    sfRenderWindow_drawSprite(score.window, score.bgmenu, NULL);
    return (score);
}

void destroy(score_t score, running_t runner, action_t pg, obstacle_t obs)
{
    for (int i = 0; i != 9; i++) {
        sfSprite_destroy(runner.s_run[i]);
        sfTexture_destroy(runner.t_run[i]);
    }
    for (int i = 0; i != 4; i++) {
        sfSprite_destroy(pg.spg[i]);
        sfTexture_destroy(pg.tpg[i]);
    }
    for (int i = 0; i != 12; i++) {
        sfSprite_destroy(pg.spj[i]);
        sfTexture_destroy(pg.tpj[i]);
    }
    sfSprite_destroy(obs.scactus);
    sfSprite_destroy(obs.scactus1);
    sfSprite_destroy(obs.scactus2);
    sfSprite_destroy(obs.scactus);
    sfTexture_destroy(obs.tcactus);
    sfTexture_destroy(obs.tcactus1);
    sfTexture_destroy(obs.tcactus2);
    sfTexture_destroy(obs.tcactus3);
    sfRenderWindow_destroy(score.window);
}

int  main(int ac, char **av)
{
    sfVideoMode mode = {1920 , 1080, 32};
    struct_t **object = tab();
    obstacle_t obs;
    running_t runner = initplayerrun(runner, &obs);
    action_t pg = initplayergliss(pg);
    score_t all = initvariable(all);
    int map = 0;

    if (ac == 1)
        return (84);
    all.window = sfRenderWindow_create(mode, "run", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(all.window)) {
        if (map == 0)
            all = map_reader(all, av[1]);
        parallax(object);
        obs = score(all, obs);
        all = drawobstacle(all, &obs, pg);
        all = eventfunction(all, object, runner, &pg);
    }
    destroy(all, runner, pg, obs);
    return (0);
}
