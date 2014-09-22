/*
** check_timer.c for  in /home/tolsa_c//zappy-2015-2014s-tolsa_c/withtimer
**
** Made by camille tolsa
** Login   <tolsa_c@epitech.net>
**
** Started on  Sun Jun 24 12:08:22 2012 camille tolsa
** Last update Thu Jun 28 21:00:25 2012 bertrand boyer
*/

#include "./serveur.h"

int		check_timer(t_init *data)
{
  t_player_lst	*tmp;

  tmp = data->head;
  while (tmp != NULL)
    {
      update_timer(&(tmp->player));
      if (istimeout(&(tmp)->player) == 1)
	functions(data, &(tmp->player),
		  tmp->player.buf.read_buffer(&(tmp->player.buf)));
      if (tmp->player.buf.c > 0 && istimeout(&(tmp)->player) == 0)
	setup_timer(&(tmp->player), data);
      tmp = tmp->next;
    }
  return (0);
}
