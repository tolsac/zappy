##
## Makefile for makefile in /home/boyer_b/Documents/Epitech/
##
## Made by bertrand boyer
## Login   <boyer_b@epitech.net>
##
## Started on  Wed Oct 26 09:52:13 2011 bertrand boyer
## Last update Sun Jul 15 17:57:00 2012 bertrand boyer
##

NAME		= zappy
NAME1		= serveur
NAME2		= client
NAME3		= moniteur

DIR_SERVEUR	= ./serveur_zappy
SRC_SERVEUR	= $(wildcard $(DIR_SERVEUR)/*.c)
HDR_SERVEUR	= $(wildcard $(DIR_SERVEUR)/*.h)

DIR_CLIENT	= ./client_zappy
SRC_CLIENT	= $(wildcard $(DIR_CLIENT)/*.cpp)
HDR_CLIENT	= $(wildcard $(DIR_CLIENT)/*.hh)

DIR_MONITEUR	= ./moniteur_zappy
SRC_MONITEUR	= $(wildcard $(DIR_MONITEUR)/*.cpp)
HDR_MONITEUR	= $(wildcard $(DIR_MONITEUR)/*.hh)

$(NAME):	$(NAME1) $(NAME2) $(NAME3)

$(NAME1):	$(HDR_SERVEUR) $(SRC_SERVEUR)
	@(cd $(DIR_SERVEUR) && $(MAKE))

$(NAME2):	$(HDR_CLIENT) $(SRC_CLIENT)
	@(cd $(DIR_CLIENT) && $(MAKE))

$(NAME3):	$(HDR_MONITEUR) $(SRC_MONITEUR)
	@(cd $(DIR_MONITEUR) && $(MAKE))

all:		$(NAME)

clean:
	@(cd $(DIR_SERVEUR) && $(MAKE) $@)
	@(cd $(DIR_CLIENT) && $(MAKE) $@)
	@(cd $(DIR_MONITEUR) && $(MAKE) $@)

fclean:
	@(cd $(DIR_SERVEUR) && $(MAKE) $@)
	@(cd $(DIR_CLIENT) && $(MAKE) $@)
	@(cd $(DIR_MONITEUR) && $(MAKE) $@)

re:		fclean all

.PHONY:	all clean fclean re
