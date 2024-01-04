##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Setting up Makefile
##

NAME=	my_sokoban

SRC	=	src/load_map.c	\
		src/main.c		\
		src/keys.c		\
		src/move.c		\
		src/verif_move.c\
		src/info.c		\
		src/pos_o.c		\
		lib.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) -lncurses -g3

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
