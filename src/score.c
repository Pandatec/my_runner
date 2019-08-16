/*
** EPITECH PROJECT, 2019
** score.c
** File description:
** score.c
*/

#include "../include/struct.h"

obstacle_t score(score_t score, obstacle_t obs)
{
    static char *test = "0";

    if (score.start == 0) {
        (obs.poscactus.x < 120 && obs.poscactus.x > 118) ? test = "1" : 0;
        (obs.poscactus1.x < 120 && obs.poscactus1.x > 118) ? test = "2" : 0;
        (obs.poscactus2.x < 120 && obs.poscactus2.x > 118) ? test = "3" : 0;
        (obs.poscactus3.x < 120 && obs.poscactus3.x > 118) ? test = "4" : 0;
        sfText_setString(obs.text, test);
        sfText_setFont(obs.text, obs.font);
        sfText_setCharacterSize(obs.text, 200);
        sfRenderWindow_drawText(score.window, obs.text, NULL);
    }
    return (obs);
}
