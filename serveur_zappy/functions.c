/*
** functions.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Wed May 30 22:07:03 2012 baptiste bourlet-de-la-vallee
** Last update Fri Jul 13 19:24:49 2012 baptiste bourlet-de-la-vallee
*/

#include	"./serveur.h"

void		functions(t_init *data, t_player *p, char *msg)
{
  int		x;

  x = -1;
  while (data->cmd[++x])
    if ((strncmp(data->cmd[x], msg, strlen(data->cmd[x]))) == 0)
      {
	p->save_time = time(NULL);
	msg[strlen(msg)] = '\0';
	if (data->action[x](data, p, msg) == 0)
	  p->timer = data->time[x] / data->speed;
	else
	  p->timer = 0;
	p->start = 0;
	p->end = 0;
	if (x < 12)
	  sending(data, p, p->ans.read_buffer(&(p->ans)));
      }
}

