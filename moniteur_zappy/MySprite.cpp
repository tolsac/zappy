/*
** MySprite.cpp for monitor in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Tue Jul 10 17:59:21 2012 bertrand boyer
// Last update Sun Jul 15 19:06:01 2012 erick clarivet
*/

#include	"MySprite.hh"

MySprite::MySprite()
{
  if (!this->imageHerbe.LoadFromFile("sprite/herbe.png"))
    std::cout << "error" << std::endl;
  if (!this->imageMenuCase.LoadFromFile("sprite/menu_case.png"))
    std::cout << "error" << std::endl;
  if (!this->imageMenuPlayer.LoadFromFile("sprite/menu_human.png"))
    std::cout << "error" << std::endl;
  this->spriteMenuCase.SetPosition(0, 0);
  this->spriteMenuCase.SetImage(this->imageMenuCase);
  this->spriteMenuCase.SetPosition(0, 0);
  this->spriteMenuCase.SetImage(this->imageMenuPlayer);
  this->view = new sf::View(sf::Vector2f(400, 300), sf::Vector2f(800, 600));
  this->app.SetView(*this->view);
  this->timeLeftClick = 0;
  this->timeRightClick = 0;
  this->clock.Reset();
  this->chooseHumanInv = 0;
  this->muse.playMusic(0);
}

MySprite::~MySprite()
{
}

void			MySprite::create(int width, int height)
{
  this->app.Create(sf::VideoMode(width, height), "Moniteur Zappy");
}

bool			MySprite::myEvent(int ***map, int width, int height, std::map<int, Player>& players)
{
  float			zoom = 1;
  sf::Event Event;

  const sf::Input& Input = this->app.GetInput();
  while (this->app.GetEvent(Event))
    {
      unsigned int MouseX = Input.GetMouseX();
      unsigned int MouseY = Input.GetMouseY();

      if (Event.Type == sf::Event::Closed)
	this->app.Close();
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
	this->app.Close();
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Add))
	{
	  zoom += 0.2;
	  this->view->Zoom(zoom);
	}
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Subtract))
	{
	  zoom -= 0.2;
	  this->view->Zoom(zoom);
	}
      if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Left))
	{
	  float x = (this->view->GetCenter().x) - 3;
	  float y = (this->view->GetCenter().y);
	  this->view->SetCenter(x, y);
	}
      if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right))
	{
	  float x = (this->view->GetCenter().x) + 3;
	  float y = (this->view->GetCenter().y);
	  this->view->SetCenter(x, y);
	}
      if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Up))
	{
	  float x = (this->view->GetCenter().x);
	  float y = (this->view->GetCenter().y) - 3;
	  this->view->SetCenter(x, y);
	}
      if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Down))
	{
	  float x = (this->view->GetCenter().x);
	  float y = (this->view->GetCenter().y) + 3;
	  this->view->SetCenter(x, y);
	}
      if(Input.IsMouseButtonDown(sf::Mouse::Left))
	{
	  std::cout << "coord,x:" << MouseX << "/y:" << MouseY << std::endl;
	  this->spriteMenuCase.SetImage(this->imageMenuCase);
	  this->spriteMenuCase.SetPosition(this->view->GetCenter().x, this->view->GetCenter().y);
	  this->app.Draw(this->spriteMenuCase);
	  this->drawInMenuCase(map, width, height, MouseX, MouseY);
	  this->timeLeftClick = this->clock.GetElapsedTime();
	}

      if(Input.IsMouseButtonDown(sf::Mouse::Right))
	{
	  std::cout << "coord,x:" << MouseX << "/y:" << MouseY << std::endl;
	  this->spriteMenuCase.SetImage(this->imageMenuPlayer);
	  this->spriteMenuCase.SetPosition(MouseX, MouseY);
	  this->app.Draw(this->spriteMenuPlayer);
	  this->drawInMenuHuman(map, width, height, MouseX, MouseY, players);
	  this->timeRightClick = this->clock.GetElapsedTime();
	}
    }
  this->app.SetView(*this->view);
  return this->app.IsOpened();
}

void		MySprite::drawCase(int *Case, int x, int y)
{
  int		i = 0;
  int		tmpx = 0;
  int		tmpy = 0;

  this->spriteHerbe.SetImage(this->imageHerbe);
  this->spriteHerbe.SetPosition((x * TAILLE_HERBE) + 1, (y * TAILLE_HERBE) + 1);
  this->app.Draw(this->spriteHerbe);
  while (i < 7)
    {
      if (Case[i] > 0)
      	{
      	  if (((i + 1) % 7) < 4 && ((i + 1) % 7) != 0)
      	    {
	      tmpy = (y * TAILLE_HERBE) + (i * TAILLE_MATERIAUX);
      	      tmpx = (x * TAILLE_HERBE);
      	    }
      	  else if (((i + 1) % 7) <= 6 && ((i + 1) % 7) > 3)
      	    {
	      tmpy = (y * TAILLE_HERBE) + ((i - 3) * TAILLE_MATERIAUX);
      	      tmpx = (x * TAILLE_HERBE) + TAILLE_MATERIAUX;
      	    }
      	  else
      	    {
	      tmpy = (y * TAILLE_HERBE);
      	      tmpx = (x * TAILLE_HERBE) + (2 * TAILLE_MATERIAUX);
      	    }
	  this->materiaux.getSpriteMat()[i].SetImage(this->materiaux.getImageMat()[i]);
	  this->materiaux.getSpriteMat()[i].SetPosition(tmpx, tmpy);
	  this->app.Draw(this->materiaux.getSpriteMat()[i]);
      	}
      i++;
    }
}

void		MySprite::drawMap(int ***map, int x, int y)
{
  int		i = 0;
  int		j;

  while (i < x)
    {
      j = 0;
      while (j < y)
	{
	  this->drawCase(map[i][j], i, j);
	  j++;
	}
      i++;
    }
}

void		MySprite::drawMap()
{
  std::vector<sf::Sprite>::iterator	it;

  it = this->materiaux.getSpriteMat().begin();
  for (; it < this->materiaux.getSpriteMat().end(); ++it)
    this->app.Draw((*it));
}

void		MySprite::display()
{
  this->app.Display();
  this->app.Clear();
}

void		MySprite::createHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().getPerso().SetImage(player.getHuman().getPosDown());
  player.getHuman().getPerso().SetPosition(tmpy, tmpx);
  this->app.Draw(player.getHuman().getPerso());
}

void		MySprite::moveHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[player.getDir()]);
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso());
}

bool		MySprite::drawHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;
  bool		ret = true;

  if (player.getDir() != player.getPos() && (player.getHuman().posIsFinish(this->clock.GetElapsedTime()) == false || (player.getPos() == START_INCANT)))
    player.getHuman().getPerso().SetImage(player.getHuman().getPos()[player.getPos()]);
  else
    {
      player.getHuman().getPerso().SetImage(player.getHuman().getPos()[player.getDir()]);
      ret = false;
    }
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso());
  return ret;
}

void		MySprite::drawAllHuman(std::map<int, Player>& players)
{
  std::map<int, Player>::iterator	it;
  int					nb = -1;

  it = players.begin();
  for (; it != players.end(); ++it)
    {
      if (this->drawHuman((*it).second) == false)
	{
	  if ((*it).second.getPos() == MORT)
	    nb = (*it).second.getNb();
	  (*it).second.setPos((*it).second.getDir());
	}
    }
  if (nb != -1)
    players.erase(nb);
} 

void		MySprite::expulseHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(EXPULSE);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[EXPULSE]);      
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso());
}

void		MySprite::broadCastHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(BROADCAST);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[BROADCAST]);      
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso());
}

void		MySprite::pondHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(POND);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[POND]);
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso());
}

void		MySprite::mortHuman(Player &player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(MORT);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[MORT]);
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso());
}

void		MySprite::prendHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(PREND);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[PREND]);
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso());
}

void		MySprite::jetteHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(JETTE);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[JETTE]);
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso());
}

void		MySprite::drawMenuCase()
{
  if (this->timeLeftClick != 0 && this->clock.GetElapsedTime() - this->timeLeftClick < 2.0f)
    {
      this->app.Draw(this->spriteMenuCase);      
      this->app.Draw(this->mat);
    }
}

void		MySprite::drawMenuPlayer()
{
  if (this->timeRightClick != 0 && this->clock.GetElapsedTime() - this->timeRightClick < 2.0f)
    {
      this->app.Draw(this->spriteMenuCase);
      this->app.Draw(this->item);
    }
}

void		MySprite::showMateriaux(int ***map, int x, int y)
{
  std::string	   contenus;
  std::stringstream	   ss1;
  std::stringstream	   ss2;
  std::stringstream	   ss3;
  std::stringstream	   ss4;
  std::stringstream	   ss5;
  std::stringstream	   ss6;
  std::stringstream	   ss7;

  ss1 << map[x][y][2];
  ss2 << map[x][y][5];
  ss3 << map[x][y][1];
  ss4 << map[x][y][6];
  ss5 << map[x][y][4];
  ss6 << map[x][y][3];
  ss7 << map[x][y][0];

  contenus = "Deraumere x" + ss1.str();

  contenus += "                   Phyras x" + ss2.str() + "\n";
  contenus += "Linemate x" + ss3.str();
  contenus += "                    Thystame x" + ss4.str() + "\n\n";
  contenus += "Mendiane x" + ss5.str();
  contenus += "                     Sibur x" + ss6.str() + "\n";

  contenus += "            Nourriture x" + ss7.str();
  this->mat.SetText(contenus.c_str());
  this->mat.SetColor(sf::Color(0, 0, 0));
  this->mat.SetPosition(this->spriteMenuCase.GetPosition().x + 30, this->spriteMenuCase.GetPosition().y + 32);
  this->mat.SetSize(10.f);
  this->app.Draw(this->mat);
}

void		MySprite::showItem(Player& player)
{
  std::string	   contenus;
  std::string		teamName = "";
  std::stringstream	   ss0;
  std::stringstream	   ss8;
  std::stringstream	   ss1;
  std::stringstream	   ss2;
  std::stringstream	   ss3;
  std::stringstream	   ss4;
  std::stringstream	   ss5;
  std::stringstream	   ss6;
  std::stringstream	   ss7;

  
  ss0 << player.getNb();
  ss8 << player.getLvl();
  ss1 << player.getInvNb(NOURRITURE);
  ss2 << player.getInvNb(LINEMATE);
  ss3 << player.getInvNb(DERAUMERE);
  ss4 << player.getInvNb(SIBUR);
  ss5 << player.getInvNb(MENDIANE);
  ss6 << player.getInvNb(PHIRAS);
  ss7 << player.getInvNb(THYSTAME);

  std::cout << ss1.str() << std::endl;
  contenus = "            " + ss0.str();
  contenus += "                           " + player.getTeam();
  contenus += "            " + ss8.str() + "\n\n";
  contenus += "x" + ss3.str();
  contenus += "          x" + ss2.str();
  contenus += "            x" + ss5.str();
  contenus += "              x" + ss6.str() + "\n";
  contenus += "       x" + ss4.str();
  contenus += "            x" + ss7.str();
  contenus += "             x" + ss1.str() + "\n";
  this->item.SetText(contenus.c_str());
  this->item.SetColor(sf::Color(0, 0, 0));
  this->item.SetPosition(this->spriteMenuCase.GetPosition().x + 30, this->spriteMenuCase.GetPosition().y + 28);
  this->item.SetSize(13.f);
  this->app.Draw(this->item);
}

void		MySprite::drawInMenuCase(int ***map, int width,
					 int height, float mouseX,
					 float mouseY)
{
  int		x = 0;
  int		y = 0;
  float		realMouseX = this->app.ConvertCoords(mouseX, mouseY).x;
  float		realMouseY = this->app.ConvertCoords(mouseX, mouseY).y;

  if (width == -1 && height == -1)
    return;
  while (x < (width - 1))
    {
      y = 0;
      while (y < (height - 1))
	{
	  if ((y * TAILLE_HERBE) < realMouseY && ((y + 1) * TAILLE_HERBE) > realMouseY &&
	      (x * TAILLE_HERBE) < realMouseX && ((x + 1) * TAILLE_HERBE) > realMouseX)
	    {
	      this->showMateriaux(map, x, y);
	      return;
	    }
	  y++;
	}
      x++;
    }
}

void		MySprite::drawInMenuHuman(int ***map, int width,
					  int height, float mouseX,
					  float mouseY,
					  std::map<int, Player>& players)
{
  float		realMouseX = this->app.ConvertCoords(mouseX, mouseY).x;
  float		realMouseY = this->app.ConvertCoords(mouseX, mouseY).y;
  std::map<int, Player>::iterator it;

  (void)map;
  it = players.begin();
  if (width == -1 && height == -1)
    return;
  for (; it != players.end(); ++it)
    {
      if (((*it).second.getY() * TAILLE_HERBE) < realMouseY && (((*it).second.getY() + 1) * TAILLE_HERBE) > realMouseY &&
	  ((*it).second.getX() * TAILLE_HERBE) < realMouseX && (((*it).second.getX() + 1) * TAILLE_HERBE) > realMouseX)
	{
	  this->showItem((*it).second);
	  return;
	}
    }
}

float			MySprite::getTime() const
{
  return this->clock.GetElapsedTime();
}

void			MySprite::beginLvlUpHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(START_INCANT);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[START_INCANT]);
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso()); 
}

void			MySprite::successLvlUpHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.setLvl(player.getLvl() + 1);
  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(SUCCESS_INCANT);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[FAIL_INCANT]);
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso()); 
}

void			MySprite::failLvlUpHuman(Player& player)
{
  int		tmpy = player.getY() * TAILLE_HERBE;
  int		tmpx = player.getX() * TAILLE_HERBE;

  player.getHuman().setTimePos(this->clock.GetElapsedTime());
  player.setPos(FAIL_INCANT);
  player.getHuman().getPerso().SetImage(player.getHuman().getPos()[FAIL_INCANT]);
  player.getHuman().getPerso().SetPosition(tmpx, tmpy);
  this->app.Draw(player.getHuman().getPerso()); 
}
