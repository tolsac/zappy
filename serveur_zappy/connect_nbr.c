/*
** connect_nbr.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Wed Jun 20 16:53:01 2012 baptiste bourlet-de-la-vallee
** Last update Sun Jul  1 19:59:04 2012 bertrand boyer
*/

#include	"./serveur.h"

int		connect_nbr(t_init *data, t_player *p, char *msg)
{
  int		ret;
  char		*tmp;

  (void) msg;
  ret = nb_place_dispo(data, p->light.team);
  tmp = xmalloc(10);
  bzero(tmp, 10);
  sprintf(tmp, "%d\n", ret);
  p->ans.write_buffer(&(p->ans), tmp);
  free(tmp);
  return (0);
}
