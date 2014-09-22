//
// infos.hh for  in /home/tolsa_c//zappy-2015-2014s-tolsa_c/client_zappy
// 
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
// 
// Started on  Fri Jun 29 15:56:03 2012 camille tolsa
// Last update Sun Jul  1 11:03:08 2012 camille tolsa
//

#ifndef __INFOS__
#define __INFOS__

#include <string>
//#define JOUEUR 0

typedef enum e_item
  {
    //  NOURRITURE
    JOUEUR,
    LINEMATE,  //bleu
    DERAUMERE, //rouge
    SIBUR,     //jaune
    MENDIANE,  //violet
    PHIRAS,    //vert
    THYSTAME   //blanc
  }t_item;

class		infos
{
public:
  infos();
  ~infos();
  int		elev[7][7];
  int		min[9];
  int		middle[9];
  int		max[9];
  std::string	items[7];
};

#endif
