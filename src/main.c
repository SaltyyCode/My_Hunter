/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my_hunter project main
*/

#include "../include/hunter.h"

int main(int ac, char **av)
{
    First *vid = malloc(sizeof(First));
    mob_s *mob = malloc(sizeof(mob_s));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        my_putstr("my_hunter epitech project!\nShoot the ducks!\n"
                    "Usage: ./my_hunter\n");
        return (0);
    }
    if (ac != 1)
        return (84);
    my_hunter(vid, mob);
    free(vid);
    free(mob);
    return 0;
}
