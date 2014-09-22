/*
** main.c for serveur in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Fri Jun 29 15:52:36 2012 bertrand boyer
** Last update Tue Jul  3 22:55:39 2012 camille
*/

#include "./serveur.h"

t_init		*g_data;

/* while (data->team_name[y] != '\0') */
/*   free(data->team_name[y++]); */
/* free(data->team_name); */
int		free_all(t_init *data)
{
  int		y;
  int		x;

  y = -1;
  while (++y != data->height)
    {
      x = -1;
      while (++x != data->width)
	free(data->map[y][x]);
      free(data->map[y]);
    }
  y = 0;
  return (0);
}

void			ctrl_c(int sig)
{
  t_player_lst		*tmp;

  (void) sig;
  printf("\nServeur interrupted !\n");
  printf("Freeing players.\n");
  tmp = g_data->head;
  while (tmp != NULL)
    {
      del_player(tmp->player.fd, g_data);
      tmp = tmp->next;
    }
  printf("Freeing map.\n");
  free_all(g_data);
  printf("Closing socket.\n");
  close(g_data->socket);
  exit(0);
}

int			main(int ac, char **av)
{
  int			flag_exit;
  struct sockaddr_in	sin;
  t_init		data;

  g_data = &data;
  signal(SIGPIPE, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  srand(time(NULL));
  if (get_option_init(ac, av, &data) == -1 || fillstruct(&sin, &data) == -1)
    return (-1);
  if ((bind(data.socket, (const struct sockaddr *) &sin, sizeof(sin))) == -1)
    return (merror("bind"));
  else
    printf(STR_LISTENING, data.port);
  if ((listen(data.socket, 1000)) == -1)
    return (merror("listen"));
  aff_options(&data);
  flag_exit = 0;
  signal(SIGINT, ctrl_c);
  while (flag_exit != -1)
    flag_exit = monitor(&data);
  close(data.socket);
  free_all(&data);
  printf("Job done !\n");
  return (EXIT_SUCCESS);
}
