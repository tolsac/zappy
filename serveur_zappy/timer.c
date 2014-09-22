/*
** timer.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Thu May 31 18:59:16 2012 baptiste bourlet-de-la-vallee
** Last update Sat Jul 14 13:50:14 2012 camille tolsa
*/

#include	"./serveur.h"

extern t_init	*g_data;

void		update_timer(t_player *p)
{
  p->start = time(NULL);
}

int		setup_timer(t_player *p, t_init *data)
{
  char		*cmd;
  int		x;

  x = -1;
  cmd = p->buf.get(&(p->buf));
  if (cmd == NULL)
    return (1);
  update_timer(p);
  p->end = 0;
  while (data->cmd[++x])
    if ((strncmp(data->cmd[x], cmd, strlen(data->cmd[x]))) == 0)
      p->end =  time(NULL) + (data->time[x] / data->speed);
  if (p->end == 0)
    {
      cmd = p->buf.read_buffer(&(p->buf));
      cmd[strlen(cmd) - 1] = '\0';
      write(1, STR_IGNORED, strlen(STR_IGNORED));
      write(1, cmd, strlen(cmd));
      write(1, STR_COMMAND, strlen(STR_COMMAND));
      free(cmd);
    }
  return (0);
}

int		istimeout(t_player *p)
{
  if (p->timer == 10 && (time(NULL) - p->save_time) >= p->timer)
    {
      del_player(p->fd, g_data);
      return (42);
    }
  if (p->graphic == 0 && p->ghost == 0 &&
      time(NULL) >= p->life + (1260 / g_data->speed))
    {
      p->life = time(NULL);
      if (p->light.inv[0] == 1)
	del_player(p->fd, g_data);
      else
	p->light.inv[0]--;
    }
  return (istimeout_next(p));
}

int		istimeout_next(t_player *p)
{
  if (p->incant != 0)
    if (time(NULL) > p->incant)
      incantation_end(g_data, p);
  if (p->start == 0 && p->end == 0)
    return (-1);
  if (p->start == 0 || p->end == 0)
    return (0);
  if (p->start >= p->end)
    return (1);
  return (42);
}
