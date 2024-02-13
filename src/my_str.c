/*
** EPITECH PROJECT, 2023
** my_str
** File description:
** all str functions
*/

#include "../include/hunter.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != 0; i++);
    return i;
}

char *my_strcat(char *dest, char *src)
{
    int a;
    int b;

    b = 0;
    a = my_strlen(dest);
    while (src[b]) {
    dest[a + b] = src[b];
        b++;
    }
    dest[a + b] = '\0';
    return (dest);
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp;
    int i = 0;

    while (i < len / 2) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i++;
    }
    return str;
}

char *int_to_str(int num)
{
    int a = 0;
    char *str = malloc(sizeof(char) * 100);

    if (num == 0)
        return "0";
    while (num != 0) {
        str[a] = num % 10 + '0';
        num = num / 10;
        a++;
    }
    str[a] = '\0';
    my_revstr(str);
    return str;
}
