/*
** put.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Wed Jun 20 16:39:17 2012 baptiste bourlet-de-la-vallee
** Last update Sun Jul 15 18:06:49 2012 bertrand boyer
*/

#include	"./serveur.h"

int		put(t_init *data, t_player *p, char *msg)
{
  int		ok;
  int		x;
  char		*s;

  msg += strlen("pose ");
  ok = 0;
  x = -1;
  while (++x != 7)
    if (!(strncmp(data->name_inv[x], msg, strlen(data->name_inv[x]))))
      if (p->light.inv[x] > 0 && (ok = 1))
	{
	  p->light.inv[x]--;
	  p->ans.write_buffer(&(p->ans), "ok\n");
	  data->map[p->light.pos.y][p->light.pos.x][x]++;
	  s = s_playerdro(&(p->light), x);
	  send(data->fd_graphic, s, strlen(s), 0);
	  s = s_playerinv(&(p->light));
	  send(data->fd_graphic, s, strlen(s), 0);
	  s = s_sendcas(data->map, p->light.pos.x, p->light.pos.y);
	  send(data->fd_graphic, s, strlen(s), 0);
	  free(s);
	}
  if (!ok)
    p->ans.write_buffer(&(p->ans), "ko\n");
  return (0);
}
