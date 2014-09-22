/*
** expulse.c for  in /home/tolsa_c//appy
**
** Made by camille tolsa
** Login   <tolsa_c@epitech.net>
**
** Started on  Wed Jun 20 08:38:41 2012 camille tolsa
** Last update Sat Jul 14 15:15:50 2012 mathieu barnetche
*/

#include "./serveur.h"

void		goU(t_player *p, int mapx, int mapy, int fd)
{
  char		*s;

  (void) mapx;
  s = s_playerexp(&(p->light));
  send(fd, s, strlen(s), 0);
  p->light.pos.y = (p->light.pos.y - 1) % mapy;
  send(fd, s, strlen(s), 0);
  free(s);
  s = NULL;
  s = s_playerpos(&(p->light));
  send(fd, s, strlen(s), 0);
  send(p->fd, "deplacement: N\n", 15, 0);
  free(s);
}

void		goR(t_player *p, int mapx, int mapy, int fd)
{
  char		*s;

  (void) mapy;
  s = s_playerexp(&(p->light));
  send(fd, s, strlen(s), 0);
  p->light.pos.x = (p->light.pos.x + 1) % mapx;
  free(s);
  s = NULL;
  s = s_playerpos(&(p->light));
  send(fd, s, strlen(s), 0);
  send(p->fd, "deplacement: E\n", 15, 0);
  free(s);
}

void		goD(t_player *p, int mapx, int mapy, int fd)
{
  char		*s;

  (void) mapx;
  s = s_playerexp(&(p->light));
  send(fd, s, strlen(s), 0);
  p->light.pos.y = (p->light.pos.y + 1) % mapy;
  free(s);
  s = NULL;
  s = s_playerpos(&(p->light));
  send(fd, s, strlen(s), 0);
  send(p->fd, "deplacement: S\n", 15, 0);
  free(s);
}

void		goL(t_player *p, int mapx, int mapy, int fd)
{
  char		*s;

  (void) mapy;
  s = s_playerexp(&(p->light));
  send(fd, s, strlen(s), 0);
  p->light.pos.x = (p->light.pos.x - 1) % mapx;
  free(s);
  s = NULL;
  s = s_playerpos(&(p->light));
  send(fd, s, strlen(s), 0);
  send(p->fd, "deplacement: O\n", 15, 0);
  free(s);
}

int		expel(t_init *d, t_player *p, char *msg)
{
  t_player_lst  *tmp;
  t_expluse	tab[4];
  int		i;

  (void) msg;
  tab[0].d = UP;
  tab[0].kick = goU;
  tab[1].d = RIGHT;
  tab[1].kick = goR;
  tab[2].d = DOWN;
  tab[2].kick = goD;
  tab[3].d = LEFT;
  tab[3].kick = goL;
  tmp = d->head;
  while (tmp != NULL && (i = -1))
    {
      if (&(tmp->player) != p && tmp->player.light.pos.x == p->light.pos.x
	  && tmp->player.light.pos.y == p->light.pos.y)
	while (++i < 4)
	  if (tab[i].d == p->light.dir)
	    tab[i].kick(&(tmp->player), d->width, d->height, d->fd_graphic);
      tmp = tmp->next;
    }
  p->ans.write_buffer(&(p->ans), "ok\n");
  return (0);
}
