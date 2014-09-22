/*
** utils.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Mon May 21 11:59:31 2012 baptiste bourlet-de-la-vallee
** Last update Tue Jul  3 14:41:41 2012 bertrand boyer
*/

#include	"./serveur.h"

extern t_init	*g_data;

void		usage()
{
  printf("Usage: ./serveur [-p port] [-x width] [-y height] ");
  printf("[-c players_allowed]\n");
  printf("\t\t [-t speed] -n team_name_1 team_name_2 ...\n");
}

void		*xrealloc(void *ptr, size_t size)
{
  if ((ptr = realloc(ptr, abs(size))) == NULL)
    {
      perror("realloc");
      free_all(g_data);
    }
  return (ptr);
}

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(abs(size))) == NULL)
    {
      perror("malloc");
      free_all(g_data);
    }
  return (ptr);
}

int		merror(const char *str)
{
  perror(str);
  return (-1);
}
