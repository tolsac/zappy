/*
** move.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Wed May 30 00:04:35 2012 baptiste bourlet-de-la-vallee
** Last update Thu Jun 28 20:52:26 2012 bertrand boyer
*/

#include	"./serveur.h"

int		ahead(t_init *data, t_player *p, char *msg)
{
  char		*s;

  (void)msg;
  if (p->light.dir == UP)
    ((p->light.pos.y - 1) == -1) ? p->light.pos.y = data->height - 1
      : p->light.pos.y--;
  else if (p->light.dir == RIGHT)
    ((p->light.pos.x + 1) == data->width) ? p->light.pos.x = 0
      : p->light.pos.x++;
  else if (p->light.dir == DOWN)
    ((p->light.pos.y + 1) == data->height) ? p->light.pos.y = 0
      : p->light.pos.y++;
  else
    ((p->light.pos.x - 1) == -1) ? p->light.pos.x = data->width - 1
      : p->light.pos.x--;
  s = s_playerpos(&(p->light));
  send(data->fd_graphic, s, strlen(s), 0);
  p->ans.write_buffer(&(p->ans), "ok\n");
  free(s);
  return (0);
}

int		left(t_init *data, t_player *p, char *msg)
{
  char		*s;
  (void) msg;
  (void) data;

  (p->light.dir == 1) ? (p->light.dir = 7) : (p->light.dir -= 2) % 8;
  p->ans.write_buffer(&(p->ans), "ok\n");
  s = s_playerpos(&(p->light));
  send(data->fd_graphic, s, strlen(s), 0);
  free(s);
  return (0);
}

int		right(t_init *data, t_player *p, char *msg)
{
  char		*s;

  (void) data;
  (void) msg;

  (p->light.dir == 7) ? (p->light.dir = 1) : (p->light.dir += 2) % 8;
  p->ans.write_buffer(&(p->ans), "ok\n");
  s = s_playerpos(&(p->light));
  send(data->fd_graphic, s, strlen(s), 0);
  free(s);
  return (0);
}
