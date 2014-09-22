/*
** Case.hh for monitor in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 16:22:36 2012 bertrand boyer
** Last update Thu Jul  5 17:11:14 2012 bertrand boyer
*/

#ifndef __CASE_HH__
#define __CASE_HH__

#include "./Enumerations.hh"

class				Case
{
private:
  int				x;
  int				y;
  int				contents[7];

public:
  Case();
  Case(int x, int y);
  ~Case();

  int				getX() const;
  int				getY() const;
  int				getContentsNb(Ressource r) const;

  void				setX(int x);
  void				setY(int y);
  void				setContents(int n, int l, int d, int s, int m, int p, int t);
};

#endif
