
    /*
** EPITECH PROJECT, 2023
** project my_hunter
** File description:
** draw and display everything
*/

#include "../include/hunter.h"

void display_all(First *vid, mob_s *mob)
{
    sfRenderWindow_clear(vid->window, sfBlack);
    sfRenderWindow_drawSprite(vid->window, vid->bgSprite, NULL);
    sfRenderWindow_drawText(vid->window, vid->score.text, NULL);
    sfRenderWindow_drawSprite(vid->window, mob->bird, NULL);
    set_and_display_crosshair(vid);
}
