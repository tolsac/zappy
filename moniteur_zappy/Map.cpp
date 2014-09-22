/*
** Map.cpp for monitor in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 18:05:15 2012 bertrand boyer
// Last update Wed Jul 11 13:46:39 2012 bertrand boyer
*/

#include "./Map.hh"

Map::Map()
{
  this->width = -1;
  this->height = -1;
}

Map::~Map()
{
  int		i = -1;
  int		j;

  while (++i < this->width)
    {
      j = -1;
      while (++j < this->height)
	delete (this->map[i][j]);
      delete (this->map[i]);
    }
}

int			Map::getWidth() const
{
  return (this->width);
}

int			Map::getHeight() const
{
  return (this->height);
}

int			***Map::getMap() const
{
  return (this->map);
}

void			Map::setAt(int x, int y, int n, int l, int d, int s, int m, int p, int t)
{
  this->map[x][y][NOURRITURE] = n;
  this->map[x][y][LINEMATE] = l;
  this->map[x][y][DERAUMERE] = d;
  this->map[x][y][SIBUR] = s;
  this->map[x][y][MENDIANE] = m;
  this->map[x][y][PHIRAS] = p;
  this->map[x][y][THYSTAME] = t;
}

void			Map::createMap(int width, int height)
{
  int			i;
  int			j;

  i = -1;
  this->width = width;
  this->height = height;
  this->map = new int**[width];
  while (++i < width)
    {
      j = -1;
      this->map[i] = new int*[height];
      while (++j < height)
	this->map[i][j] = new int[7];
    }
}

void			Map::ressourceUp(int x, int y, Ressource r)
{
  this->map[x][y][r]++;
}

void			Map::ressourceDown(int x, int y, Ressource r)
{
  this->map[x][y][r]--;
}
