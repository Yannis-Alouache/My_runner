##
## EPITECH PROJECT, 2020
## is_char_alpha.c
## File description:
## yannis.alouache@epitech.eu
##

SRC	=	*.c

LIB_NAME = libmy.a
INC_NAME = my.h

NAME = test

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(LIB_NAME) *.o
	cp $(LIB_NAME) ../
	cp $(INC_NAME) ../../include/

clean:
	find -name "*.o" -delete

fclean:
	make clean
	rm -f *.a

auteur:
	echo $(USER)