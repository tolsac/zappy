/*
** structures.h for zappy in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Fri Jun 22 17:19:29 2012 bertrand boyer
** Last update Sat Jul 14 13:44:48 2012 camille tolsa
*/

#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<strings.h>
#include	<time.h>
#include	<netdb.h>
#include	<dlfcn.h>
#include	<fcntl.h>
#include	<signal.h>
#include	<dirent.h>
#include	<getopt.h>
#include	<netinet/in.h>
#include	<sys/mman.h>
#include	<sys/stat.h>
#include	<arpa/inet.h>
#include	<sys/ioctl.h>
#include	<sys/time.h>
#include	<sys/select.h>
#include	<sys/types.h>
#include	<sys/socket.h>

#define NB_FCT		21
#define	MAX_MSG		1024
#define	PERCENT		60
#define	BUFFER_SIZE	20000
#define	INV_FORMAT	"nourriture %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d\n"
#define STR_IGNORED	"\033[31mServer has ignored \"\033[0m"		/* Dans setup_timer() */
#define STR_COMMAND	"\033[31m\" command\033[0m\n"			/* Dans setup_timer() */
#define STR_LISTENING	"Listening on \033[33;33mport\033[33;0m: \033[33;32m%d\033[33;0m\n"	/* Dans main() */

typedef enum	e_direction
  {
    UP = 1,
    RIGHT = 3,
    DOWN = 5,
    LEFT = 7
  }		t_direction;

typedef enum	e_action
  {
    AVANCER,
    DROITE,
    GAUCHE,
    VOIR,
    INVENTAIRE,
    PRENDRE,
    POSER,
    EXPULSER,
    BROADCAST,
    INCANTER,
    FORKER,
    CONNECTER,
    MAPSIZE,
    GETCASE,
    GETMAP,
    GETTEAM,
    PLAYERPOS,
    PLAYERINV,
    PLAYERLVL,
    GETTIME,
    SETTIME
  }		t_action;

typedef struct s_egg
{
  int		x;
  int		y;
  char		*team;
  time_t	die;
  struct s_egg  *next;
}		t_egg;

/* typedef struct s_graphic_clt */
/* { */
/*   int			fd; */
/*   int			connected; */
/*   struct s_graphic_clt  *next; */
/* }t_graphic_clt; */

typedef struct	s_case
{
  int		x;
  int		y;
}		t_case;

typedef struct	s_light
{
  int		lvl;
  int		nb;
  char		*team;
  t_case	pos;
  int		inv[7];
  t_direction	dir;
}		t_light;

typedef struct s_buffer
{
  char		buf[BUFFER_SIZE];
  int		w;
  int		r;
  int		c;
  int		(*write_buffer)(struct s_buffer *, char *);  /*ecris dans le buffer et decale l'indice*/
  char		*(*read_buffer)(struct s_buffer *);	     /*lis dans le buffer et decale l'indice*/
  char		*(*get)(struct s_buffer *);                  /*lis dans le buffer sans decaler l'indice*/
  void		(*show_buffer)(struct s_buffer *);           /*print la totalité du buffer*/
  void		(*clear_buffer)(struct s_buffer *);          /*vide et initialise le buffer*/
}		t_buffer;

typedef struct	s_player
{
  int		fd;
  int		graphic;
  char		ghost;
  char		*answer;
  time_t	timer;
  time_t	save_time;
  time_t	life;
  t_light	light;
  t_buffer	buf;
  t_buffer	ans;
  time_t	start;
  time_t	end;
  time_t	incant;
}		t_player;

typedef struct	s_player_lst
{
  t_player	player;
  struct s_player_lst *next;
}		t_player_lst;

typedef struct	s_init
{
  int		fd_graphic;
  int		***map;
  int		socket;
  int		port;
  int		width;
  int		height;
  int		players_allowed;
  int		speed;
  int		*time;
  char		check_option[6];
  char		name_inv[7][11];
  char		objets[8][12];
  char		**team_name;
  char		**cmd;
  fd_set	read;
  fd_set	write;
  t_player_lst	*head;
  t_player_lst	*tail;
  t_egg		*egg_lst;
  int		(*action[NB_FCT])(struct s_init *, t_player *, char *);
}		t_init;

typedef struct  s_expluse
{
  t_direction   d;
  void          (*kick)(t_player *, int, int, int);
}		t_expluse;

typedef struct	s_node
{
  t_player	**list;
  t_case	pos;
  struct s_node	*next;
  struct s_node	*prev;
}		t_node;

#endif
