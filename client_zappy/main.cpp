//
// main.cpp for  in /home/tolsa_c//zappy-2015-2014s-tolsa_c/client_zappy
// 
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
// 
// Started on  Wed Jul 11 08:05:43 2012 camille tolsa
// Last update Sun Jul 15 11:48:41 2012 camille tolsa
//

#include <pthread.h>
#include "./client.hh"
#include <unistd.h>
#define z(s) (std::cout << s)

int main(int ac, char **av)
{
  IA		*ia;
  int i = -1;
  srand(time(NULL));

  while (++i<1000){
    fork();
  ia = new IA(ac, av);
  ia->mainLoop();
  }
  return (0);
}
