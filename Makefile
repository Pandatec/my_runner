##
## EPITECH PROJECT, 2017
## make
## File description:
## make
##

SRC	=	src/create_obj.c		\
		src/event.c			\
		src/init_struct.c		\
		src/jump_gestion.c		\
		src/my_runner.c			\
		src/obstacle_gestion.c		\
		src/read_map.c			\
		src/score.c


OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	my_runner

FLAGS1	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

FLAGS2	=	-Werror -Wall -Wextra -Iinclude -lm -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o 	$(NAME) $(OBJ) $(FLAGS1) $(FLAGS2)

clean:
	$(RM) $(OBJ)
	$(RM) vgcore.*

fclean:	clean
	rm -f 	$(NAME)

re:	fclean all

.PHONY:		 all clean fclean re
