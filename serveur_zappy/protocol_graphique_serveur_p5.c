/*
** serveur_protocol_graphique_p5.c for serveur_protocol_graphique_p5 in /home/nerevarine/Documents
**
** Made by nerevarine
** Login   <nerevarine@scarlett>
**
** Started on Fri Jun 15 15:40:48 2012 nerevarine
** Last update Sat Jun 30 19:46:27 2012 bertrand boyer
*/

#include "./serveur.h"

char		*s_eggnew(t_light *egg, t_light *p)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "enw %d %d %d %d\n",
	   egg->nb, p->nb, p->pos.x, p->pos.y);
  return (s);
}

char		*s_eggend(t_light *egg)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "eht %d\n", egg->nb);
  return (s);
}

char		*s_eggcon(t_light *egg)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "ebo %d\n", egg->nb);
  return (s);
}

char		*s_eggdie(t_light *egg)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "edi %d\n", egg->nb);
  return (s);
}
