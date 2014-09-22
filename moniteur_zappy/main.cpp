/*
** main.c for monitor in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 18:04:19 2012 bertrand boyer
// Last update Tue Jul 10 18:13:42 2012 bertrand boyer
*/

#include <sstream>

#include "./Monitor.hh"

int			main(int ac, char **av)
{
  int			port;
  std::string		ip;
  std::istringstream	ss;
  Monitor		m;

  if (ac == 3)
    {
      ip.assign(av[1]);
      ss.str(av[2]);
      ss >> port;
      if (1023 < port)
	{
	  if (m.connexion(ip.c_str(), port) != -1)
	    {
	      m.startReception();
	      m.mainLoop();
	    }
	}
      else
	std::cout << "Error: PORT < 1024." << std::endl;
    }
  else
    std::cout << "Usage: " << av[0] << " IP PORT. (1023 < PORT)." << std::endl;
  return (0);
}
