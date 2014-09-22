/*
** command_graphic.c for  in /home/tolsa_c//svnok/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by camille tolsa
** Login   <tolsa_c@epitech.net>
**
** Started on  Tue Jun 26 09:38:56 2012 camille tolsa
** Last update Thu Jun 28 13:37:42 2012 camille tolsa
*/

#include "./serveur.h"

int		msz(t_init *data, t_player *g, char *msg)
{
  char		*s;

  (void) msg;
  s = s_mapsize(data->width, data->height);
  send(g->fd, s, strlen(s), 0);
  free(s);
  return (0);
}

int		bct(t_init *data, t_player *g, char *msg)
{
  char		*s;
  int		x;
  int		y;

  if (8 <= strlen(msg))
    {
      sscanf(msg, "bct %d %d\n", &x, &y);
      if (data->width <= x || data->height <= y)
	s = s_badpara();
      else
	s = s_sendcas(data->map, x, y);
    }
  else
    s = s_badpara();
  send(g->fd, s, strlen(s), 0);
  free(s);
  return (0);
}

int		mct(t_init *data, t_player *g, char *msg)
{
  char		*s;

  (void) msg;
  s = s_sendmap(data->map, data->width, data->height);
  send(g->fd, s, strlen(s), 0);
  free(s);
  return (0);
}

int		tna(t_init *data, t_player *g, char *msg)
{
  char		*s;

  (void) msg;
  s = s_sendtea(data->team_name);
  send(g->fd, s, strlen(s), 0);
  free(s);
  return (0);
}

int		ppo(t_init *data, t_player *g, char *msg)
{
  char		*s;
  int		id;
  t_player_lst	*tmp;

  if (5 <= strlen(msg))
    {
      sscanf(msg, "ppo %d\n", &id);
      tmp = data->head;
      while (tmp != NULL && tmp->player.light.nb != id)
	tmp = tmp->next;
      if (tmp != NULL)
	s = s_playerpos(&(tmp->player.light));
      else
	s = s_badpara();
    }
  else
    s = s_badpara();
  send(g->fd, s, strlen(s), 0);
  free(s);
  return (0);
}
