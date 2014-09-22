//
// Human.hh for Human in /home/clariv_e//Projets/Systeme-Unix-Avance/Zappy/graphic
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Thu Jul  5 16:18:05 2012 erick clarivet
// Last update Fri Jul 13 16:10:59 2012 erick clarivet
//

#ifndef		__HUMAN_HH__
#define		__HUMAN_HH__

#include	<map>
#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	"Enumerations.hh"

class		Human
{
  std::map<Position, sf::Image>	pos;
  sf::Sprite				perso;
  float		 timePos;
public:
  Human();
  ~Human();
  std::map<Position, sf::Image>&	getPos();
  sf::Image&              getPosUp();
  sf::Image&              getPosDown();
  sf::Image&              getPosLeft();
  sf::Image&              getPosRight();

  float			getTimePos() const;
  void			setTimePos(float newTime);
  bool			posIsFinish(float newTime);
  sf::Sprite&			getPerso();
};

#endif
