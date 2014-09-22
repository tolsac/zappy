/*
** Monitor.hh for monitor in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 16:41:27 2012 bertrand boyer
// Last update Sun Jul 15 01:34:26 2012 erick clarivet
*/

#ifndef __MONITOR_HH__
#define __MONITOR_HH__

#include <iostream>
#include <string>
#include <list>
#include <map>

#include <cstdio>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "./Enumerations.hh"
#include "./Map.hh"
#include "./Player.hh"
#include "./Buffer.hh"
#include "./MySprite.hh"

class				Monitor
{
private:
  int				fd;
  int				port;
  int				time;
  int				timeRefreshInv;
  Buffer			buff;
  Map				map;
  MySprite			graphic;
  std::map<int, Player>		players;
  std::list<std::string>	teamName;
  std::string			cmd[24];
  int				(Monitor::*actionsFrom[24])(std::string const &cmd);

public:
  Monitor();
  ~Monitor();

  int				getFd() const;
  int				getPort() const;
  int				getTime() const;
  Map				getMap() const;
  std::map<int, Player>		getPlayers() const;
  std::list<std::string>	getTeamName() const;

  void				setPort(int port);
  void				setTime(int time);

  void				addTeam(std::string const &name);

  int				connexion(std::string const &ip, int port);
  int				startReception() const;
  int				mainLoop();
  int				reception();
  int				action();

  int				msz(std::string const &cmd);
  int				bct(std::string const &cmd);
  int				tna(std::string const &cmd);
  int				pnw(std::string const &cmd);
  int				ppo(std::string const &cmd);
  int				plv(std::string const &cmd);
  int				pin(std::string const &cmd);
  int				pex(std::string const &cmd);
  int				pbc(std::string const &cmd);
  int				pic(std::string const &cmd);
  int				pie(std::string const &cmd);
  int				pfk(std::string const &cmd);
  int				pdr(std::string const &cmd);
  int				pgt(std::string const &cmd);
  int				pdi(std::string const &cmd);
  int				enw(std::string const &cmd);
  int				eht(std::string const &cmd);
  int				ebo(std::string const &cmd);
  int				edi(std::string const &cmd);
  int				sgt(std::string const &cmd);
  int				seg(std::string const &cmd);
  int				smg(std::string const &cmd);
  int				suc(std::string const &cmd);
  int				sbp(std::string const &cmd);

  std::string			m_msz() const;
  std::string			m_bct(int x, int y) const;
  std::string			m_mct() const;
  std::string			m_tna() const;
  std::string			m_ppo(Player p) const;
  std::string			m_plv(Player p) const;
  std::string			m_pin(Player p) const;
  std::string			m_sgt() const;
  std::string			m_sst() const;

  void				createWindow(int, int);
  bool				isFinish(int ***, int, int, std::map<int, Player>&);
  void				display();

  void				checkTime();
};

#endif
