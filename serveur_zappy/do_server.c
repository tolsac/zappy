/*
** do_server.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Mon May 21 22:54:21 2012 baptiste bourlet-de-la-vallee
** Last update Tue Jun 26 07:38:33 2012 camille tolsa
*/

#include	"./serveur.h"

int		do_server(t_init *data)
{
  int			socket_client;
  int			client_len;
  struct sockaddr_in	sin_client;

  client_len = sizeof(sin_client);
  if ((socket_client = accept(data->socket, (struct sockaddr *)&sin_client,
			      (socklen_t *)&client_len)) == -1)
    return (merror("accept"));
  else
    {
      printf("\033[33;36mNew client from %s:%d\033[33;0m\n",
	     inet_ntoa(sin_client.sin_addr), ntohs(sin_client.sin_port));
      return (new_player(socket_client, data));
    }
  return (0);
}
