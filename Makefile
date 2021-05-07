##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	src/create_object.c		\
			src/main.c				\
			src/print_usage.c		\
			src/game.c				\
			src/display.c			\
			src/music.c				\
			src/destroy.c			\
			src/move_environment.c	\
			src/score.c				\
			src/init_score.c		\
			src/create_clock.c		\
			src/sound_effect.c		\
			src/init_buffer.c		\
			src/update_menu.c		\
			src/menu_handler.c		\
			src/create_menu_object.c	\
			src/init_menu.c			\
			src/pause_menu.c		\
			src/fps_handler.c		\
			src/read_map.c			\
			src/load_map.c			\
			src/check_end_game.c	\
			src/collision.c			\
			src/end_game_handler.c	\
			src/random_spawn.c		\
			src/init_struct.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS	+=	-Wall -Werror -Wshadow -Wshadow -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
			make re -C lib/my/
			cc $(OBJ) -o $(NAME) -L./lib/ -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			make fclean -C lib/my/
			rm -f lib/libmy.a

re:			fclean all

.PHONY:		all clean fclean re