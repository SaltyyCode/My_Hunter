/*
** EPITECH PROJECT, 2023
** my_hunter analyse event
** File description:
** switch case for events
*/
#include "../include/hunter.h"

void set_score(First *vid)
{
    char *new_score = malloc(sizeof(500));

    vid->score.value += 1;
    new_score[0] = '\0';
    my_strcat(new_score, "Score ");
    my_strcat(new_score, int_to_str(vid->score.value));
    sfText_setString(vid->score.text, new_score);
}

void click_evt(First *vid, mob_s *mob)
{
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(mob->bird);

    if (sfFloatRect_contains(&spriteBounds, vid->event.mouseButton.x,
    vid->event.mouseButton.y)) {
        mob->speed += 1;
        mob->x = -200;
        mob->y = rand() % (1080 - 110);
        set_score(vid);
        sfSprite_setPosition(mob->bird, (sfVector2f){mob->x, mob->y});
        }
}

int analyse_events(First *vid, mob_s *mob)
{
    while (sfRenderWindow_pollEvent(vid->window, &vid->event)) {
        switch (vid->event.type){
            case sfEvtClosed:
                sfRenderWindow_close(vid->window);
            case sfEvtMouseButtonPressed:
                click_evt(vid, mob);
            default:
                continue;
            }
    }
    return 0;
}
