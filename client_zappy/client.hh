//
// client.hh for  in /home/tolsa_c//zappy-2015-2014s-tolsa_c/client_zappy
// 
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
// 
// Started on  Thu Jul 12 11:26:32 2012 camille tolsa
// Last update Sat Jul 14 13:10:01 2012 mathieu barnetche
//

#ifndef __IA__
#define __IA__

#include <deque>
#include <list>
#include <string>
#include <string.h>
#include "connexion.hh"
#include "infos.hh"
#include "Buffer.hh"

typedef enum e_action
  {
    AVANCE,
    DROITE,
    GAUCHE,
    VOIR,
    INVENTAIRE,
    PRENDRE,
    POSER,
    EXPULSER,
    BROADCAST,
    INCANTER,
    FORKER,
    PILLER
  }t_action;

class	    IA
{
public:
  IA(int ac, char **av);
  ~IA();
  
  int				mainLoop();
  
  Connexion			*co;
  infos				data;
  int				(IA::*action[12])(std::string const&);
  int				fd;
private:
  bool				valid;
  int				mapx;
  int				mapy;
  int				ac;
  char				**av;
  int				inv[7];
  int				dir;
  int				nb;
  int				lvl;
  int				number;
  std::string			team;
  std::string			vision;
  std::deque<std::deque<int> >	see;
  Buffer			buf;
     
  void			usage();
  void			collectAll();
  bool			check_args();
  std::string		getCmd();
  void			err(std::string const&);
  int			auth();
  int			isbc(std::string const&);
  bool			play(); 
  bool			enoughFood(); 
  bool			canIUp(); 
  bool			lookingForItems(t_item); 
  std::string		gatherMates(std::string);
  bool			findMyPath(int); 
  void			getVision(); 
  void			clearVision(); 
  int			thereIsHere(t_item); 
  int			avance(std::string const&);
  int			droite(std::string const&);
  int			gauche(std::string const&);
  int			voir(std::string const&);
  int			inventaire(std::string const&);
  int			prendre(std::string const&);
  int			poser(std::string const&);
  int			expulser(std::string const&);
  int			broadcast(std::string const&);
  int			incanter(std::string const&);
  int			forker(std::string const&);
  int			piller(std::string const&);
  void			randomMove();
};

#endif
