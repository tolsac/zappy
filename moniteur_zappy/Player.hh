/*
** Player.hh for moniteur in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 14:24:31 2012 bertrand boyer
// Last update Fri Jul 13 19:56:18 2012 erick clarivet
*/

#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include <string>

#include "./Enumerations.hh"
#include "./Human.hh"

class				Player
{
private:
  int				nb;
  int				lvl;
  int				x;
  int				y;
  int				inv[7];
  Position			dir;
  Position			pos;
  std::string			team;
  Human				human;
public:
  Player();
  Player(int nb, int lvl, int x, int y);
  ~Player();

  Human&			getHuman();
  int				getNb() const;
  int				getLvl() const;
  int				getX() const;
  int				getY() const;
  int				getInvNb(Ressource r) const;
  Position			getDir() const;
  Position			getPos() const;
  std::string			getTeam() const;

  void				setNb(int nb);
  void				setLvl(int lvl);
  void				setX(int x);
  void				setY(int y);
  void				setInv(int n, int l, int d, int s, int m, int p, int t);
  void				setDir(Position d);
  void				setPos(Position d);
  void				setTeam(std::string const &t);

  void				ressourceUp(Ressource r);
  void				ressourceDown(Ressource r);
};

#endif
