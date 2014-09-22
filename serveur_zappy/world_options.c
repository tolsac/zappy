/*
** world_options.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Mon May 21 16:06:57 2012 baptiste bourlet-de-la-vallee
** Last update Thu Jul 12 06:01:36 2012 camille tolsa
*/

#include	"./serveur.h"

void		is_a_p(int c, char *str, t_init *data)
{
  if (c == 'p')
    {
      if (atoi(str) <= 1024 || atoi(str) >= 65536)
	{
	  usage();
	  printf("./serveur: option -p need a valid port [1024-65536]\n");
	  exit(0);
	}
      data->check_option[0] = 1;
      data->port = atoi(str);
    }
  else if (data->check_option[0] == 0)
    {
      data->check_option[0] = 2;
      data->port = atoi("4242");
    }
}

void		is_a_x(int c, char *str, t_init *data)
{
  if (c == 'x')
    {
      if (atoi(str) <= 3)
	{
	  usage();
	  printf("./serveur: option -x need an argument bigger than 3\n");
	  exit(0);
	}
      data->check_option[1] = 1;
      data->width = atoi(str);
    }
  else if (data->check_option[1] == 0)
    {
      data->check_option[1] = 2;
      data->width = atoi("20");
    }
}

void		is_a_y(int c, char *str, t_init *data)
{
  if (c == 'y')
    {
      if (atoi(str) <= 3)
	{
	  usage();
	  printf("./serveur: option -y need an argument bigger than 3\n");
	  exit(0);
	}
      data->check_option[2] = 1;
      data->height = atoi(str);
    }
  else if (data->check_option[2] == 0)
    {
      data->check_option[2] = 2;
      data->height = atoi("20");
    }
}

void		is_a_c(int c, char *str, t_init *data)
{
  if (c == 'c')
    {
      if (atoi(str) <= 0)
	{
	  usage();
	  printf("./serveur: option -c need a positive argument\n");
	  exit(0);
	}
      data->check_option[3] = 1;
      data->players_allowed = atoi(str);
    }
  else if (data->check_option[3] == 0)
    {
      data->check_option[3] = 2;
      data->players_allowed = atoi("10");
    }
}

void		is_a_t(int c, char *str, t_init *data)
{
  if (c == 't')
    {
      if (atoi(str) <= 0)
	{
	  usage();
	  printf("./serveur: option -t need a positive argument\n");
	  exit(0);
	}
      data->check_option[4] = 1;
      data->speed = atoi(str);
    }
  else if (data->check_option[4] == 0)
    {
      data->check_option[4] = 2;
      data->speed = atoi("100");
    }
}
