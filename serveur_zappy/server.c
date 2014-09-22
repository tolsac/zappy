/*
** server.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Mon May 21 11:44:41 2012 baptiste bourlet-de-la-vallee
** Last update Sun Jul 15 16:01:59 2012 baptiste bourlet-de-la-vallee
*/

#include		"./serveur.h"

int			max(t_init *data)
{
  t_player_lst		*tmp;
  int			x;

  tmp = data->head;
  x = 3;
  while (tmp != NULL)
    {
      if (tmp->player.fd > x)
	x = tmp->player.fd;
      tmp = tmp->next;
    }
  return (x);
}

void			set_fd(t_init *data)
{
  t_player_lst		*tmp;

  FD_ZERO(&(data->read));
  FD_ZERO(&(data->write));
  FD_SET(data->socket, &(data->read));
  tmp = data->head;
  while (tmp != NULL)
    {
      if (tmp->player.fd > 0)
	FD_SET(tmp->player.fd, &(data->read));
      tmp = tmp->next;
    }
}

int			init_monitor(t_init *data, struct timeval *tv, int *ret,
				     t_player_lst **tmp)
{
  tv->tv_sec = 0;
  tv->tv_usec = 500000;
  *ret = 0;
  set_fd(data);
  (*tmp) = data->head;
  return (0);
}

int			monitor(t_init *data)
{
  t_player_lst		*tmp;
  int			ret;
  struct timeval	tv;
  int			stay;

  init_monitor(data, &tv, &ret, &tmp);
  if ((select(max(data) + 1, &(data->read), &(data->write), NULL, &tv)) == -1)
    return (merror("select"));
  if (FD_ISSET(data->socket, &(data->read)))
    ret = do_server(data);
  else
    {
      stay = 1;
      while (stay && tmp != NULL)
	{
	  if (ret == 0 && FD_ISSET(tmp->player.fd, &(data->read)))
	    stay = do_client(tmp->player.fd, &tmp, data);
	  else
	    ret = 0;
	  tmp = tmp->next;
	}
    }
  check_timer(data);
  test_end(data);
  return (0);
}

int			fillstruct(struct sockaddr_in *sin, t_init *data)
{
  struct protoent	*s_proto;

  if ((s_proto = getprotobyname("TCP")) == NULL)
    return (merror("getprotobyname"));
  if ((data->socket = socket(AF_INET, SOCK_STREAM,
			     s_proto->p_proto)) == -1)
    return (merror("socket"));
  sin->sin_family = AF_INET;
  sin->sin_addr.s_addr = INADDR_ANY;
  sin->sin_port = htons(data->port);
  data->head = NULL;
  data->cmd = xmalloc(sizeof(char *) * (NB_FCT + 1));
  data->time = xmalloc(sizeof(float) * (NB_FCT + 1));
  if (data->cmd == NULL || data->time == NULL)
    return (-1);
  return (1);
}
