/*
** Player.cpp for moniteur in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 14:49:25 2012 bertrand boyer
// Last update Fri Jul 13 17:47:42 2012 erick clarivet
*/

#include "./Player.hh"

Player::Player()
{
  int			i = -1;

  this->nb = 0;
  this->lvl = 0;
  this->x = 0;
  this->y = 0;
  while (++i < 7)
    this->inv[i] = 0;
  this->dir = DOWN;
}

Player::Player(int nb, int lvl, int x, int y)
{
  this->nb = nb;
  this->lvl = lvl;
  this->x = x;
  this->y = y;
}

Player::~Player()
{
}

int			Player::getNb() const
{
  return (this->nb);
}

int			Player::getLvl() const
{
  return (this->lvl);
}

int			Player::getX() const
{
  return (this->x);
}

int			Player::getY() const
{
  return (this->y);
}

int			Player::getInvNb(Ressource r) const
{
  return (this->inv[r]);
}

Position		Player::getDir() const
{
  return (this->dir);
}

std::string		Player::getTeam() const
{
  return (this->team);
}

void			Player::setNb(int nb)
{
  this->nb = nb;
}

void			Player::setLvl(int l)
{
  this->lvl = l;
}

void			Player::setX(int x)
{
  this->x = x;
}

void			Player::setY(int y)
{
  this->y = y;
}

void			Player::setInv(int n, int l, int d, int s, int m, int p, int t)
{
  this->inv[NOURRITURE] = n;
  this->inv[LINEMATE] = l;
  this->inv[DERAUMERE] = d;
  this->inv[SIBUR] = s;
  this->inv[MENDIANE] = m;
  this->inv[PHIRAS] = p;
  this->inv[THYSTAME] = t;
}

void			Player::setDir(Position d)
{
  this->dir = d;
}

void			Player::setTeam(std::string const &t)
{
  this->team = t;
}

void			Player::ressourceUp(Ressource r)
{
  this->inv[r]++;
}

void			Player::ressourceDown(Ressource r)
{
  this->inv[r]--;
}

Position		Player::getPos() const
{
  return this->pos;
}

void	       		Player::setPos(Position d)
{
  this->pos = d;
}

Human&		        Player::getHuman()
{
  return this->human;
}
