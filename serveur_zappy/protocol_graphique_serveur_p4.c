/*
** serveur_protocol_graphique_p4.c for serveur_protocol_graphique_p4 in /home/nerevarine/Documents
**
** Made by nerevarine
** Login   <nerevarine@scarlett>
**
** Started on Fri Jun 15 15:28:08 2012 nerevarine
** Last update Sat Jun 30 19:46:37 2012 bertrand boyer
*/

#include "./serveur.h"

char		*s_playerdro(t_light *p, int ressource)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pdr %d %d\n", p->nb, ressource);
  return (s);
}

char		*s_playerget(t_light *p, int ressource)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pgt %d %d\n", p->nb, ressource);
  return (s);
}

char		*s_playerdie(t_light *p)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "pdi %d\n", p->nb);
  return (s);
}
