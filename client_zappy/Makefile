##
## Makefile for makefile in /home/boyer_b/Documents/Epitech/
##
## Made by bertrand boyer
## Login   <boyer_b@epitech.net>
##
## Started on  Wed Oct 26 09:52:13 2011 bertrand boyer
## Last update Sun Jul 15 17:58:29 2012 bertrand boyer
##

# Généralité.
NAME		= client
RM		= rm -f

# Compilation C.
CPP		= g++
CXXFLAGS	= -ansi -pedantic -W -Wall -Wextra
SRC		= $(wildcard *.cpp)
OBJ		= $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@echo -n "Compilation de $(NAME)."
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo " Terminée."

all:		$(NAME)

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