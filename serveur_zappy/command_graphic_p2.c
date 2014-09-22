/*
** command_graphic_p2.c for serveur in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jun 28 14:04:05 2012 bertrand boyer
** Last update Sun Jul  1 19:59:28 2012 bertrand boyer
*/

#include "./serveur.h"

int		plv(t_init *data, t_player *g, char *msg)
{
  char		*s;
  t_player_lst	*lst;
  int		nb;

  sscanf(msg, "plv %d\n", &nb);
  printf("%d\n", nb);
  lst = data->head;
  while (lst && lst->player.light.nb != nb)
    lst = lst->next;
  if (lst != NULL && nb > 0)
    {
      s = s_playerlvl(&(lst->player.light));
      send(g->fd, s, strlen(s), 0);
    }
  else
    {
      s = s_badpara();
      send(g->fd, s, strlen(s), 0);
    }
  free(s);
  free(msg);
  return (0);
}

int		pin(t_init *data, t_player *g, char *msg)
{
  char		*s;
  int		nb;
  t_player_lst  *lst;

  sscanf(msg, "pin %d\n", &nb);
  lst = data->head;
  while (lst && lst->player.light.nb != nb)
    lst = lst->next;
  if (lst != NULL && nb > 0)
    {
      s = s_playerinv(&(lst->player.light));
      send(g->fd, s, strlen(s), 0);
    }
  else
    {
      s = s_badpara();
      send(g->fd, s, strlen(s), 0);
    }
  free(msg);
  free(s);
  return (0);
}

int		sgt(t_init *data, t_player *g, char *msg)
{
  char		*s;

  (void) msg;
  s = s_servtim(data->speed);
  send(g->fd, s, strlen(s), 0);
  free(msg);
  free(s);
  return (0);
}

int		sst(t_init *data, t_player *g, char *msg)
{
  int		nb;
  char		*s;

  (void) g;
  sscanf(msg, "sst %d\n", &nb);
  if (nb <= 0)
    {
      s = s_badpara();
      send(g->fd, s, strlen(s), 0);
    }
  else
    data->speed = abs(nb);
  free(msg);
  free(s);
  return (0);
}
