/*
** send_all.c for  in /home/tolsa_c//svnok/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by camille tolsa
** Login   <tolsa_c@epitech.net>
**
** Started on  Tue Jun 26 07:45:18 2012 camille tolsa
** Last update Thu Jun 28 20:19:02 2012 bertrand boyer
*/

#include "./serveur.h"

int		send_all(t_init *data, t_player *g)
{
  char		*msg;

  msg = s_mapsize(data->width, data->height);
  if ((send(g->fd, msg, strlen(msg), 0)) == -1)
    return (merror("send"));
  free(msg);
  msg = s_servtim(data->speed);
  if ((send(g->fd, msg, strlen(msg), 0)) == -1)
    return (merror("send"));
  free(msg);
  msg = s_sendmap(data->map, data->width, data->height);
  if ((send(g->fd, msg, strlen(msg), 0)) == -1)
    return (merror("send"));
  free(msg);
  msg = s_sendtea(data->team_name);
  if ((send(g->fd, msg, strlen(msg), 0)) == -1)
    return (merror("send"));
  free(msg);
  return (0);
}
