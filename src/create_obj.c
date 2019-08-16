/*
** EPITECH PROJECT, 2019
** create_obj.c
** File description:
** create object
*/

#include "../include/struct.h"

struct_t *create_object(const char *path_to_spritesheet, sfVector2f pos,
sfIntRect rect)
{
    struct_t *object = malloc(sizeof(*object));
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path_to_spritesheet, NULL);

    object->sprite = sprite;
    object->texture = texture;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->vector = pos;
    sfSprite_setPosition(object->sprite, object->vector);
    object->rect = rect;
    sfSprite_setTextureRect(object->sprite, object->rect);
    return (object);
}

struct_t **tab(void)
{
    struct_t **back = malloc(sizeof(tab) * 100000000);

    back[0] = create_object("./assets/back0.png", (sfVector2f){1, 1},
                           (sfIntRect){0, 0, 1920, 1080});
    back[1] = create_object("./assets/back5.png", (sfVector2f){1, 1},
                           (sfIntRect){0, 0, 1920, 1080});
    back[2] = create_object("./assets/back4.png", (sfVector2f){1, 1},
                           (sfIntRect){0, 0, 1920, 1080});
    back[3] = create_object("./assets/back3.png", (sfVector2f){1, 1},
                           (sfIntRect){0, 0, 1920, 1080});
    back[4] = create_object("./assets/back2.png", (sfVector2f){1, 1},
                           (sfIntRect){0, 0, 1920, 1080});
    back[5] = create_object("./assets/back1.png", (sfVector2f){1, 1},
                           (sfIntRect){0, 0, 1920, 1080});
    return (back);
}

void parallax(struct_t **object)
{
        move(&object[0]->rect, 0, 1080);
        move(&object[1]->rect, 1, 1080);
        move(&object[2]->rect, 2, 1080);
        sfSprite_setTextureRect(object[2]->sprite, object[2]->rect);
        sfSprite_setTextureRect(object[1]->sprite, object[1]->rect);
        sfSprite_setTextureRect(object[0]->sprite, object[0]->rect);
}
