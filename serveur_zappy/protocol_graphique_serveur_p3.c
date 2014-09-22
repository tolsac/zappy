/*
** serveur_protocol_graphique_p3.c for serveur_protocol_graphique_p3 in /home/nerevarine/Documents
**
** Made by nerevarine
** Login   <nerevarine@scarlett>
**
** Started on Tue Jun 12 18:20:51 2012 nerevarine
** Last update Sun Jul 15 09:33:32 2012 camille tolsa
*/

#include "./serveur.h"

char		*s_playerexp(t_light *p)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pex %d\n", p->nb);
  return (s);
}

char		*s_playerbro(t_light *p, char *m)
{
  char		*s;
  int		i;

  i = STR_SIZE + strlen(m) + 1;
  if ((s = xmalloc((STR_SIZE + i) * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, i);
  snprintf(s, i, "pbc %d %s\n", p->nb, m);
  return (s);
}

char		*s_playerinc(t_player *p)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pic %d %d %d %d\n", p->light.pos.x,
	   p->light.pos.y, p->light.lvl, p->light.nb);
  return (s);
}

char		*s_playerend(int x, int y, int res)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pie %d %d %d\n", x, y, res);
  return (s);
}

char		*s_playerfrk(t_light *p)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pfk %d\n", p->nb);
  return (s);
}
