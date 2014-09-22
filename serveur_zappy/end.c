/*
** end.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project/serveur_zappy
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Sun Jul 15 16:01:39 2012 baptiste bourlet-de-la-vallee
** Last update Sun Jul 15 18:11:37 2012 bertrand boyer
*/

#include	"serveur.h"

void		do_the_end(t_init *data, char *name)
{
  char		*str;
  t_player_lst	*list;

  str = xmalloc(STR_SIZE);
  sprintf(str, "The team who won is %s !\nWe hope you was in this team !\n",
	  name);
  list = data->head;
  while (list)
    {
      if (list->player.graphic == 0)
	{
	  if (list->player.ghost == 0)
	    sending(data, &(list->player), str);
	  del_player(list->player.fd, data);
	}
      list = list->next;
    }
  free(str);
  str = s_endgame(name);
  send(data->fd_graphic, str, strlen(str), 0);
  free(str);
}

int		check_lvl_players(t_init *data, t_player_lst *tmp)
{
  t_player_lst	*tmp_2;
  int		cpt;

  tmp_2 = data->head;
  cpt = 0;
  while (cpt < 6 && tmp_2)
    {
      if (tmp_2->player.graphic == 0 && tmp_2->player.ghost == 0 &&
	  ((strcmp(tmp_2->player.light.team, tmp->player.light.team)) == 0) &&
	  tmp_2->player.light.lvl == 8)
	cpt++;
      tmp_2 = tmp_2->next;
    }
  if (cpt == 6)
    {
      do_the_end(data, tmp->player.light.team);
      return (1);
    }
  return (0);
}

void		test_end(t_init *data)
{
  t_player_lst	*tmp;
  int		ret;

  tmp = data->head;
  ret = 0;
  while (ret == 0 && tmp)
    {
      if (tmp->player.graphic == 0 && tmp->player.ghost == 0 &&
	  tmp->player.light.lvl == 8)
	ret = check_lvl_players(data, tmp);
      if (ret == 0)
	tmp = tmp->next;
    }
}
