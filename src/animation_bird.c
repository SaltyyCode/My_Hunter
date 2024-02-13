/*
** EPITECH PROJECT, 2023
** project my_hunter
** File description:
** function for animate my beautiful bird
*/

#include "../include/hunter.h"

void animation(mob_s *mob, First *vid)
{
    mob->birdtime = sfClock_getElapsedTime(mob->birdclock);
    mob->bird_seconds = mob->birdtime.microseconds / 1000000.0;
    if (mob->bird_seconds > 0.2) {
        if (mob->birdrect.left > ((mob->birdrect.width * 3) - 180))
            mob->birdrect.left = 0;
        mob->birdrect.left += mob->birdrect.width;
        sfSprite_setTextureRect(mob->bird, mob->birdrect);
        sfClock_restart(mob->birdclock);
    }
    mob->x += mob->speed;
    if (mob->x > vid->video_mode.width) {
        mob->x = 0;
        mob->y = rand() % (1080 - 110);
    }
    sfSprite_setPosition(mob->bird, (sfVector2f){mob->x, mob->y});
}
