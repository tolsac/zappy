/*
** message.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Tue May 29 20:12:43 2012 baptiste bourlet-de-la-vallee
** Last update Wed Jul 11 14:48:03 2012 vincent biret-chaussat
*/

#include	"./serveur.h"

int		received(t_player *p, char *buf)
{
  int		ret;

  memset(buf, 0, 1024);
  ret = recv(p->fd, buf, MAX_MSG, 0);
  if (ret > 0)
    {
      buf[ret - 1] = '\n';
      p->buf.write_buffer(&(p->buf), buf);
      buf[ret - 1] = '\0';
      printf("\033[33;35mReceived \"\033[33;0m%s\033[33;35m\" ", buf);
      printf("from %d\033[33;0m\n", p->light.nb);
    }
  return (ret);
}

int		sending(t_init *data, t_player *p, char *msg)
{
  int		ret;

  FD_SET(p->fd, &(data->write));
  if (FD_ISSET(p->fd, &(data->write)))
    {
      write(1, "\033[33;35mSending \"\033[33;0m",
	    strlen("\033[33;35mSending \"\033[33;0m"));
      write(1, msg, strlen(msg) - 1);
      printf("\033[33;35m\" to %d\033[33;0m\n", p->light.nb);
      ret = send(p->fd, msg, strlen(msg), 0);
      return (ret);
    }
  else
    del_player(p->fd, data);
  return (0);
}

