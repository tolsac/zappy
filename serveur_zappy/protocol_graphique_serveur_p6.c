/*
** serveur_protocol_graphique_p6.c for serveur_protocol_graphique_p6 in /home/nerevarine/Documents
**
** Made by nerevarine
** Login   <nerevarine@scarlett>
**
** Started on Fri Jun 15 15:48:23 2012 nerevarine
** Last update Sat Jun 30 19:46:15 2012 bertrand boyer
*/

#include "./serveur.h"

char		*s_servtim(int speed)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "sgt %d\n", speed);
  return (s);
}

char		*s_endgame(char *team)
{
  char		*s;
  int		i;

  i = STR_SIZE + strlen(team);
  if ((s = xmalloc(i * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, i);
  snprintf(s, i, "seg %s\n", team);
  return (s);
}

char		*s_message(char *msg)
{
  char		*s;
  int		i;

  i = STR_SIZE + strlen(msg);
  if ((s = xmalloc(i * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, i);
  snprintf(s, i, "smg %s\n", msg);
  return (s);
}

char		*s_unkncmd()
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "suc\n");
  return (s);
}

char		*s_badpara()
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "sbp\n");
  return (s);
}
