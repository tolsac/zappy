/*
** Map.hh for monitor in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 17:08:16 2012 bertrand boyer
** Last update Mon Jul  9 14:15:58 2012 bertrand boyer
*/

#ifndef __MAP_HH__
#define __MAP_HH__

#include <deque>

#include "./Enumerations.hh"

class				Map
{
private:
  int				width;
  int				height;
  int				***map;

public:
  Map();
  ~Map();

  int				getWidth() const;
  int				getHeight() const;
  int				***getMap() const;

  // void				setWidth();
  // void				setHeight();
  void				setAt(int x, int y, int n, int l, int d, int s, int m, int p, int t);

  void				createMap(int width, int height);

  void				ressourceUp(int x, int y, Ressource r);
  void				ressourceDown(int x, int y, Ressource r);
};

#endif
