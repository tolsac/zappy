/*
** view.c for zappy in /home/boyer_b//Documents
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Wed Jun 20 15:37:20 2012 bertrand boyer
** Last update Wed Jul 11 12:26:26 2012 bertrand boyer
*/

#include "./serveur.h"

int		see(t_init *d, t_player *p, char *msg)
{
  char		*str;
  int		i[2];
  int		viewXY[2];
  int		lvl[8];

  str = msg;
  str = viewInit(str, lvl, i);
  viewXY[0] = p->light.pos.x;
  viewXY[1] = p->light.pos.y;
  str = strcat(append(d, p, viewXY, str), ",");
  while ((++i[0] < p->light.lvl + 1) && (i[1] = -1))
    {
      goToNextLine(d, p, viewXY, i[0]);
      while (++i[1] < lvl[i[0]])
	{
	  str = append(d, p, viewXY, str);
	  if (!((i[0] == p->light.lvl) && (i[1] == lvl[i[0]] - 1)))
	    str = strcat(str, ",");
	  goToNextCase(d, p->light.dir, viewXY);
	}
    }
  str = strcat(str, "}\n");
  p->ans.write_buffer(&(p->ans), str);
  free(str);
  return (0);
}

char		*viewInit(char *str, int lvl[8], int i[2])
{
  int		j;

  i[0] = 0;
  i[1] = 0;
  str = xmalloc(5000);
  bzero(str, 5000);
  str[0] = '{';
  lvl[0] = 1;
  j = 0;
  while (++j < 8)
    lvl[j] = lvl[j - 1] + 2;
  return (str);
}

int		goToNextLine(t_init *d, t_player *p, int viewXY[2], int lvl)
{
  if (p->light.dir == UP)
    {
      viewXY[0] = p->light.pos.x - lvl;
      viewXY[1] = p->light.pos.y - lvl;
    }
  else if (p->light.dir == RIGHT)
    {
      viewXY[0] = (p->light.pos.x + lvl) % d->width;
      viewXY[1] = p->light.pos.y - lvl;
    }
  else if (p->light.dir == DOWN)
    {
      viewXY[0] = (p->light.pos.x + lvl) % d->width;
      viewXY[1] = (p->light.pos.y + lvl) % d->height;
    }
  else if (p->light.dir == LEFT)
    {
      viewXY[0] = p->light.pos.x - lvl;
      viewXY[1] = (p->light.pos.y + lvl) % d->height;
    }
  if (viewXY[0] < 0)
    viewXY[0] = d->width + viewXY[0];
  if (viewXY[1] < 0)
    viewXY[1] = d->height + viewXY[1];
  return (0);
}

int		goToNextCase(t_init *d, t_direction dir, int viewXY[2])
{
  if (dir == UP)
    viewXY[0] = (viewXY[0] + 1) % d->width;
  else if (dir == RIGHT)
    viewXY[1] = (viewXY[1] + 1) % d->height;
  else if (dir == DOWN)
    {
      viewXY[0] = viewXY[0] - 1;
      if (viewXY[0] < 0)
	viewXY[0] = d->width - 1;
    }
  else if (dir == LEFT)
    {
      viewXY[1] = viewXY[1] - 1;
      if (viewXY[1] < 0)
	viewXY[1] = d->height - 1;
    }
  return (0);
}

char		*append(t_init *d, t_player *p, int viewXY[2], char *str)
{
  int		i;
  int		j;
  t_player_lst	*tmp;

  tmp = d->head;
  while (tmp != NULL)
    {
      if ((tmp->player.light.pos.x == viewXY[0]
	   && tmp->player.light.pos.y == viewXY[1])
	  && p != &(tmp->player)
	  && p->graphic != 1)
	str = strcat(str, d->objets[7]);
      tmp = tmp->next;
    }
  i = -1;
  while (++i < 7)
    if (d->map[viewXY[1]][viewXY[0]][i] != 0)
      {
	j = -1;
	while (++j < d->map[viewXY[1]][viewXY[0]][i])
	  str = strcat(str, d->objets[i]);
      }
  return (str);
}
