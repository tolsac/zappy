//
// connexion.cpp for  in /home/tolsa_c//zappy-2015-2014s-tolsa_c/client_zappy
// 
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
// 
// Started on  Fri Jun 29 10:46:39 2012 camille tolsa
// Last update Sun Jul  1 21:05:04 2012 camille tolsa
//

#include "./connexion.hh"

Connexion::Connexion(std::string const& ip, int port)
{
  this->valid = true;
  if ((this->s_proto = getprotobyname("TCP")) == NULL)
    err("getprotobyname");
  if ((this->fd = socket(AF_INET, SOCK_STREAM, this->s_proto->p_proto)) == -1)
    err("socket");
  this->sin.sin_family = AF_INET;
  this->sin.sin_addr.s_addr = inet_addr(ip.c_str());
  this->sin.sin_port = htons(port);
  if ((connect(this->fd,
               (const struct sockaddr *)&(this->sin),
               sizeof(this->sin))) == -1)
    err("connect");
}

Connexion::~Connexion()
{
  
}

void Connexion::err(std::string const& msg)
{
  perror(msg.c_str());
  std::cout << "./client" << ": Usage [IP ADDR] [PORT] [TEAM]" << std::endl;
  exit(0);
}

int Connexion::getFd()  const
{
  return (this->fd);
}

bool		Connexion::isValid() const
{
  return (this->valid);
}
