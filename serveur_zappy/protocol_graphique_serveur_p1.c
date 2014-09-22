/*
** serveur_protocol_graphique_p1.c for serveur_protocol_graphique in /home/nerevarine/Documents
**
** Made by nerevarine
** Login   <nerevarine@scarlett>
**
** Started on Tue Jun 12 16:25:47 2012 nerevarine
** Last update Sat Jun 30 19:47:42 2012 bertrand boyer
*/

#include "./serveur.h"

char		*s_mapsize(int x, int y)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "msz %d %d\n", x, y);
  return (s);
}

char		*s_sendcas(int ***map, int x, int y)
{
  char		*s;

  if ((s = xmalloc(STR_SIZE * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, STR_SIZE);
  snprintf(s, STR_SIZE, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
	   map[y][x][0], map[y][x][1], map[y][x][2], map[y][x][3],
	   map[y][x][4], map[y][x][5], map[y][x][6]);
  return (s);
}

char		*s_sendmap(int ***map, int l, int h)
{
  char		*s;
  char		tmp[STR_SIZE];
  int		i;
  int		j;

  j = STR_SIZE * l * h + 1;
  if ((s = xmalloc(j * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, j);
  i = -1;
  while (++i < h)
    {
      j = -1;
      while (++j < l)
	{
	  bzero(tmp, STR_SIZE);
	  snprintf(tmp, STR_SIZE, "bct %d %d %d %d %d %d %d %d %d\n", j, i,
		   map[i][j][0], map[i][j][1], map[i][j][2], map[i][j][3],
		   map[i][j][4], map[i][j][5], map[i][j][6]);
	  strcat(s, tmp);
	}
    }
  return (s);
}

char		*s_sendtea(char **team_name)
{
  char		*s;
  char		tmp[STR_SIZE];
  int		l;
  int		i;
  int		j;

  i = 0;
  while (team_name[i] != '\0' && i++);
  l = STR_SIZE * i + 1;
  if ((s = xmalloc(l * sizeof(char))) == NULL)
    return (NULL);
  bzero(s, l);
  j = -1;
  while (++j < i + 1)
    {
      bzero(tmp, STR_SIZE);
      snprintf(tmp, STR_SIZE, "tna %s\n", team_name[j]);
      strcat(s, tmp);
    }
  return (s);
}
