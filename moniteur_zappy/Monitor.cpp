/*
** Monitor.cpp for monitor in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 17:20:10 2012 bertrand boyer
// Last update Sun Jul 15 18:51:59 2012 erick clarivet
*/

#include "./Monitor.hh"
#include <unistd.h>
Monitor::Monitor()
{
  this->fd = -1;
  this->port = -1;
  this->time = -1;
  this->timeRefreshInv = 0;
  this->cmd[MSZ] = "msz";
  this->cmd[BCT] = "bct";
  this->cmd[TNA] = "tna";
  this->cmd[PNW] = "pnw";
  this->cmd[PPO] = "ppo";
  this->cmd[PLV] = "plv";
  this->cmd[PIN] = "pin";
  this->cmd[PEX] = "pex";
  this->cmd[PBC] = "pbc";
  this->cmd[PIC] = "pic";
  this->cmd[PIE] = "pie";
  this->cmd[PFK] = "pfk";
  this->cmd[PDR] = "pdr";
  this->cmd[PGT] = "pgt";
  this->cmd[PDI] = "pdi";
  this->cmd[ENW] = "enw";
  this->cmd[EHT] = "eht";
  this->cmd[EBO] = "ebo";
  this->cmd[EDI] = "edi";
  this->cmd[SGT] = "sgt";
  this->cmd[SEG] = "seg";
  this->cmd[SMG] = "smg";
  this->cmd[SUC] = "suc";
  this->cmd[SBP] = "sbp";
  this->actionsFrom[MSZ] = &Monitor::msz;
  this->actionsFrom[BCT] = &Monitor::bct;
  this->actionsFrom[TNA] = &Monitor::tna;
  this->actionsFrom[PNW] = &Monitor::pnw;
  this->actionsFrom[PPO] = &Monitor::ppo;
  this->actionsFrom[PLV] = &Monitor::plv;
  this->actionsFrom[PIN] = &Monitor::pin;
  this->actionsFrom[PEX] = &Monitor::pex;
  this->actionsFrom[PBC] = &Monitor::pbc;
  this->actionsFrom[PIC] = &Monitor::pic;
  this->actionsFrom[PIE] = &Monitor::pie;
  this->actionsFrom[PFK] = &Monitor::pfk;
  this->actionsFrom[PDR] = &Monitor::pdr;
  this->actionsFrom[PGT] = &Monitor::pgt;
  this->actionsFrom[PDI] = &Monitor::pdi;
  this->actionsFrom[ENW] = &Monitor::enw;
  this->actionsFrom[EHT] = &Monitor::eht;
  this->actionsFrom[EBO] = &Monitor::ebo;
  this->actionsFrom[EDI] = &Monitor::edi;
  this->actionsFrom[SGT] = &Monitor::sgt;
  this->actionsFrom[SEG] = &Monitor::seg;
  this->actionsFrom[SMG] = &Monitor::smg;
  this->actionsFrom[SUC] = &Monitor::suc;
  this->actionsFrom[SBP] = &Monitor::sbp;
}

Monitor::~Monitor()
{
}

int			Monitor::getFd() const
{
  return (this->fd);
}

int			Monitor::getPort() const
{
  return (this->port);
}

int			Monitor::getTime() const
{
  return (this->time);
}

Map			Monitor::getMap() const
{
  return (this->map);
}

std::map<int, Player>	Monitor::getPlayers() const
{
  return (this->players);
}

std::list<std::string>	Monitor::getTeamName() const
{
  return (this->teamName);
}

void			Monitor::setPort(int port)
{
  this->port = port;
}

void			Monitor::setTime(int time)
{
  this->time = time;
}

void			Monitor::addTeam(std::string const &name)
{
  this->teamName.push_back(name);
}

int			Monitor::connexion(std::string const &ip, int port)
{
  struct sockaddr_in	sin;
  struct protoent	*s_proto;

  this->port = port;
  if ((s_proto = getprotobyname("TCP")) == NULL)
    {
      perror("getprotobyname");
      return (-1);
    }
  if ((this->fd = socket(AF_INET, SOCK_STREAM, s_proto->p_proto)) == -1)
    {
      perror("socket");
      return (-1);
    }
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr(ip.c_str());
  sin.sin_port = htons(port);
  if ((connect(this->fd, (const struct sockaddr *) &sin, sizeof(sin))) == -1)
    {
      perror("connect");
      return (-1);
    }
  std::cout << "Connexion établie sur " << ip << ":" << port << "." << std::endl;
  return (0);
}

int			Monitor::startReception() const
{
  char			b[11];

  if (memset(b, 0, 11) == NULL)
    perror("memset");
  if (recv(this->fd, b, 10, 0) == -1)
    {
      perror("recv");
      return (-1);
    }
  std::cout << b;
  if (send(this->fd, "GRAPHIC\n", 8, 0) == -1)
    {
      perror("send");
      return (-1);
    }
  return (0);
}

int			Monitor::mainLoop()
{
  int			retSelect = 0;
  fd_set		fdset;
  struct timeval	tv;

  this->createWindow(800, 600);
  tv.tv_sec = 0;
  tv.tv_usec = 500000;
  while (!this->isFinish(this->map.getMap(), this->map.getWidth(), this->map.getHeight(), this->players))
    {
      FD_ZERO(&fdset);
      FD_SET(this->fd, &fdset);
      if ((retSelect = select(this->fd + 1, &fdset, NULL, NULL, &tv)) > 0)
	{
	  if (FD_ISSET(this->fd, &fdset))
	    if (this->reception() != 0)
	      return (1);
	}
      else if (retSelect == 0)
	{
	  this->graphic.drawMap(this->map.getMap(), this->map.getWidth(), this->map.getHeight());
	  this->checkTime();
	  this->graphic.drawAllHuman(this->players);
	  this->graphic.drawMenuCase();
	  this->graphic.drawMenuPlayer();
	}
      else
	{
	  perror("select");
	  return (-1);
	}
      this->display();
    }
  return (0);
}

int			Monitor::reception()
{
  char			b[2048] = {'\0'};
  int			retRecv = 0;
  int			ret = 0;

  if ((retRecv = recv(this->fd, b, 2047, 0)) > 0)
    {
      this->buff.write_buffer(b);
      ret = this->action();
    }
  else if (retRecv == 0)
    {
      std::cout << "Serveur déconnecté." << std::endl;
      return (1);
    }
  else if (retRecv == -1)
    {
      perror("recv");
      return (-1);
    }
  return (0);
}

int			Monitor::action()
{
  std::string		s;
  int			i;
  int			ret;

  while ((s = this->buff.get()) != "" && s[s.size() - 1] == '\n')
    {
      s.clear();
      s = this->buff.read_buffer();
      if (3 < s.size())
	{
	  i = 0;
	  while (i < 24 && s.compare(0, 3, this->cmd[i]) != 0 && ++i);
	  if (i < 24)
	    {
	      std::cout << "Action " << i << ": [" << s.substr(0, s.size() - 1) << "]";
	      if ((ret = (this->*actionsFrom[i])(s)) == 0)
		std::cout << " Success !" << std::endl;
	      else if (ret == -1)
		std::cout << " Fail !" << std::endl;
	      else
		{
		  std::cout << " Exiting." << std::endl;
		  return (-1);
		}
	    }
	  else
	    std::cout << "Error: [" << s.substr(0, s.size() - 1) << "] is a bad command !" << std::endl;
	}
      else
	std::cout << "Error: [" << s.substr(0, ((s.size() > 0) ? s.size() : 1) - 1) << "] is a bad command !" << std::endl;
    }
  return (0);
}

int				Monitor::msz(std::string const &cmd)
{
  int				width;
  int				height;

  sscanf(cmd.c_str(), "msz %d %d\n", &width, &height);
  if (width < 3 || height < 3)
    {
      std::cout << " Error: bad size !";
      return (-2);
    }
  this->map.createMap(width, height);
  return (0);
}

int				Monitor::bct(std::string const &cmd)
{
  int				x;
  int				y;
  int				r[7];
  int				i = -1;
  int				ret = 0;

  sscanf(cmd.c_str(), "bct %d %d %d %d %d %d %d %d %d\n",
	 &x, &y, &r[NOURRITURE], &r[LINEMATE], &r[DERAUMERE], &r[SIBUR], &r[MENDIANE], &r[PHIRAS], &r[THYSTAME]);
  if (x < 0 || this->map.getWidth() < x || y < 0 || this->map.getHeight() < y)
    {
      std::cout << " Error: bad position !";
      return (-2);
    }
  while (++i < 7)
    if (r[i] < 0 && (ret = -1))
      r[i] = 0;
  this->map.setAt(x, y, r[NOURRITURE], r[LINEMATE], r[DERAUMERE], r[SIBUR], r[MENDIANE], r[PHIRAS], r[THYSTAME]);
  this->graphic.drawCase(r, x, y);
  return (ret);
}

int				Monitor::tna(std::string const &cmd)
{
  std::string			s;

  s.assign(cmd, 4, cmd.size() - 5);
  this->teamName.push_back(s);
  return (0);
}

int				Monitor::pnw(std::string const &cmd)
{
  Player			p;
  int				nb;
  int				x;
  int				y;
  int				O;
  int				L;
  std::string			N;
  char				c[1024];

  sscanf(cmd.c_str(), "pnw %d %d %d %d %d %s\n", &nb, &x, &y, &O, &L, c);
  if (x < 0 || this->map.getWidth() < x || y < 0 || this->map.getHeight() < y)
    {
      std::cout << " Error: bad position !";
      return (-2);
    }
  p.setNb(nb);
  p.setX(x);
  p.setY(y);
  p.setDir((Position) O);
  p.setPos((Position) O);
  p.setLvl(L);
  N.assign(c);
  p.setTeam(N);
  this->players[nb] = p;
  this->graphic.createHuman(this->players[nb]);
  return (0);
}

int				Monitor::ppo(std::string const &cmd)
{
  int				nb;
  int				x;
  int				y;
  int				O;

  sscanf(cmd.c_str(), "ppo %d %d %d %d\n", &nb, &x, &y, &O);
  if (x < 0 || this->map.getWidth() < x || y < 0 || this->map.getHeight() < y)
    {
      std::cout << " Error: bad position !" << std::endl;
      return (-2);
    }
  this->graphic.drawCase(this->map.getMap()[this->players[nb].getX()][this->players[nb].getY()], this->players[nb].getX(), this->players[nb].getY());
  this->players[nb].setX(x);
  this->players[nb].setY(y);
  this->players[nb].setDir((Position) O);
  this->players[nb].setPos((Position) O);
  this->graphic.drawCase(this->map.getMap()[x][y], x, y);
  this->graphic.moveHuman(this->players[nb]);
  return (0);
}

int				Monitor::plv(std::string const &cmd)
{
  int				nb;
  int				L;

  sscanf(cmd.c_str(), "plv %d %d\n", &nb, &L);
  this->players[nb].setLvl(L);
  return (0);
}

int				Monitor::pin(std::string const &cmd)
{
  int				nb;
  int				x;
  int				y;
  int				r[7];
  int				ret;
  int				i = -1;

  sscanf(cmd.c_str(), "pin %d %d %d %d %d %d %d %d %d %d\n",
	 &nb, &x, &y, &r[NOURRITURE], &r[LINEMATE], &r[DERAUMERE], &r[SIBUR], &r[MENDIANE], &r[PHIRAS], &r[THYSTAME]);
  if (x < 0 || this->map.getWidth() < x || y < 0 || this->map.getHeight() < y)
    {
      std::cout << " Error: bad position !";
      return (-2);
    }
  this->players[nb].setX(x);
  this->players[nb].setY(y);
  while (++i < 7)
    if (r[i] < 0 && (ret = -1))
      r[i] = 0;
  this->players[nb].setInv(r[NOURRITURE], r[LINEMATE], r[DERAUMERE], r[SIBUR], r[MENDIANE], r[PHIRAS], r[THYSTAME]);
  return (0);
}

int				Monitor::pex(std::string const &cmd)
{
  int				nb;
  std::map<int, Player>::iterator	it;

  sscanf(cmd.c_str(), "pex %d\n", &nb);
  it = this->players.begin();
  for (; it != this->players.end(); ++it)
    {
      if (nb == (*it).second.getNb())
	{
	  this->graphic.expulseHuman((*it).second);
	  std::cout << "jexpulse" << std::endl;
	  sleep(1);
	}
    }
  return (0);
}

int				Monitor::pbc(std::string const &cmd)
{
  int				nb;
  char				c[1024];
  std::map<int, Player>::iterator	it;

  sscanf(cmd.c_str(), "pbc %d %s\n", &nb, c);
  it = this->players.begin();
  for (; it != this->players.end(); ++it)
    {
      if (nb == (*it).second.getNb())
	this->graphic.broadCastHuman((*it).second);
    }
  return (0);
}

int				Monitor::pic(std::string const &cmd)
{
  int				nb;
  int				x;
  int				y;
  int				lvl;
  std::map<int, Player>::iterator	it;

  sscanf(cmd.c_str(), "pic %d %d %d %d\n", &x, &y, &lvl, &nb);
  it = this->players.begin();
  for (; it != this->players.end(); ++it)
    {
      if (nb == (*it).second.getNb() && (*it).second.getX() == x && 
	  (*it).second.getY() == y)
	{
	  (*it).second.setLvl(lvl);
	  this->graphic.beginLvlUpHuman((*it).second);
	}
    }
  return (0);
}

int				Monitor::pie(std::string const &cmd)
{
  int				x;
  int				y;
  int				r;
  std::map<int, Player>::iterator	it;

  sscanf(cmd.c_str(), "pie %d %d %d\n", &x, &y, &r);
  if (x < 0 || this->map.getWidth() < x || y < 0 || this->map.getHeight() < y)
    {
      std::cout << " Error: bad position !";
      return (-2);
    }
  it = this->players.begin();
  for (; it != this->players.end(); ++it)
    {
      if (x == (*it).second.getX() && y == (*it).second.getY() &&
	  (*it).second.getPos() == START_INCANT)
	{
	  if (r == 1)
	    this->graphic.successLvlUpHuman((*it).second);
	  else
	    this->graphic.failLvlUpHuman((*it).second);
	  return (0);
	}
    }
  return (0);
}

int				Monitor::pfk(std::string const &cmd)
{
  int				nb;
  std::map<int, Player>::iterator	it;
  int				x = -1;
  int				y = -1;
  std::string			team = "";

  sscanf(cmd.c_str(), "pfk %d\n", &nb);
  std::cout << "un oeuf!" << std::endl;
  it = this->players.begin();
  for (; it != this->players.end(); ++it)
    {
      if (nb == (*it).second.getNb())
	{
	  x = (*it).second.getX();
	  y = (*it).second.getY();
	  team = (*it).second.getTeam();
	  this->graphic.pondHuman((*it).second);
	}
    }
  if (x != -1 && y != -1 && team.compare("") != 0 && this->players.size() > 0)
    {
      Player	p;

      p.setNb(this->players.size() - 1);
      p.setX(x);
      p.setY(y);
      p.setDir((Position) OEUF);
      p.setPos((Position) OEUF);
      p.setLvl(0);
      p.setTeam(team);
      this->players[this->players.size() - 1] = p;
      this->graphic.drawHuman(this->players[this->players.size() - 1]);
    }
  return (0);
}

int				Monitor::pdr(std::string const &cmd)
{
  int				nb;
  int				r;

  sscanf(cmd.c_str(), "pdr %d %d\n", &nb, &r);
  this->players[nb].ressourceDown((Ressource) r);
  this->graphic.drawCase(this->map.getMap()[this->players[nb].getX()][this->players[nb].getY()],
 this->players[nb].getX(), this->players[nb].getY());
  this->graphic.jetteHuman(this->players[nb]);
  return (0);
}

int				Monitor::pgt(std::string const &cmd)
{
  int				nb;
  int				r;

  sscanf(cmd.c_str(), "pgt %d %d\n", &nb, &r);
  this->players[nb].ressourceUp((Ressource) r);
  this->graphic.drawCase(this->map.getMap()[this->players[nb].getX()][this->players[nb].getY()], this->players[nb].getX(), this->players[nb].getY());
  this->graphic.prendHuman(this->players[nb]);
  return (0);
}

int				Monitor::pdi(std::string const &cmd)
{
  int				nb;

  sscanf(cmd.c_str(), "pdi %d\n", &nb);
  this->graphic.mortHuman(this->players[nb]);
  return (0);
}

int				Monitor::enw(std::string const &cmd)
{
  Player			egg;
  int				e_nb;
  int				p_nb;
  int				x;
  int				y;

  sscanf(cmd.c_str(), "enw %d %d %d %d\n", &e_nb, &p_nb, &x, &y);
  if (x < 0 || this->map.getWidth() < x || y < 0 || this->map.getHeight() < y)
    {
      std::cout << " Error: bad position !";
      return (-2);
    }
  egg.setNb(e_nb);
  egg.setLvl(0);
  egg.setX(x);
  egg.setY(y);
  egg.setInv(10, 0, 0, 0, 0, 0, 0);
  egg.setDir(DOWN);
  egg.setTeam(this->players[p_nb].getTeam());
  this->players[e_nb] = egg;
  return (0);
}

int				Monitor::eht(std::string const &cmd)
{
  int				nb;
  std::map<int, Player>::iterator	it;

  sscanf(cmd.c_str(), "eht %d\n", &nb);
  it = this->players.begin();
  for (; it != this->players.end(); ++it)
    {
      if (nb == (*it).second.getNb() && OEUF == (*it).second.getDir())
	{
	  (*it).second.setPos(OEUF_ECLOT);
	  (*it).second.setDir(OEUF_ECLOT);
	  this->graphic.drawHuman((*it).second);
	}
    }
  return (0);
}

int				Monitor::ebo(std::string const &cmd)
{
  int				nb;

  sscanf(cmd.c_str(), "ebo %d\n", &nb);
  return (0);
}

int				Monitor::edi(std::string const &cmd)
{
  int				nb;

  sscanf(cmd.c_str(), "edi %d\n", &nb);
  return (0);
}

int				Monitor::sgt(std::string const &cmd)
{
  int				t;

  sscanf(cmd.c_str(), "eht %d\n", &t);
  this->time = t;
  return (0);
}

int				Monitor::seg(std::string const &cmd)
{
  char				c[1024];

  sscanf(cmd.c_str(), "seg %s\n", c);
  return (0);
}

int				Monitor::smg(std::string const &cmd)
{
  char				c[1024];

  sscanf(cmd.c_str(), "smg %s\n", c);
  return (0);
}

int				Monitor::suc(std::string const &cmd)
{
  (void) cmd;
  std::cout << " Unknown command.";
  return (-1);
}

int				Monitor::sbp(std::string const &cmd)
{
  (void) cmd;
  std::cout << " Bad parameter.";
  return (-1);
}

std::string			Monitor::m_msz() const
{
  char		c[10] = {'\0'};
  std::string	s;

  snprintf(c, 10, "msz\n");
  s.assign(c);
  return (s);
}

std::string			Monitor::m_bct(int x, int y) const
{
  char		c[30] = {'\0'};
  std::string	s;

  snprintf(c, 30, "bct %d %d\n", x, y);
  s.assign(c);
  return (s);
}

std::string			Monitor::m_mct() const
{
  char		c[10] = {'\0'};
  std::string	s;

  snprintf(c, 10, "mct\n");
  s.assign(c);
  return (s);
}

std::string			Monitor::m_tna() const
{
  char		c[10] = {'\0'};
  std::string	s;

  snprintf(c, 10, "tna\n");
  s.assign(c);
  return (s);
}

std::string			Monitor::m_ppo(Player p) const
{
  char		c[20] = {'\0'};
  std::string	s;

  snprintf(c, 20, "ppo %d\n", p.getNb());
  s.assign(c);
  return (s);
}

std::string			Monitor::m_plv(Player p) const
{
  char		c[20] = {'\0'};
  std::string	s;

  snprintf(c, 20, "plv %d\n", p.getNb());
  s.assign(c);
  return (s);
}

std::string			Monitor::m_pin(Player p) const
{
  char		c[20] = {'\0'};
  std::string	s;

  snprintf(c, 20, "pin %d\n", p.getNb());
  s.assign(c);
  if (send(this->fd, s.c_str(), s.size(), 0) == -1)
    {
      perror("send");
      return (NULL);
    }
  return (s);
}

std::string		Monitor::m_sgt() const
{
  char		c[10] = {'\0'};
  std::string	s;

  snprintf(c, 10, "sgt\n");
  s.assign(c);
  return (s);
}

std::string		Monitor::m_sst() const
{
  char		c[20] = {'\0'};
  std::string	s;

  snprintf(c, 20, "sst %d\n", this->time);
  s.assign(c);
  return (s);
}

void			Monitor::createWindow(int width, int height)
{
  this->graphic.create(width, height);
  std::cout << "Création de la fenêtre" << std::endl;
}

bool			Monitor::isFinish(int ***map, int width, int height, std::map<int, Player>& players)
{
  if (this->graphic.myEvent(map, width, height, players))
    return (false);
  std::cout << "Programme terminé." << std::endl;
  return (true);
}

void			Monitor::display()
{
  this->graphic.display();
}

void			Monitor::checkTime()
{
  if ((this->graphic.getTime() - this->timeRefreshInv) > 2)
    {
      std::map<int, Player>::const_iterator it;
      
      it = this->players.begin();
      this->timeRefreshInv = this->graphic.getTime();
      for (; it != this->players.end(); ++it)
	this->m_pin((*it).second);
    }
}
