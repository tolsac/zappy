/*
** new_inc.c for in /home/tolsa_c/zappy
**
** Made by camille tolsa
** Login   camille
**
** Started on  Thu Jul 12 19:29:29 2012 camille tolsa
** Last update Sun Jul 15 18:06:32 2012 bertrand boyer
*/

#include	"./serveur.h"

extern t_init	*g_data;

int		how_many_players_on_my_case(t_init *data,
					    int x, int y, int level)
{
  t_player_lst	*tmp;
  int		how_many;

  how_many = 0;
  tmp = data->head;
  while (tmp)
    {
      if (tmp->player.ghost != 1 &&
	  tmp->player.light.lvl > 0 && tmp->player.graphic != 1)
	if (tmp->player.light.pos.x == x && tmp->player.light.pos.y == y)
	  if (tmp->player.light.lvl == level)
	    how_many++;
      tmp = tmp->next;
    }
  return (how_many);
}

int		is_there_enough_ressources(t_init *data,
					   int x, int y, int level)
{
  int			i;
  static int		conditions[7][6] = {{1, 0, 0, 0, 0, 0},
					    {1, 1, 1, 0, 0, 0},
					    {2, 0, 1, 0, 2, 0},
					    {1, 1, 2, 0, 1, 0},
					    {1, 2, 1, 3, 0, 0},
					    {1, 2, 3, 0, 1, 0},
					    {2, 2, 2, 2, 2, 1}};

  i = 1;
  while (data->map[y][x][i] == conditions[level - 1][i - 1] && i < 7)
    i++;
  if (i == 7)
    return (1);
  return (0);
}

void		send_msg_to_monitor(t_init *data, t_player *p, char *msg)
{
  char		*s;

  if (msg[0] == 'k')
    s = s_playerend(p->light.pos.x, p->light.pos.y, 0);
  else if (msg[0] == 'n')
    s = s_playerend(p->light.pos.x, p->light.pos.y, 1);
  else if (msg[0] == 'e')
    s = s_playerinc(p);
  if (-1 == send(data->fd_graphic, s, strlen(s), 0))
    perror("send");
  free(s);
}

void		send_msg_to_all(t_init *data, t_player *p, char *msg, int flag)
{
  t_player_lst	*tmp;

  tmp = data->head;
  while (tmp)
    {
      if (tmp->player.ghost != 1 &&
	  tmp->player.light.lvl > 0 && tmp->player.graphic != 1)
	if (tmp->player.light.pos.x == p->light.pos.x &&
	    tmp->player.light.pos.y == p->light.pos.y)
	  if (tmp->player.light.lvl == p->light.lvl && &(tmp->player) != p)
	    {
	      if (flag == 1)
		tmp->player.light.lvl++;
	      sending(data, &(tmp->player), msg);
	    }
      tmp = tmp->next;
    }
  if (flag == 1)
    p->light.lvl++;
  if (flag == 0)
    p->ans.write_buffer((&p->ans), msg);
  else
    sending(data, p, msg);
  send_msg_to_monitor(data, p, msg);
}

int             incantation(t_init *data, t_player *p, char *msg)
{
  static int		people[7] = {1, 2, 2, 4, 4, 6, 6};

  (void)msg;
  if (how_many_players_on_my_case(data,
				  p->light.pos.x,
				  p->light.pos.y,
				  p->light.lvl)
      >= people[p->light.lvl - 1])
    if (is_there_enough_ressources(data,
				   p->light.pos.x,
				   p->light.pos.y,
				   p->light.lvl))
      {
	send_msg_to_all(data, p, "elevation en cours\n", 0);
	p->incant = (300 / data->speed) + time(NULL);
	return (1);
      }
  send_msg_to_all(data, p, "ko\n", 0);
  return (0);
}

int             incantation_end(t_init *data, t_player *p)
{
  static int		people[7] = {1, 2, 2, 4, 4, 6, 6};
  char			*m;

  m = xmalloc(128);
  p->incant = 0;
  if (how_many_players_on_my_case(data,
				  p->light.pos.x,
				  p->light.pos.y,
				  p->light.lvl)
      == people[p->light.lvl - 1])
    if (is_there_enough_ressources(data,
				   p->light.pos.x,
				   p->light.pos.y,
				   p->light.lvl))
      {
	sprintf(m, "niveau actuel : %d\n", p->light.lvl + 1);
	send_msg_to_all(data, p, m, 1);
	return (1);
      }
  send_msg_to_all(data, p, "ko\n", 2);
  free(m);
  return (0);
}
