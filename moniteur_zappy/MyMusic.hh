//
// MyMusic.hh for MyMusic in /home/clariv_e//Projets/Systeme-Unix-Avance/Zappy/zappy-2015-2014s-tolsa_c/moniteur_zappy
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Sun Jul 15 13:52:50 2012 erick clarivet
// Last update Sun Jul 15 13:54:36 2012 erick clarivet
//

#ifndef		__MYMUSIC_HH__
#define		__MYMUSIC_HH__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <deque>

class	MyMusic
{
  sf::Music	music1;
  sf::Music	bruitage1;
  sf::Music	bruitage2;
  sf::Music	bruitage3;
  sf::Music	bruitage4;
  sf::Music	bruitage5;
public:
  MyMusic();
  ~MyMusic();

  void				  playMusic(const int& i);
  void				  pauseMusic(const int& i);
  void				  stopMusic(const int& i);

  void				  update();
  sf::Music&			  getMusic(const int& i);
};

#endif
