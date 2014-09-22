//
// connexion.hh for  in /home/tolsa_c//zappy-2015-2014s-tolsa_c/client_zappy
// 
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
// 
// Started on  Fri Jun 29 10:41:23 2012 camille tolsa
// Last update Fri Jun 29 11:27:15 2012 camille tolsa
//

#ifndef __CONNEXION__
#define __CONNEXION__

#include <iostream>
#include <sstream>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

class			Connexion
{
public:
  Connexion(std::string const& ip, int port);
  ~Connexion();

  bool			isValid() const;
  int			getFd() const;

private:
  void			err(std::string const&);
  
  bool			valid;
  int                   fd;
  struct protoent       *s_proto;
  struct sockaddr_in    sin;
};
#endif
