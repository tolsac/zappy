/*
** buffer_static.c for zappy in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Sat Jun 30 19:40:54 2012 bertrand boyer
** Last update Thu Jul 12 09:01:46 2012 camille tolsa
*/

#include "./structures.h"

int		write_buffer(struct s_buffer *b, char *s)
{
  int			i;

  i = -1;
  while (s[++i])
    if (s[i] == '\n')
      {
	b->buf[b->w] = '\n';
	b->w = (b->w + 1) % BUFFER_SIZE;
	b->buf[b->w] = '\0';
	b->w = (b->w + 1) % BUFFER_SIZE;
	b->c++;
      }
    else
      {
	b->buf[b->w] = s[i];
	b->w = (b->w + 1) % BUFFER_SIZE;
      }
  return (i);
}

char		*read_buffer(struct s_buffer *b)
{
  int			j;
  char			*s;

  if (b->w == b->r)
    return (NULL);
  s = malloc(BUFFER_SIZE);
  j = 0;
  while (b->buf[b->r])
    {
      s[j++] = b->buf[b->r];
      b->r = (b->r + 1) % BUFFER_SIZE;
    }
  b->c--;
  b->r = (b->r + 1) % BUFFER_SIZE;
  s[j] = '\0';
  if (s[j - 1] != '\n')
    {
      b->r = (b->r - j) % BUFFER_SIZE;
      return (NULL);
    }
  return (s);
}

char		*get(struct s_buffer *b)
{
  int			i;
  int			j;
  char			*s;

  if (b->w == b->r)
    return (NULL);
  s = malloc(BUFFER_SIZE);
  i = b->r;
  j = 0;
  while (b->buf[i])
    {
      s[j++] = b->buf[i];
      i = (i + 1) % BUFFER_SIZE;
    }
  s[j] = '\0';
  if (s[j - 1] != '\n')
    return (NULL);
  return (s);
}

void		clear_buffer(t_buffer *b)
{
  b->w = 0;
  b->r = 0;
  b->c = 0;
  memset(b->buf, 0, BUFFER_SIZE);
}
