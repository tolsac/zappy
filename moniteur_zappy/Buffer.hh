/*
** Buffer.hh for moniteur in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Fri Jul  6 17:18:43 2012 bertrand boyer
** Last update Fri Jul  6 17:18:45 2012 bertrand boyer
*/


#ifndef		__BUFFER_HH__
#define		__BUFFER_HH__

#define	BUFFER_SIZE	20000
#define	MAX_MSG		1024

#include <string>
#include <cstring>
#include <cmath>
#include <iostream>

class Buffer
{
private:
  char		buf[BUFFER_SIZE];
  int		w;
  int		r;
  int		c;

public:
  Buffer();
  ~Buffer();
  int		write_buffer(const std::string& s);
  std::string	read_buffer();
  std::string	get();
  void		clear_buffer();
};

#endif
