//
// Materiaux.cpp for Materiaux in /home/clariv_e//Projets/Systeme-Unix-Avance/Zappy/graphic
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Thu Jul  5 18:59:02 2012 erick clarivet
// Last update Tue Jul 10 04:32:57 2012 erick clarivet
//

#include	"Materiaux.hh"

Materiaux::Materiaux()
{
  // charger les sprites
  sf::Image	tmp;
  if (!tmp.LoadFromFile("sprite/nourriture.png"))
    std::cout << "error" << std::endl;
  sf::Sprite	sTmp(tmp);
  this->imageMat.push_back(tmp);
  this->spriteMat.push_back(sTmp);
  if (!tmp.LoadFromFile("sprite/linemate.png"))
    std::cout << "error" << std::endl;
  sf::Sprite	sTmp2(tmp);
  this->imageMat.push_back(tmp);
  this->spriteMat.push_back(sTmp2);
  if (!tmp.LoadFromFile("sprite/deraumere.png"))
    std::cout << "error" << std::endl;
    sf::Sprite	sTmp3(tmp);
  this->imageMat.push_back(tmp);
  this->spriteMat.push_back(sTmp3);
  if (!tmp.LoadFromFile("sprite/sibur.png"))
    std::cout << "error" << std::endl;
    sf::Sprite	sTmp4(tmp);
  this->imageMat.push_back(tmp);
  this->spriteMat.push_back(sTmp4);
  if (!tmp.LoadFromFile("sprite/mendiane.png"))
    std::cout << "error" << std::endl;
  sf::Sprite	sTmp5(tmp);
  this->imageMat.push_back(tmp);
  this->spriteMat.push_back(sTmp5);
  if (!tmp.LoadFromFile("sprite/phyras.png"))
    std::cout << "error" << std::endl;
  sf::Sprite	sTmp6(tmp);
  this->imageMat.push_back(tmp);
  this->spriteMat.push_back(sTmp6);
  if (!tmp.LoadFromFile("sprite/thystame.png"))
    std::cout << "error" << std::endl;
    sf::Sprite	sTmp7(tmp);
  this->imageMat.push_back(tmp);
  this->spriteMat.push_back(sTmp7);
}

Materiaux::~Materiaux()
{
}

std::vector<sf::Image>&	Materiaux::getImageMat()
{
  return this->imageMat;
}

sf::Image&			Materiaux::getImageMatNourriture()
{
  return this->imageMat[0];
}

sf::Image&			Materiaux::getImageMatLinemate()
{
  return this->imageMat[1];
}

sf::Image&			Materiaux::getImageMatDeraumere()
{
  return this->imageMat[2];
}

sf::Image&			Materiaux::getImageMatSibur()
{
  return this->imageMat[3];
}

sf::Image&			Materiaux::getImageMatMendiane()
{
  return this->imageMat[4];
}

sf::Image&			Materiaux::getImageMatPhiras()
{
  return this->imageMat[5];
}

sf::Image&			Materiaux::getImageMatThystame()
{
  return this->imageMat[6];
}


std::vector<sf::Sprite>&	Materiaux::getSpriteMat()
{
  return this->spriteMat;
}

sf::Sprite&			Materiaux::getSpriteMatNourriture()
{
  return this->spriteMat[0];
}

sf::Sprite&			Materiaux::getSpriteMatLinemate()
{
  return this->spriteMat[1];
}

sf::Sprite&			Materiaux::getSpriteMatDeraumere()
{
  return this->spriteMat[2];
}

sf::Sprite&			Materiaux::getSpriteMatSibur()
{
  return this->spriteMat[3];
}

sf::Sprite&			Materiaux::getSpriteMatMendiane()
{
  return this->spriteMat[4];
}

sf::Sprite&			Materiaux::getSpriteMatPhiras()
{
  return this->spriteMat[5];
}

sf::Sprite&			Materiaux::getSpriteMatThystame()
{
  return this->spriteMat[6];
}

