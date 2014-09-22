/*
** temporary.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Thu May 31 13:57:31 2012 baptiste bourlet-de-la-vallee
** Last update Sun Jul 15 10:40:01 2012 camille tolsa
*/

#include	"./serveur.h"

t_egg		*create_egg(t_player *p, t_init *data)
{
  t_egg		*node;

  node = xmalloc(sizeof(*node));
  node->x = p->light.pos.x;
  node->y = p->light.pos.y;
  node->team = strdup(p->light.team);
  node->die = time(NULL) + (data->time[FORKER] / data->speed);
  return (node);
}

int		fork_egg(t_init *data, t_player *p, char *msg)
{
  data = data;
  p = p;
  msg = msg;
  p->ans.write_buffer(&(p->ans), "ko\n");
  return (0);
}

t_egg		*delete_egg(t_egg **egg_list, t_egg *egg)
{
  t_egg		*tmp;
  t_egg		*prev;

  tmp = *egg_list;
  prev = NULL;
  while (tmp != NULL)
    {
      if (tmp == egg && prev == NULL)
	{
	  *egg_list = tmp->next;
	  free(tmp);
	  return (*egg_list);
	}
      else if (tmp == egg)
	{
	  prev->next = egg->next;
	  free(tmp);
	  return (prev);
	}
      prev = tmp;
      tmp = tmp->next;
    }
  return (egg);
}
