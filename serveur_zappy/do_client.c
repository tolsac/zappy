/*
** do_client.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Tue May 22 00:09:00 2012 baptiste bourlet-de-la-vallee
** Last update Thu Jul 12 06:36:08 2012 camille tolsa
*/

#include	"./serveur.h"

int		do_client(int socket_client, t_player_lst **tmp, t_init *data)
{
  char		buff[MAX_MSG + 1];
  int		ret;

  if ((*tmp)->player.buf.c > 9)
    return (1);
  if ((ret = received(&((*tmp)->player), buff)) == -1)
    return (merror("recv"));
  else if (!ret)
    {
      *tmp = del_player(socket_client, data);
      return (0);
    }
  else if ((*tmp)->player.ghost == 1)
    {
      (*tmp)->player.ghost = 0;
      (*tmp)->player.timer = 0;
      ret = add_player(data, *tmp,
		       (*tmp)->player.buf.read_buffer(&((*tmp)->player.buf)));
      ((ret == 1) ? (*tmp = del_player(socket_client, data)) : 0);
      if (ret == 1)
	return (0);
    }
  else if (istimeout(&(*tmp)->player) == -1)
    setup_timer(&(*tmp)->player, data);
  return (1);
}
