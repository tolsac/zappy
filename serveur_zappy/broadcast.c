/*
** broadcast.c for  in /home/barnet_m//Tek2/zappy/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by mathieu barnetche
** Login   <barnet_m@epitech.net>
**
** Started on  Sat Jun 23 16:28:44 2012 mathieu barnetche
** Last update Sat Jul 14 12:16:12 2012 mathieu barnetche
*/

#include "./serveur.h"

extern t_init *g_data;

int		needS(int x1, int x2, int xmap)
{
  if (abs(x1 - x2) < (xmap / 2))
    return (0);
  else
    return (1);
}

int		from(t_player *tmp, t_player *p, int wi, int he)
{
  int		caze;
  int		x;
  int		y;

  if (needS(tmp->light.pos.x, p->light.pos.x, wi) == 0)
    x = abs(tmp->light.pos.x - p->light.pos.x);
  else
    x = wi - abs(tmp->light.pos.x - p->light.pos.x);
  if (needS(tmp->light.pos.y, p->light.pos.y, he) == 0)
    y = abs(tmp->light.pos.y - p->light.pos.y);
  else
    y = he - abs(tmp->light.pos.y - p->light.pos.y);
  if (x == 0 && y == 0)
    return (0);
  if (x > y)
    (((tmp->light.pos.x < p->light.pos.x &&
       needS(tmp->light.pos.x, p->light.pos.x, wi) == 0) ||
      (tmp->light.pos.x > p->light.pos.x &&
       needS(tmp->light.pos.x, p->light.pos.x, wi) == 1)) ?
     (caze = 3) : (caze = 7));
  else
    caze = from2(tmp, p, x, y);
  caze = (caze + tmp->light.dir - 2) % 8 + 1;
  return (caze);
}

int		from2(t_player *tmp, t_player *p, int x, int y)
{
  int		caze;

  if (x < y)
    (((tmp->light.pos.y < p->light.pos.y &&
       needS(tmp->light.pos.y, p->light.pos.y, g_data->height) == 0) ||
      (tmp->light.pos.y < p->light.pos.y &&
       needS(tmp->light.pos.y, p->light.pos.y, g_data->height) == 1)) ?
     (caze = 5) : (caze = 1));
  else if ((tmp->light.pos.x < p->light.pos.x &&
	    needS(tmp->light.pos.x, p->light.pos.x, g_data->width) == 0) ||
	   (tmp->light.pos.x > p->light.pos.x &&
	    needS(tmp->light.pos.x, p->light.pos.x, g_data->width) == 1))
    (((tmp->light.pos.y < p->light.pos.y &&
       needS(tmp->light.pos.y, p->light.pos.y, g_data->height) == 0) ||
      (tmp->light.pos.y > p->light.pos.y &&
       needS(tmp->light.pos.y, p->light.pos.y, g_data->height) == 1)) ?
     (caze = 6) : (caze = 8));
  else
    (((tmp->light.pos.y < p->light.pos.y &&
       needS(tmp->light.pos.y, p->light.pos.y, g_data->height) == 0) ||
      (tmp->light.pos.y < p->light.pos.y &&
       needS(tmp->light.pos.y, p->light.pos.y, g_data->height) == 1)) ?
     (caze = 4) : (caze = 2));
  return (caze);
}

int		broadcast(t_init *data, t_player *p, char *msg)
{
  t_player_lst  *tmp;
  int		caze;
  char		*s;

  msg += strlen("broadcast ");
  tmp = data->head;
  s = xmalloc(strlen(msg) + STR_SIZE);
  while (tmp != NULL)
    {
      if (&(tmp->player) != p && tmp->player.graphic != 1
	  && tmp->player.ghost == 0)
	{
	  caze = from(&tmp->player, p, data->width, data->height);
	  snprintf(s, strlen(msg) + STR_SIZE, "%d %s\n", caze, msg);
	  s[strlen(s) - 1] = '\0';
	  sending(data, &(tmp->player), s);
	}
      tmp = tmp->next;
    }
  p->ans.write_buffer(&(p->ans), "ok\n");
  free(s);
  s = s_playerbro(&(p->light), msg);
  send(data->fd_graphic, s, strlen(s), 0);
  free(s);
  return (0);
}
