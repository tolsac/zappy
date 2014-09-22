/*
** serveur_protocol_graphique_p2.c for serveur_protocol_graphique_p2 in /home/nerevarine/Documents
**
** Made by nerevarine
** Login   <nerevarine@scarlett>
**
** Started on Tue Jun 12 17:54:07 2012 nerevarine
** Last update Sat Jun 30 19:47:26 2012 bertrand boyer
*/

#include "./serveur.h"

char		*s_playernew(t_light *p)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pnw %d %d %d %d %d %s\n",
	   p->nb, p->pos.x, p->pos.y,
	   p->dir, p->lvl, p->team);
  return (s);
}

char		*s_playerpos(t_light *p)
{
  char		*s;
  int		gooddir;

  gooddir = 1;
  if (p->dir == 3)
    gooddir = 2;
  else if (p->dir == 5)
    gooddir = 3;
  else if (p->dir == 7)
    gooddir = 4;
  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "ppo %d %d %d %d\n",
	   p->nb, p->pos.x, p->pos.y, gooddir);
  return (s);
}

char		*s_playerlvl(t_light *p)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "plv %d %d\n", p->nb, p->lvl);
  return (s);
}

char		*s_playerinv(t_light *p)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pin %d %d %d %d %d %d %d %d %d %d\n",
	   p->nb, p->pos.x, p->pos.y, p->inv[0], p->inv[1], p->inv[2],
	   p->inv[3], p->inv[4], p->inv[5], p->inv[6]);
  return (s);
}
