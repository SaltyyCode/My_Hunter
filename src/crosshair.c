/*
** EPITECH PROJECT, 2023
** crosshair file
** File description:
** Display crosshair ( && create)
*/

#include "../include/hunter.h"

void set_and_display_crosshair(First *game)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window);

    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    sfSprite_setTexture(game->cross.sprite, game->cross.texture, sfTrue);
    sfSprite_setScale(game->cross.sprite, (sfVector2f){0.05, 0.05});
    sfSprite_setPosition(game->cross.sprite,
    (sfVector2f){(float)mpos.x - 65, (float)mpos.y - 65});
    sfRenderWindow_drawSprite(game->window, game->cross.sprite, NULL);
}
