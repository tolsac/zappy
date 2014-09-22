//
// infos.cpp for  in /home/tolsa_c//zappy-2015-2014s-tolsa_c/client_zappy
// 
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
// 
// Started on  Fri Jun 29 16:02:39 2012 camille tolsa
// Last update Sun Jul  1 10:20:42 2012 camille tolsa
//

#include "./infos.hh"

infos::infos()
{
  this->elev[0][JOUEUR] = 1;
  this->elev[0][LINEMATE] = 1;
  this->elev[0][DERAUMERE] = 0;
  this->elev[0][SIBUR] = 0;
  this->elev[0][MENDIANE] = 0;
  this->elev[0][PHIRAS] = 0;
  this->elev[0][THYSTAME] = 0;

  this->elev[1][JOUEUR] = 2;
  this->elev[1][LINEMATE] = 1;
  this->elev[1][DERAUMERE] = 1;
  this->elev[1][SIBUR] = 1;
  this->elev[1][MENDIANE] = 0;
  this->elev[1][PHIRAS] = 0;
  this->elev[1][THYSTAME] = 0;

  this->elev[2][JOUEUR] = 2;
  this->elev[2][LINEMATE] = 2;
  this->elev[2][DERAUMERE] = 0;
  this->elev[2][SIBUR] = 1;
  this->elev[2][MENDIANE] = 0;
  this->elev[2][PHIRAS] = 2;
  this->elev[2][THYSTAME] = 0;

  this->elev[3][JOUEUR] = 4;
  this->elev[3][LINEMATE] = 1;
  this->elev[3][DERAUMERE] = 1;
  this->elev[3][SIBUR] = 2;
  this->elev[3][MENDIANE] = 0;
  this->elev[3][PHIRAS] = 1;
  this->elev[3][THYSTAME] = 0;

  this->elev[4][JOUEUR] = 4;
  this->elev[4][LINEMATE] = 1;
  this->elev[4][DERAUMERE] = 2;
  this->elev[4][SIBUR] = 1;
  this->elev[4][MENDIANE] = 3;
  this->elev[4][PHIRAS] = 0;
  this->elev[4][THYSTAME] = 0;

  this->elev[5][JOUEUR] = 6;
  this->elev[5][LINEMATE] = 1;
  this->elev[5][DERAUMERE] = 2;
  this->elev[5][SIBUR] = 3;
  this->elev[5][MENDIANE] = 0;
  this->elev[5][PHIRAS] = 1;
  this->elev[5][THYSTAME] = 0;

  this->elev[6][JOUEUR] = 6;
  this->elev[6][LINEMATE] = 2;
  this->elev[6][DERAUMERE] = 2;
  this->elev[6][SIBUR] = 2;
  this->elev[6][MENDIANE] = 2;
  this->elev[6][PHIRAS] = 2;
  this->elev[6][THYSTAME] = 1;

  this->min[0] = 0;
  this->min[1] = 1;
  this->min[2] = 4;
  this->min[3] = 9;
  this->min[4] = 16;
  this->min[5] = 25;
  this->min[6] = 36;
  this->min[7] = 49;
  this->min[8] = 64;
  
  this->middle[0] = 0;
  this->middle[1] = 2;
  this->middle[2] = 6;
  this->middle[3] = 12;
  this->middle[4] = 20;
  this->middle[5] = 30;
  this->middle[6] = 42;
  this->middle[7] = 56;
  this->middle[8] = 72; 

  this->max[0] = 0;
  this->max[1] = 3;
  this->max[2] = 8;
  this->max[3] = 15;
  this->max[4] = 24;
  this->max[5] = 35;
  this->max[6] = 48;
  this->max[7] = 63;
  this->max[8] = 80;

  this->items[0] = "nourriture\n";
  this->items[1] = "linemate\n";
  this->items[2] = "deraumere\n";
  this->items[3] = "sibur\n";
  this->items[4] = "mendiane\n";
  this->items[5] = "phiras\n";
  this->items[6] = "thystame\n";
}

infos::~infos()
{}
