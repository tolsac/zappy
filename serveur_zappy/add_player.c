/*
** add_player.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Tue May 29 18:58:38 2012 baptiste bourlet-de-la-vallee
** Last update Sat Jul 14 13:44:21 2012 bertrand boyer
*/

#include	"./serveur.h"

int		nb_place_dispo(t_init *data, char *name)
{
  t_player_lst	*tmp;
  int		nb;

  tmp = data->head;
  nb = data->players_allowed;
  while (tmp)
    {
      if (name && tmp->player.light.team
	  && (strcmp(name, tmp->player.light.team)) == 0)
	nb--;
      tmp = tmp->next;
    }
  return (nb);
}

int		find_team(t_init *data, t_player_lst *p, char *name)
{
  int		x;
  char		*s;

  if ((x = -1) && strncmp(name, "GRAPHIC", 7) == 0)
    return (add_player_graphic(data, p));
  while (data->team_name[++x] != NULL)
    if ((strncmp(name, data->team_name[x], strlen(data->team_name[x]))) == 0)
      {
	if ((nb_place_dispo(data, name)) > 0)
	  {
	    p->player.graphic = 0;
	    p->player.light.team = xmalloc(strlen(name) + 2);
	    bzero(p->player.light.team, strlen(name) + 2);
	    sprintf(p->player.light.team, "%s", name);
	    s = s_playernew(&(p->player.light));
	    send(data->fd_graphic, s, strlen(s), 0);
	    free(s);
	    return (0);
	  }
	else
	  return (connection_to_egg(data, p, name));
      }
  return (1);
}

int		conversation(t_init *data, t_player_lst *p, char *buf)
{
  int		ret;

  if ((fcntl(p->player.fd, F_SETFL,
	     fcntl(p->player.fd, F_GETFL) | O_NONBLOCK)) < 0)
    return (merror("fcntl"));
  ret = find_team(data, p, buf);
  if (ret == 2)
    send_all(data, &(p->player));
  if (ret == 1 && (sending(data, &(p->player), "ko\n")) == -1)
    return (merror("send"));
  return (ret);
}

int		add_player(t_init *data, t_player_lst *p, char *buf)
{
  int		ret;
  char		*msg;

  if (buf == NULL)
    return (0);
  if ((ret = conversation(data, p, buf)) == 0)
    {
      msg = xmalloc(MAX_MSG);
      bzero(msg, MAX_MSG);
      sprintf(msg, "%d\n", nb_place_dispo(data, p->player.light.team));
      sending(data, &(p->player), msg);
      bzero(msg, MAX_MSG);
      sprintf(msg, "%d %d\n", data->width, data->height);
      sending(data, &(p->player), msg);
      free(msg);
    }
  return (ret);
}

int		add_player_graphic(t_init *data, t_player_lst *p)
{
  p->player.light.team = xmalloc(7);
  sprintf(p->player.light.team, "%s", "GRAPHIC");
  p->player.graphic = 1;
  data->fd_graphic = p->player.fd;
  return (2);
}
