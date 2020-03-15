##
## EPITECH PROJECT, 2019
## emacs
## File description:
## Makefile for lib
##

SRC	=	my_strdup.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_strlen.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strstr.c			\
		malloc_arr.c			\
		my_itoa.c			\
		my_getnbr.c 		\
		my_str_to_word_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

RM	=	rm -f

CFLAGS	=	-I./../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	clean
