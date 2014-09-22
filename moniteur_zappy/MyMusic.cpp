//
// MyMusic.cpp<2> for MyMusic in /home/clariv_e//Projets/Systeme-Unix-Avance/Zappy/zappy-2015-2014s-tolsa_c/moniteur_zappy
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Sun Jul 15 14:08:33 2012 erick clarivet
// Last update Sun Jul 15 14:11:59 2012 erick clarivet
//


#include		"MyMusic.hh"

MyMusic::MyMusic()
{
  this->music1.OpenFromFile("sounds/Alone.ogg");
  // this->music2.OpenFromFile("sons/Bomberman.ogg");
  // this->music3.OpenFromFile("sons/explosion.ogg");
  // this->music4.OpenFromFile("sons/fireUp.ogg");
  // this->music5.OpenFromFile("sons/bombUp.ogg");
  // this->music6.OpenFromFile("sons/ready.ogg");
}

MyMusic::~MyMusic()
{
}

void		MyMusic::playMusic(const int& i)
{
  if (i == 0)
    this->music1.Play();
  // else if (i == 1)
  //   this->music2.Play();
  // else if (i == 2)
  //   this->music3.Play();
  // else if (i == 3)
  //   this->music4.Play();
  // else if (i == 4)
  //   this->music5.Play();
  // else
  //   this->music6.Play();
}

void		MyMusic::update()
{
  // if (music2.GetStatus() != sf::Music::Playing)
  //   this->music2.Play();
}

sf::Music&	MyMusic::getMusic(const int& i)
{
  if (i == 0)
    return this->music1;
  // if (i == 1)
  //   return this->music2;
  // if (i == 2)
  //   return this->music3;
  // if (i == 3)
  //   return this->music4;
  // if (i == 4)
  //   return this->music5;
  // return this->music6;
}

void		MyMusic::stopMusic(const int& i)
{
  if (i == 0)
    this->music1.Stop();
  // else if (i == 1)
  //   this->music2.Stop();
  // else if (i == 2)
  //   this->music3.Stop();
  // else if (i == 3)
  //   this->music4.Stop();
  // else if (i == 4)
  //   this->music5.Stop();
  // else
  //   this->music6.Stop();
}

void		MyMusic::pauseMusic(const int& i)
{
  if (i == 0)
    this->music1.Pause();
  // else if (i == 1)
  //   this->music2.Pause();
  // else if (i == 2)
  //   this->music3.Pause();
  // else if (i == 3)
  //   this->music4.Pause();
  // else if (i == 4)
  //   this->music5.Pause();
  // else
  //   this->music6.Pause();
}
