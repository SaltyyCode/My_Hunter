/*
** EPITECH PROJECT, 2023
** my_events_window
** File description:
** all events with the window
*/

#include "../include/hunter.h"

void destroy_init(First *vid, mob_s *mob)
{
    sfRenderWindow_destroy(vid->window);
    sfSprite_destroy(vid->bgSprite);
    sfSprite_destroy(mob->bird);
    sfTexture_destroy(vid->bgTexture);
    sfTexture_destroy(mob->texture_bird);
    sfClock_destroy(mob->birdclock);
    sfSound_destroy(vid->music);
    sfFont_destroy(vid->score.font);
    sfSprite_destroy(vid->cross.sprite);
    sfTexture_destroy(vid->cross.texture);
}

void init_window(First *vid)
{
    vid->video_mode.width = 1920;
    vid->video_mode.height = 1080;
    vid->video_mode.bitsPerPixel = 32;
    vid->window = sfRenderWindow_create(vid->video_mode,
    "My_Hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(vid->window, 60);
    vid->bgSprite = sfSprite_create();
    vid->bgTexture = sfTexture_createFromFile("ressources/backg.jpg", NULL);
    sfSprite_setTexture(vid->bgSprite, vid->bgTexture, sfTrue);
    vid->score.text = sfText_create();
    vid->score.font = sfFont_createFromFile("ressources/arial.ttf");
    vid->score.value = 0;
    vid->cross.sprite = sfSprite_create();
    sfText_setFont(vid->score.text, vid->score.font);
    sfText_setCharacterSize(vid->score.text, 30);
    sfText_setPosition(vid->score.text, (sfVector2f){10, 10});
    sfText_setFillColor(vid->score.text, sfBlack);
    sfText_setString(vid->score.text, "Score 0");
    vid->cross.texture = sfTexture_createFromFile("ressources/shoot.png",
    NULL);
}

void start_sound(First *vid)
{
    vid->music = sfMusic_createFromFile("ressources/Duckhunt.ogg");
    sfMusic_setLoop(vid->music, sfTrue);
    sfMusic_play(vid->music);
}

int my_hunter(First *vid, mob_s *mob)
{
    init_window(vid);
    init_bird(mob);
    start_sound(vid);
    while (sfRenderWindow_isOpen(vid->window)) {
            analyse_events(vid, mob);
            display_all(vid, mob);
            sfRenderWindow_display(vid->window);
            animation(mob, vid);
        }
    destroy_init(vid, mob);
    return EXIT_SUCCESS;
}
