/*
** get_option.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Mon May 21 15:56:55 2012 baptiste bourlet-de-la-vallee
** Last update Thu Jul 12 06:08:18 2012 camille tolsa
*/

#include	"./serveur.h"

void			is_a_n(int c, char **av, t_init *data)
{
  int			x;
  int			cpt;

  if (c != 'n')
    return;
  data->check_option[5] = 1;
  cpt = 0;
  x = optind - 1;
  data->team_name = xmalloc(sizeof(char *) * 3);
  while (av[x] && av[x][0] != '-')
    {
      if (cpt >= 2)
	data->team_name = xrealloc(data->team_name, 8 * (cpt + 2));
      data->team_name[cpt] = xmalloc(sizeof(char) * 1024);
      if (strlen(av[x]) > 1024)
	{
	  usage();
	  fprintf(stderr, "./serveur: one of your team name is too long\n");
	  free(data->team_name[cpt]);
	  exit(0);
	}
      else
	data->team_name[cpt++] = av[x++];
    }
  data->team_name[cpt] = NULL;
}

int			aff_options(t_init *data)
{
  int			x;

  printf("Configuration : \033[33;33mMax\033[33;0m(\033[33;32m%d\033[33;0m) ",
	 data->players_allowed);
  printf("\033[33;33mWorldX\033[33;0m(\033[33;32m%d\033[33;0m) ", data->width);
  printf("\033[33;33mWorldY\033[33;0m(\033[33;32m%d\033[33;0m)", data->height);
  printf(" \033[33;33mT\033[33;0m(\033[33;32m%d\033[33;0m)\n", data->speed);
  printf("Teams : \n");
  x = 0;
  while (data->team_name[x] != NULL)
    {
      printf("\t\033[33;33mName\033[33;0m(\033[33;32m%s\033[33;0m) ",
	     data->team_name[x]);
      printf("\033[33;33mMax\033[33;0m(\033[33;32m%d\033[33;0m)\n",
	     data->players_allowed);
      x++;
    }
  printf("Generating world ... ");
  init_action(data);
  generating(data);
  if ((generating_map(data)) == 1)
    printf("\033[33;32mdone\033[33;0m\n");
  else
    printf("\033[33;31mfail\033[33;0m\n");
  return (1);
}

int			get_option_init(int ac, char **av, t_init *data)
{
  int                   c;

  bzero(data->check_option, 6);
  if (ac > 1)
    {
      while ((c = getopt(ac, av, "p:x:y:n:c:t:")) != -1)
	{
	  is_a_p(c, optarg, data);
	  is_a_x(c, optarg, data);
	  is_a_y(c, optarg, data);
	  is_a_c(c, optarg, data);
	  is_a_t(c, optarg, data);
	  is_a_n(c, av, data);
	}
      if (data->check_option[5] == 1)
	{
	  c = 0;
	  while (data->team_name[c++]);
	  if ((c - 1) >= 2)
	    return (1);
	}
    }
  usage();
  return (-1);
}
