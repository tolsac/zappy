//
// Materiaux.hh for Materiaux in /home/clariv_e//Projets/Systeme-Unix-Avance/Zappy/graphic
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Thu Jul  5 18:43:06 2012 erick clarivet
// Last update Tue Jul 10 04:20:22 2012 erick clarivet
//

#ifndef		__MATERIAUX_HH__
#define		__MATERIAUX_HH__

#include	<vector>
#include	<iostream>
#include	<SFML/Graphics.hpp>

class		Materiaux
{
  std::vector<sf::Image>	imageMat;
  std::vector<sf::Sprite>	spriteMat;
  int				tailleX;
  int				tailleY;
public:
  Materiaux();
  ~Materiaux();
  std::vector<sf::Image>&	getImageMat();
  sf::Image&			getImageMatNourriture();
  sf::Image&			getImageMatLinemate();
  sf::Image&			getImageMatDeraumere();
  sf::Image&			getImageMatSibur();
  sf::Image&			getImageMatMendiane();
  sf::Image&			getImageMatPhiras();
  sf::Image&			getImageMatThystame();

  std::vector<sf::Sprite>&	getSpriteMat();
  sf::Sprite&			getSpriteMatNourriture();
  sf::Sprite&			getSpriteMatLinemate();
  sf::Sprite&			getSpriteMatDeraumere();
  sf::Sprite&			getSpriteMatSibur();
  sf::Sprite&			getSpriteMatMendiane();
  sf::Sprite&			getSpriteMatPhiras();
  sf::Sprite&			getSpriteMatThystame();
};

#endif
