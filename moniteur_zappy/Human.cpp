//
// Human.cpp for Human in /home/clariv_e//Projets/Systeme-Unix-Avance/Zappy/graphic
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Thu Jul  5 16:23:47 2012 erick clarivet
// Last update Sun Jul 15 18:49:14 2012 erick clarivet
//

#include	"Human.hh"

Human::Human()
{
  sf::Image _pos1;
  if (!_pos1.LoadFromFile("sprite/up.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[UP] = _pos1;
  sf::Image _pos2;
  if (!_pos2.LoadFromFile("sprite/right.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[RIGHT] = _pos2;
  sf::Image _pos3;
  if (!_pos3.LoadFromFile("sprite/down.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[DOWN] = _pos3;
  this->perso.SetImage(_pos3);
  sf::Image _pos22;
  if (!_pos22.LoadFromFile("sprite/down.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[NONE] = _pos22;
  sf::Image _pos4;
  if (!_pos4.LoadFromFile("sprite/left.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[LEFT] = _pos4;
  sf::Image _pos5;
  if (!_pos5.LoadFromFile("sprite/expulse.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[EXPULSE] = _pos5;
  sf::Image _pos6;
  if (!_pos6.LoadFromFile("sprite/broadcast.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[BROADCAST] = _pos6;
  sf::Image _pos7;
  if (!_pos7.LoadFromFile("sprite/pond.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[POND] = _pos7;
  sf::Image _pos8;
  if (!_pos8.LoadFromFile("sprite/oeuf.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[OEUF] = _pos8;
  sf::Image _pos9;
  if (!_pos9.LoadFromFile("sprite/oeuf_eclot.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[OEUF_ECLOT] = _pos9;
  sf::Image _pos10;
  if (!_pos10.LoadFromFile("sprite/prend.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[PREND] = _pos10;
  sf::Image _pos11;
  if (!_pos11.LoadFromFile("sprite/jette.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[JETTE] = _pos11;
  sf::Image _pos12;
  if (!_pos12.LoadFromFile("sprite/mort.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[MORT] = _pos12;
  sf::Image _pos13;
  if (!_pos13.LoadFromFile("sprite/incantation.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[START_INCANT] = _pos13;
  sf::Image _pos14;
  if (!_pos14.LoadFromFile("sprite/success_incantation.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[SUCCESS_INCANT] = _pos14;
  sf::Image _pos15;
  if (!_pos15.LoadFromFile("sprite/fail_incantation.png"))
    std::cout << "Cannot open your file" << std::endl;
  this->pos[FAIL_INCANT] = _pos15;
  this->timePos = 0;
}

Human::~Human()
{
}

std::map<Position, sf::Image>&		Human::getPos()
{
  return this->pos;
}

float			Human::getTimePos() const
{
  return this->timePos;
}

void			Human::setTimePos(float newTime)
{
  this->timePos = newTime;
}

bool			Human::posIsFinish(float newTime)
{
  if ((newTime - this->timePos) < 0.5f)
    return false;
  this->setTimePos(newTime);
  return true;
}

sf::Image&		Human::getPosUp()
{
  return this->pos[UP];
}

sf::Image&		Human::getPosDown()
{
  return this->pos[DOWN];
}

sf::Image&		Human::getPosLeft()
{
  return this->pos[LEFT];
}

sf::Image&		Human::getPosRight()
{
  return this->pos[RIGHT];
}

sf::Sprite&			Human::getPerso()
{
  return this->perso;
}
