/*
** EPITECH PROJECT, 2023
** project my_hunter
** File description:
** init my bird mob
*/

#include "../include/hunter.h"

void init_bird(mob_s *mob)
{
    mob->birdclock = sfClock_create();
    mob->bird = sfSprite_create();
    mob->bird_seconds = 0.0;
    mob->x = -200;
    mob->speed = 2;
    mob->y = rand() % (1080 - 110);
    mob->texture_bird = sfTexture_createFromFile("ressources/duck.png", NULL);
    mob->birdrect = (sfIntRect){0, 0, 110, 110};
    sfSprite_setTexture(mob->bird, mob->texture_bird, sfTrue);
    sfSprite_setTextureRect(mob->bird, mob->birdrect);
    sfSprite_setPosition(mob->bird, (sfVector2f){mob->x, mob->y});
}
