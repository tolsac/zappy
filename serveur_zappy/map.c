/*
** map.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Wed May 30 00:25:23 2012 baptiste bourlet-de-la-vallee
** Last update Thu Jul 12 06:37:30 2012 camille tolsa
*/

#include	"./serveur.h"

int		*generate_stuff()
{
  int		*line;
  int		x;

  x = -1;
  line = xmalloc(sizeof(int) * 7);
  while (++x != 8)
    {
      if (rand() % 100 >= PERCENT)
      	line[x] = (rand() % 3);
    }
  return (line);
}

int		generating_map(t_init *d)
{
  int		y;
  int		x;

  d->map = xmalloc(sizeof(int **) * d->height);
  y = -1;
  while (++y != d->height)
    {
      d->map[y] = xmalloc(sizeof(int *) * d->width);
      x = -1;
      while (++x != d->width)
	{
	  d->map[y][x] = generate_stuff();
	  if ((y + 1 == d->height) && (x + 1 == d->width))
	    return (1);
	}
    }
  return (0);
}
