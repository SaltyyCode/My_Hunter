##
## EPITECH PROJECT, 2023
## Makefile my_hunter
## File description:
## Makefile for my_hunter
##

NAME	=	my_hunter

CFLAGS	=	-W -Wall -Wextra

SRC =	src/main.c \
     	src/analyse_events.c \
     	src/my_hunter.c \
     	src/my_write.c\
		src/init_mob.c\
		src/animation_bird.c\
		src/draw.c\
		src/my_str.c\
		src/crosshair.c

OBJ = $(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -I../include $(CFLAGS) $(CSFML) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
