/*
** take.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Wed Jun 20 15:55:05 2012 baptiste bourlet-de-la-vallee
** Last update Mon Jul  2 09:51:56 2012 camille tolsa
*/

#include	"./serveur.h"

int		take(t_init *data, t_player *p, char *msg)
{
  int		x;
  int		ok;
  char		*s;

  sscanf(msg, "prend %s\n", msg);
  x = -1;
  ok = 0;
  while (++x != 7)
    if (strcmp(msg, data->name_inv[x]) == 0)
      if (data->map[p->light.pos.y][p->light.pos.x][x] && (ok = 1))
	{
	  data->map[p->light.pos.y][p->light.pos.x][x]--;
	  p->light.inv[x]++;
	  p->ans.write_buffer(&(p->ans), "ok\n");
	  s = s_playerget(&(p->light), x);
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
