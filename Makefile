##
## EPITECH PROJECT, 2022
## ftp
## File description:
## Makefile
##

NAME		=	panoramix

TNAME		=	unittest

MAIN		=	sources/main.c

SRC		=	sources/panonoramix/args_management.c \
			sources/panonoramix/panoramix.c \
			sources/panonoramix/print_usage.c \

TSRC		=	$(SRC) \
				tests/test_args_management.c \

OBJ		=	$(SRC:.c=.o) \
			$(MAIN:.c=.o)

CC		=	gcc

RM		=	rm -rf

CFLAGS		=	-Wall -Wextra -Wshadow -Werror -I./includes -lpthread

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

tests_run: fclean
	$(CC) -o $(TNAME) $(TSRC) $(CFLAGS) -lcriterion --coverage
	./$(TNAME)
	gcovr --exclude tests
	gcovr --exclude tests --branch

.PHONY: debug re fclean clean all tests_run
