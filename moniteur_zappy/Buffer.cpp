/*
** Buffer.cpp for  in /home/camille/zappy-2015-2014s-tolsa_c/client_zappy
**
** Made by camille
** Login   <camille@epitech.net>
**
** Started on  Wed Jul  4 00:18:40 2012 camille
** Last update Sat Jul  7 15:40:07 2012 bertrand boyer
*/


#include		"Buffer.hh"

Buffer::Buffer()
{
  if (memset(this->buf, 0, BUFFER_SIZE) == NULL)
    std::cout << "Error with buffer init." << std::endl;
  this->w = 0;
  this->r = 0;
  this->c = 0;
}

Buffer::~Buffer()
{
}

int		Buffer::write_buffer(const std::string& s)
{
  int                   i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '\n')
        {
	  this->buf[this->w] = '\n';
          this->w = (this->w + 1) % BUFFER_SIZE;
          this->buf[this->w] = '\0';
          this->w = (this->w + 1) % BUFFER_SIZE;
          this->c++;
	}
      else
        {
          this->buf[this->w] = s[i];
          this->w = (this->w + 1) % BUFFER_SIZE;
	}
      i++;
    }
  // if (s[i - 1] != '\n')
  //   {
  //     this->w = (this->w + 1) % BUFFER_SIZE;
  //   }
  return (i);


}

std::string		Buffer::read_buffer()
{
  std::string		s = "";

  if (this->w == this->r)
    return ("");
  while (this->buf[this->r])
    {
      s += this->buf[this->r];
      this->r = (this->r + 1) % BUFFER_SIZE;
    }
  this->c--;
  this->r = (this->r + 1) % BUFFER_SIZE;
  return (s);
}

std::string		Buffer::get()
{
  int			i;
  int			j;
  std::string		s = "";

  if (this->w == this->r)
    return ("");
  i = this->r;
  j = 0;
  while (this->buf[i])
    {
      s += this->buf[i];
      i = (i + 1) % BUFFER_SIZE;
    }
  return (s);
}

void		Buffer::clear_buffer()
{
  this->w = 0;
  this->r = 0;
  this->c = 0;
  memset(this->buf, 0, BUFFER_SIZE);
}
