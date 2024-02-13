/*
** EPITECH PROJECT, 2023
** kaisen.h
** File description:
** my_hunter .h
*/

#ifndef HUNTER
    #define HUNTER

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>

typedef struct score_game {
    int value;
    sfText *text;
    sfFont *font;
} score_game;

typedef struct crosshair {
    sfSprite *sprite;
    sfTexture *texture;
} crosshair;

typedef struct mob{
    sfSprite *bird;
    sfTexture *texture_bird;
    sfClock *birdclock;
    sfTime birdtime;
    sfIntRect birdrect;
    float bird_seconds;
    float x;
    float y;
    int speed;
} mob_s;

typedef struct first{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfTexture *texture;
    sfTexture *bgTexture;
    sfEvent event;
    sfSprite *bgSprite;
    sfMusic *music;
    score_game score;
    crosshair cross;
} First;

void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(const char *str);
int analyse_events(First *vid, mob_s *mob);
int my_hunter(First *vid, mob_s *mob);
void init_bird(mob_s *mob);
void animation(mob_s *mob, First *vid);
void display_all(First *vid, mob_s *mob);
void destroy_init(First *vid, mob_s *mob);
void click_evt(First *vid, mob_s *mob);
char *my_strcat(char *dest, char *src);
char *my_revstr(char *str);
char *int_to_str(int num);
void set_and_display_crosshair(First *game);

#endif /*HUNTER*/
