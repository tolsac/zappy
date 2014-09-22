//
// MySprite.hh for MySprite in /home/clariv_e//Projets/Systeme-Unix-Avance/Zappy/graphic
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Thu Jul  5 16:34:27 2012 erick clarivet
// Last update Sun Jul 15 18:43:27 2012 erick clarivet
//

#ifndef		__MYSPRITE_HH__
#define		__MYSPRITE_HH__

// * Event.MouseButton.Button contient le bouton qui a été appuyé / relâché
// * Event.MouseButton.X contient la position X actuelle de la souris
// * Event.MouseButton.Y contient la position Y actuelle de la souris


#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	<map>
#include	<iterator>
#include	<sstream>
// #include	<SFML/View.hpp>
// #include	<Rect.hpp>

#include	"Human.hh"
#include	"Materiaux.hh"
#include	"Player.hh"
#include	"MyMusic.hh"

#define		TAILLE_HERBE	50
#define		TAILLE_MATERIAUX	16	
#define		WIDTH_MAX	1200
#define		HEIGHT_MAX	720

class		MySprite
{
  sf::RenderWindow app;
  sf::Event	event;
  sf::View	*view;
  sf::Clock	clock;
  sf::String	mat;
  sf::String	item;
  float		timeLeftClick;
  float		timeRightClick;
  int		chooseHumanInv;
  Human		human;
  Materiaux	materiaux;
  sf::Image	imageHerbe;
  sf::Sprite	spriteHerbe;
  sf::Image	imageMenuCase;
  sf::Sprite	spriteMenuCase;
  sf::Image	imageMenuPlayer;
  sf::Sprite	spriteMenuPlayer;
  MyMusic	muse;
  // nourriture
  // tous les materiaux
  // le sol
public:
  MySprite();
  ~MySprite();
  void		drawMap();
  void		drawCase(int *Case, int x, int y);
  void		drawMap(int ***map, int x, int y);
  // penser a faire apparaitre les joueur dans la case aleatoirement
  // agrandire la taille du sol ou reduire la taille des items et persos
  void		createHuman(Player& player); 
  void		moveHuman(Player& player);
  void		create(int, int);
  bool		myEvent(int ***, int, int, std::map<int, Player>&);
  void		display();
  void		drawAllHuman(std::map<int, Player>& players);
  bool		drawHuman(Player& player);
  void		expulseHuman(Player& player);
  void		broadCastHuman(Player& player);
  void		pondHuman(Player& player);
  void		prendHuman(Player& player);
  void		jetteHuman(Player& player);
  void		mortHuman(Player &player);
  void          drawMenuCase();
  void		showMateriaux(int ***map, int x, int y);
  void		drawInMenuCase(int ***map, int width,
			       int height, float mouseX,
			       float mouseY);
  void		drawInMenuHuman(int ***map, int width,
				int height, float mouseX,
				float mouseY,
				std::map<int, Player>& players);
  void		showItem(Player& player);
  void		drawMenuPlayer();
  float		getTime() const;
  void		beginLvlUpHuman(Player& player);
  void		successLvlUpHuman(Player& player);
  void		failLvlUpHuman(Player& player);
};

#endif
