/*
** add_player_spec.c for zappy in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Sat Jul 14 12:41:27 2012 bertrand boyer
** Last update Sun Jul 15 18:07:08 2012 bertrand boyer
*/

#include "./serveur.h"

int		connection_to_egg(t_init *data, t_player_lst *p, char *name)
{
  t_egg		*tmp;

  tmp = data->egg_lst;
  while (tmp != NULL)
    {
      if (tmp != NULL && strcmp(tmp->team, name) == 0)
	{
	  p->player.light.team = strdup(name);
	  p->player.light.lvl = 1;
	  p->player.light.pos.x = tmp->x;
	  p->player.light.pos.y = tmp->y;
	  p->player.ghost = 0;
	  delete_egg(&(data->egg_lst), tmp);
	  return (0);
	}
      if (tmp != NULL)
	tmp = tmp->next;
    }
  return (1);
}
