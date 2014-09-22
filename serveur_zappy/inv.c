/*
** temporary.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Thu May 31 13:57:31 2012 baptiste bourlet-de-la-vallee
** Last update Thu Jun 28 20:53:32 2012 bertrand boyer
*/

#include	"serveur.h"

int		inventory(t_init *data, t_player *p, char *msg)
{
  char		s[255];

  (void)data;
  (void)msg;
  sprintf(s, INV_FORMAT,
	  p->light.inv[0], p->light.inv[1], p->light.inv[2], p->light.inv[3],
	  p->light.inv[4], p->light.inv[5], p->light.inv[6]);
  p->ans.write_buffer(&(p->ans), s);
  return (0);
}
