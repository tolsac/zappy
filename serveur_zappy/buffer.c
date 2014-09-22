/*
** buffer.c for  in /home/tolsa_c//zappy/circular_buffer
**
** Made by camille tolsa
** Login   <tolsa_c@epitech.net>
**
** Started on  Mon Jun 11 11:49:43 2012 camille tolsa
** Last update Wed Jul 11 17:51:35 2012 bertrand boyer
*/

#include "./serveur.h"

void		init_buffer(t_buffer *b)
{
  if (memset(b->buf, 0, BUFFER_SIZE) == NULL)
    printf("Error with buffer init.\n");
  b->write_buffer = write_buffer;
  b->read_buffer = read_buffer;
  b->clear_buffer = clear_buffer;
  b->get = &get;
  b->w = 0;
  b->r = 0;
  b->c = 0;
}
