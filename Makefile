##
## EPITECH PROJECT, 2022
## ftp
## File description:
## Makefile
##

NAME		=	panoramix

TNAME		=	unittest

MAIN		=	sources/main.c

SRC		=	

TSRC		=	$(SRC) \

OBJ		=	$(SRC:.c=.o) \
			$(MAIN:.c=.o)

CC		=	gcc

RM		=	rm -rf

CFLAGS		=	-Wall -Wextra -Wshadow -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TNAME)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: debug re fclean clean all
