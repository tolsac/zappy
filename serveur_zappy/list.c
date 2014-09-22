/*
** list.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Mon May 21 22:59:36 2012 baptiste bourlet-de-la-vallee
** Last update Mon Jul  2 13:49:08 2012 bertrand boyer
*/

#include	"./serveur.h"

int		new_player(int socket_client, t_init *data)
{
  t_player_lst	*node;

  if ((node = xmalloc(sizeof(t_player_lst) * 2)) == NULL)
    return (-1);
  else
    {
      init_all(node, socket_client, data);
      if (data->head == NULL)
	{
	  data->head = node;
	  data->tail = data->head;
	  data->tail->next = NULL;
	}
      else
	{
	  data->tail->next = (struct s_player_lst *)node;
	  data->tail = node;
	}
      set_fd(data);
      if ((sending(data, &(node->player), "BIENVENUE\n")) == -1)
	return (merror("send"));
    }
  return (0);
}

void		send_die(t_player *p, t_init *data)
{
  char		*s;

  s = s_playerdie(&(p->light));
  send(data->fd_graphic, s, strlen(s), 0);
  free(s);
}

int		init_delete(t_init *data, t_player_lst *save)
{
  printf("\033[33;36mDeleting player %d\033[33;0m\n", save->player.light.nb);
  send_die(&(save->player), data);
  FD_CLR(save->player.fd, &(data->read));
  FD_CLR(save->player.fd, &(data->write));
  close(save->player.fd);
  free(save->player.light.team);
  return (0);
}

t_player_lst	*del_player(int socket_client, t_init *data)
{
  t_player_lst	*save;
  t_player_lst	*tmp;

  save = data->head;
  while (save != NULL && save->player.fd != socket_client)
    save = save->next;
  init_delete(data, save);
  tmp = data->head;
  while (tmp->next && tmp->next != (struct s_player_lst *) save)
    tmp = tmp->next;
  if (save == data->head)
    if (save->next != NULL)
      data->head = (t_player_lst *) save->next;
    else
      data->head = NULL;
  else if (save == data->tail)
    {
      data->tail = tmp;
      data->tail->next = NULL;
    }
  else
    tmp->next = save->next;
  free(save);
  return (tmp);
}
