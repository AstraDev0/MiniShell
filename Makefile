##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=	$(wildcard ./src/*.c)	\

OBJ		=	$(SRC:.c=.o)

NAME	=	42sh

LIB =	-L ./lib/my -lmy

CFLAGS	=	-I ./include -g3

$(NAME):
		make -C lib/my
		gcc -o $(NAME) $(SRC) $(CFLAGS) $(LIB)
		@echo "\033[05m\033[44mcompilation done => ${NAME}\033[00m"

all:	$(NAME)

clean:
		make clean -C lib/my
		rm -f *~
		rm -f $(OBJ)

fclean:	clean
		make fclean -C lib/my
		rm -f vgcore*
		rm -f *.gcda
		rm -f *.gcno
		rm -f $(NAME)

re:		fclean all

.PHONY:	re fclean clean all
