/*
** Case.cpp for monitor in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 16:29:51 2012 bertrand boyer
** Last update Thu Jul  5 18:04:03 2012 bertrand boyer
*/

#include "./Case.hh"

Case::Case()
{
}

Case::Case(int x, int y)
{
  this->x = x;
  this->y = y;
}

Case::~Case()
{
}

int			Case::getX() const
{
  return (this->x);
}

int			Case::getY() const
{
  return (this->y);
}

int			Case::getContentsNb(Ressource r) const
{
  return (this->contents[r]);
}

void			Case::setX(int x)
{
  this->x = x;
}

void			Case::setY(int y)
{
  this->y = y;
}

void			Case::setContents(int n, int l, int d, int s, int m, int p, int t)
{
  this->contents[NOURRITURE] = n;
  this->contents[LINEMATE] = l;
  this->contents[DERAUMERE] = d;
  this->contents[SIBUR] = s;
  this->contents[MENDIANE] = m;
  this->contents[PHIRAS] = p;
  this->contents[THYSTAME] = t;
}
