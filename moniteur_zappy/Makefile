##
## Makefile for makefile in /home/boyer_b/Documents/Epitech/
##
## Made by bertrand boyer
## Login   <boyer_b@epitech.net>
##
## Started on  Wed Oct 26 09:52:13 2011 bertrand boyer
## Last update Sun Jul 15 18:00:36 2012 bertrand boyer
##

# Généralité.
NAME		= moniteur
RM		= rm -f

# Compilation C++.
CPP		= g++
CXXFLAGS	= -ansi -pedantic -W -Wall -Wextra $(INC) $(LIB) #-Werror
INC		= -I ./include/
LIB		= -Wl,--rpath=./lib/sfml -L ./lib/sfml -lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics -lGL -lX11 -lXrandr -lfreetype

HDR		= $(wildcard *.hh)
SRC		= $(wildcard *.cpp)
OBJ		= $(SRC:.cpp=.o)

$(NAME):	$(HDR) $(OBJ)
	@echo -n "Compilation de $(NAME)."
	@$(CPP) -o $(NAME) $(OBJ) $(CXXFLAGS)
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