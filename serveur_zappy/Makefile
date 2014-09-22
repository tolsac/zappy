##
## Makefile for makefile in /home/boyer_b/Documents/Epitech/
##
## Made by bertrand boyer
## Login   <boyer_b@epitech.net>
##
## Started on  Wed Oct 26 09:52:13 2011 bertrand boyer
## Last update Sun Jul 15 17:57:35 2012 bertrand boyer
##

# Généralités.
NAME		= serveur
RM		= rm -f

# Compilation C.
CC		= gcc
CFLAGS		= -ansi -pedantic -W -Wall -Wextra #-Werror

HDR		= $(wildcard *.h)
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

$(NAME):	$(HDR) $(OBJ)
	@echo -n "Compilation de $(NAME)."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo " Terminée."

all:		$(NAME)

%.o:		%.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -n "Suppression des fichiers objets."
	@$(RM) $(OBJ)
	@echo " Terminée."

fclean:		clean
	@echo -n "Suppression du programme $(NAME)."
	@$(RM) $(NAME)
	@echo " Terminée."

re:		fclean all

.PHONY:	all clean fclean re