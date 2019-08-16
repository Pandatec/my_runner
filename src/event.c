/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** event.c
*/

#include "../include/struct.h"

score_t eventfunction2(score_t score, struct_t **object, running_t runner,
                       action_t *pg)
{
    //if (score.start == 0) {
    while (score.i != 3) {
        sfRenderWindow_drawSprite(score.window, object[score.i]->sprite,
                                  NULL);
        score.i = score.i + 1;
    }
    score.i = 0;
    score = anim1(score, pg, runner);
//} else
    //      score = menu(score);
    return (score);
}

score_t eventfunction(score_t score, struct_t **object, running_t runner,
action_t *pg)
{
    while (sfRenderWindow_pollEvent(score.window, &score.event)) {
        if (score.event.type == sfEvtClosed) {
            sfRenderWindow_close(score.window);
            return;
        }
        (sfKeyboard_isKeyPressed(sfKeyDown)) ? score.boolean = 1 : 0;
        (sfKeyboard_isKeyPressed(sfKeyReturn) && score.start == 1) ?
            score.start = 0 : 0;
        (sfKeyboard_isKeyPressed(sfKeyUp)) ? score.boolean = 2 : 0;
    }
    score = eventfunction2(score, object, runner, pg);
    return (score);
}
