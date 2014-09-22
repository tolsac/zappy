//
// client.cpp for  in /home/tolsa_c//zappy-2015-2014s-tolsa_c/client_zappy
// 
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
// 
// Started on  Wed Jul 11 07:39:22 2012 camille tolsa
// Last update Sun Jul 15 11:55:34 2012 camille tolsa
//

#include "./client.hh"


IA::IA(int ac, char **av)
{
  std::stringstream	ss;
  int			port;
  
  this->ac = ac;
  this->av = av;
  this->check_args();
  for (int i = 0; i < 7; i++)
    this->inv[i] = 0;
  this->inv[0] = 10;
  this->dir = 5;

  ss << av[2];
  ss >> port;
  
  this->team.assign(av[3]);
  this->team.push_back('\n');
  this->co = new Connexion(av[1], port);
  this->fd = this->co->getFd();
  
  this->action[0] = &IA::avance;
  this->action[1] = &IA::droite;
  this->action[2] = &IA::gauche;
  this->action[3] = &IA::voir;
  this->action[4] = &IA::inventaire;
  this->action[5] = &IA::prendre;
  this->action[6] = &IA::poser;
  this->action[7] = &IA::expulser;
  this->action[8] = &IA::broadcast;
  this->action[9] = &IA::incanter;
  this->action[10] = &IA::forker;
  this->action[11] = &IA::piller;

  this->lvl = 1;
  this->number = 1;
  this->auth();
}

IA::~IA()
{

}

bool			IA::check_args()
{
  std::stringstream	ss;
  int			port;
  
  if (this->ac != 4)
    this->usage();
  ss << this->av[2];
  ss >> port;
  if (port <= 1024 || port >= 65536)
    {
      std::cerr << this->av[0] 
		<< ": Port should be included in range 1024-65536" 
		<< std::endl;
      this->usage();
      return (false);
    }
  return (true);
}

void			IA::collectAll()
{
  int			got = 1;
  int			item = 1;
  
  while (got)
    {
      while (this->inv[item] <= this->data.elev[6][item])
	{
	  this->lookingForItems((t_item)item);
	}
      item++;
      if (item != 7)
	got = 0;
    }
}

void			IA::usage()
{
  std::cout << this->av[0] << ": Usage [IP ADDR] [PORT] [TEAM]" << std::endl;
  exit(0);
}

bool			IA::enoughFood()
{
  if (this->inv[0] >= 5)
    return (true);
  else
    return (false);
  return (false);
}

bool			IA::canIUp()
{
  int			item = 1;
  int			i = 0;
  
  if (this->lvl > 7)
    exit(0);
  this->getVision();
  this->piller("");
  while (item != 7)
    {
      if (this->inv[item] >= this->data.elev[this->lvl - 1][item])
	{
	  item++;
	}
      else
	break;
    }
  if (item != 7)
    return (this->lookingForItems((t_item)item));
  item = 1;
  while (item != 7)
    {
      i = 0;
      while (this->data.elev[this->lvl - 1][item] > i)    
	{
	  this->poser(this->data.items[item]);
	  i++;
	}
      item++;
    }
  if (item == 7)
    {
      if ((this->*action[INCANTER])("") == 1)
	return (true);
    }
  return (false);
}

void			IA::randomMove()
{
  int			randomdir;
  
  randomdir = rand() % 7;
  if (randomdir < 5)
    (this->*action[AVANCE])("");
  else if (randomdir == 5)
    (this->*action[GAUCHE])("");
  else if (randomdir == 6)
    (this->*action[DROITE])("");
}

bool			IA::lookingForItems(t_item it)
{
  int			where;

  this->getVision();
  if ((where = this->thereIsHere(it)) != -1)
    {
      if (this->findMyPath(where))
	(this->*action[PRENDRE])(this->data.items[it]);
      return (true);
    }
  else
    {
      this->randomMove();
      return (false);
    }
  return (false);
}

bool			IA::findMyPath(int where)
{
  int			i = 0;
  
  if (where == 0)
    return (true);
  while (where > this->data.max[i] ||
	 where < this->data.min[i])
    {
      i++;
      (this->*action[AVANCE])("");
    }
  i = this->data.middle[i];
  if (where == i)
    return (true);
  if (where > i)
    {
      (this->*action[DROITE])("");
      while (i != where)
  	{
   	  (this->*action[AVANCE])("");
	  i++;
	}
      return (true);
    }
  else if (where < i)
    {
      (this->*action[GAUCHE])("");
      while (i != where)
  	{
   	  (this->*action[AVANCE])("");
	  i--;
	}
      return (true);
    }
  return (false);
}

int			IA::thereIsHere(t_item it)
{
  int			i = -1;
  std::deque<std::deque<int> > ::iterator iter = this->see.begin();
  
  while (iter != this->see.end())
    {
      ++i;
      if ((*iter)[it] > 0)
	{
	  return (i);
	}    
      ++iter;
    }
  return (-1);
}

std::string			IA::gatherMates(std::string s)
{
  int			pos;
  std::stringstream	ss;
  int			lvl;
  
  ss << s.substr(1, 3);
  ss >> lvl;
  if (lvl == this->lvl)
    {
      ss.clear();
      ss << s.substr(0, 2);
	  ss >> pos;
	  switch (pos)
	    {
	    case 0:
	      this->incanter("");
	      exit(0);
		break;
	    case 1:
	      this->avance("");
	      break;
	    case 2:
	      this->avance("");
		this->gauche("");
		this->avance("");
		break;
	    case 3:
	      this->gauche("");
	      this->avance("");
	      break;
	    case 4:
	      this->gauche("");
	      this->avance("");
	      this->gauche("");
	      this->avance("");
	      break;
	    case 5:
	      this->gauche("");
	      this->gauche("");
	      this->avance("");
	      break;
	    case 6:
	      this->droite("");
	      this->avance("");
	      this->droite("");
	      this->avance("");
	      break;
	    case 7:
	      this->droite("");
	      this->avance("");
	      break;
	    case 8:
	      this->avance("");
	      this->droite("");
	      this->avance("");
	      break;
	    }
    }//fin if
  return ("");
}

bool			IA::play()
{
  if (this->enoughFood())
    this->canIUp();
  else
    this->lookingForItems((t_item)0);
  return (true);
}

void			IA::getVision()
{
  int				k = 0;
  std::list<std::string>	lst;
  std::list<std::string>::iterator it;
  std::string			tmp;
  
  this->clearVision();
  this->see.clear();
  this->vision.assign("");
  (this->*action[VOIR])("");
  while (k < (int)this->vision.size())
    {
      tmp += this->vision[k];
      if (this->vision[k] == ',' || this->vision[k] == '}')
	{
	  lst.push_back(tmp);
	  tmp.erase();
	}
      if (this->vision[k] == '}')
	k = this->vision.size();
      k++;
    }
  this->see.clear();
  std::deque<std::deque<int> >  sees;
  sees.clear();
  this->see = sees;
  for (it = lst.begin(); it != lst.end(); ++it)
    {
      std::deque<int>		ss(8, 0);
      int			decal = 0;
      int			how = 0;
      
      while ((how = (*it).find("nourriture", decal)) != std::string::npos)
	{
	  decal = how + 10;
	  ss[0]++;
	}
      decal = 0;
      while ((how = (*it).find("linemate", decal)) != std::string::npos)
	{
	  decal = how + 8;
	  ss[1]++;
	}
      decal = 0;
      while ((how = (*it).find("deraumere", decal)) != std::string::npos)
	{
	  decal = how + 9;
	  ss[2]++;
	}
      decal = 0;
      while ((how = (*it).find("sibur", decal)) != std::string::npos)
	{
	  decal = how + 5;
	  ss[3]++;
	}
      decal = 0;
      while ((how = (*it).find("mendiane", decal)) != std::string::npos)
	{
	  decal = how + 8;
	  ss[4]++;
	}
      decal = 0;
      while ((how = (*it).find("phiras", decal)) != std::string::npos)
	{
	  decal = how + 6;
	  ss[5]++;
	}
      decal = 0;
      while ((how = (*it).find("thystame", decal)) != std::string::npos)
	{
	  decal = how + 8;
	  ss[6]++;
	}      
      decal = 0;
      while ((how = (*it).find("joueur", decal)) != std::string::npos)
	{
	  decal = how + 6;
	  ss[7]++;
	}
      this->see.push_back(ss);
    }
}

void			IA::clearVision()
{
  this->see.clear();
}

int			IA::mainLoop()
{
  bool			game = true;
  
  (this->*action[DROITE])("");
  while (game)
    {
      game = this->play();
    }
  return (0);
}

void		      IA::err(std::string const& msg)
{
  this->valid = false;
  perror(msg.c_str());
}

int			IA::auth()
{
  char			buf[128];
  std::stringstream	ss;

  if (recv(this->fd, buf, 128, 0) == -1)
    err("recv");
  ss << buf;
  ss >> this->nb;
  if (send(this->fd, this->team.c_str(), this->team.size(), 0) == -1)
    err("send");
  if (recv(this->fd, buf, 128, 0) == -1)
    err("recv");
  if (strncmp(buf, "ko\n", 3) == 0)
    {
      std::cout << this->av[0] << ": Wrong team name\n";
      this->usage();
    }
  sscanf(buf, "%d\n", &(this->nb));
  if (recv(this->fd, buf, 128, 0) == -1)
    err("recv");
  sscanf(buf, "%d %d\n", &(this->mapx), &(this->mapy));
  std::cout << "IA n° " << this->nb << std::endl;
  std::cout << "Map [" << this->mapx << ":" << this->mapy << "]" << std::endl;
  std::cout << "Connected to server" << std::endl;
  return (0);
}

int		      IA::piller(std::string const& s)
{
  std::string		tmp = s;
  
  while (this->prendre(this->data.items[0]));
  while (this->prendre(this->data.items[1]));
  while (this->prendre(this->data.items[2]));
  while (this->prendre(this->data.items[3]));
  while (this->prendre(this->data.items[4]));
  while (this->prendre(this->data.items[5]));
  while (this->prendre(this->data.items[6]));
  return (1);
}

int		      IA::isbc(std::string const& s)
{
  if (s.size() > 2)
    {
      if ((s[0] >= '0' && s[0] <= '8') && s[1] == ' ')
	{
	  if (s.find("seriouscat") != std::string::npos)
	    return (1);
	  else
	    return (2);
	}
    }
  return (0);
}

int                   IA::avance(std::string const& s)
{
  char	buf[100] = {'\0'};
  std::string st;
  std::string bc;
  bool bol = false;

  (void)s;
  bc.clear();
  bc.assign("");
  if (send(this->fd, "avance\n", 7, 0) == -1)
    err("send");
  if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();     
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	bol = true;
      gatherMates(bc);	  
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	return (1);
    }
  if (bol)
    return (1);
  return (0);
}

int                   IA::droite(std::string const& s)
{
  char  buf[100] = {'\0'};
  std::string st;
  std::string bc;
  bool bol = false;

  (void)s;
  bc.clear();
  bc.assign("");
  if (send(this->fd, "droite\n", 7, 0) == -1)
    err("send");
  if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }  
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();     
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	bol = true;
      gatherMates(bc);	  
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	return (1);
    }
  if (bol)
    return (1);
  return (0);
}

int                   IA::gauche(std::string const& s)
{
  char  buf[100] = {'\0'};
  std::string st;
  std::string bc;
  bool bol = false;

  (void)s;
  bc.clear();
  bc.assign("");
  if (send(this->fd, "gauche\n", 7, 0) == -1)
    err("send");
    if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();     
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	bol = true;
      gatherMates(bc);	  
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	return (1);
    }
  if (bol)
    return (1);
  return (0);
}

int                   IA::voir(std::string const& s)
{
  std::string		tmp = s;
  char			buf[5000] = {'\0'};
  std::string		st;
  std::string		bc;
  
  if (send(this->fd, "voir\n", 5, 0) == -1)
    err("send");
  if (recv(this->fd, buf, 1000, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();
      st = this->buf.read_buffer();
      this->vision.assign(st);
      gatherMates(bc);
    }
  else
    {
      st = this->buf.read_buffer();
      this->vision.assign(st);
    }
  return (1);
}

int                   IA::inventaire(std::string const& s)
{
  char  buf[100] = {'\0'};
  std::string st;
  std::string bc;
  bool bol = false;

  (void)s;
  bc.clear();
  bc.assign("");
  if (send(this->fd, "inventaire\n", 11, 0) == -1)
    err("send");
  if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();     
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	bol = true;
      gatherMates(bc);	  
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	return (1);
    }
  if (bol)
    return (1);
  return (0);
}

int                   IA::prendre(std::string const& s)
{
  int		      i;
  std::string	      st;
  char  buf[100] = {'\0'};
  std::string bc;
  bool bol = false;

  bc.clear();
  bc.assign(""); 
  i = -1;
  st.assign("prend " + s);
  if (send(this->fd, st.c_str(), st.size(), 0) == -1)
    err("send");
  if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();     
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	{
	  while (s != this->data.items[++i]);
	  this->inv[i]++;
	  bol = true;
	}
      gatherMates(bc);	  
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	{
	    while (s != this->data.items[++i]);
	    this->inv[i]++;
	    return (1);
	}
    }
  if (bol)
    return (1);
  return (0); 
}

int                   IA::poser(std::string const& s)
{
  int		      i = -1;
  std::string	      st;
  char  buf[100] = {'\0'};
  std::string bc;
  bool bol = false;

  bc.clear();
  bc.assign("");
  st.assign("pose " + s);
  if (send(this->fd, st.c_str(), st.size(), 0) == -1)
    err("send");
  while (s != this->data.items[++i]);
  this->inv[i]--;
    if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();     
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	bol = true;
      gatherMates(bc);	  
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	return (1);
    }
  if (bol)
    return (1);
  return (0);
}

int                   IA::expulser(std::string const& s)
{
  char  buf[100] = {'\0'};
  std::string st;
  std::string bc;
  bool bol = false;

  (void)s;
  bc.clear();
  bc.assign("");
  if (send(this->fd, "expulser\n", 9, 0) == -1)
    err("send");
  if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();     
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	bol = true;
      gatherMates(bc);	  
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	return (1);
    }
  if (bol)
    return (1);
  return (0);
}

int                   IA::broadcast(std::string const& s)
{
  char  buf[100] = {'\0'};
  std::string st;
  std::string bc;
  bool bol = false;

  bc.clear();
  bc.assign("");
  st.assign("broadcast " + s);
  if (send(this->fd, st.c_str(), st.size(), 0) == -1)
    err("send");  
    if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();     
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	bol = true;
      gatherMates(bc);	  
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "ok")
	return (1);
    }
  if (bol)
    return (1);
  return (0);
}

int                   IA::incanter(std::string const& s)
{
  std::string		tmp = s;
  char			buf[100] = {'\0'};
  std::string		st;
  char			str[255];
  std::string		bc;
  bool			bol = false;

  bc.clear();
  bc.assign("");
  snprintf(str, 255, "%d seriouscat\n", this->lvl);
  if (this->lvl > 1)
    (this->*action[BROADCAST])(str);
  st.assign("incantation\n");
  if (send(this->fd, st.c_str(), st.size(), 0) == -1)
    err("send");
  if (recv(this->fd, buf, 100, 0) == -1)
    err("recv");
  this->buf.write_buffer(buf);
  st = this->buf.get();
  while (isbc(st) == 2)
    {
      st = this->buf.read_buffer();
      if (recv(this->fd, buf, 100, 0) == -1)
	err("recv");
      this->buf.write_buffer(buf);
      st = this->buf.get();
    }  
  if (isbc(st) == 1)
    {
      bc = this->buf.read_buffer();
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "el")
	{
	  if (recv(this->fd, buf, 100, 0) == -1)
	    err("recv");
	  this->buf.write_buffer(buf);
	  st = this->buf.read_buffer();
	  if (st.substr(0, 2) == "ni")
	    {
	      this->lvl++;
	      bol = true;
	    }
	}
      else
	{
	  this->randomMove();
	}
      gatherMates(bc);
    }
  else
    {
      st = this->buf.read_buffer();
      if (st.substr(0, 2) == "el")
	{
	  sleep(1);
	  if (recv(this->fd, buf, 100, 0) == -1)
	    err("recv");
	  this->buf.write_buffer(buf);
	  st = this->buf.read_buffer();
	  if (st.substr(0, 2) == "ni")
	    {
	      this->lvl++;
	      return (1);
	    }
	}  
      else
	{
	  this->randomMove();
	}
    }
  if (bol)
    return (1);
  return (0);
}

int                   IA::forker(std::string const& s)
{
  std::string		tmp = s;
  int		pid;
  std::string st;
  std::string bc;

  (void)s;
  bc.clear();
  bc.assign("");
  if ((pid = fork()) == -1)
    {
      return (-1);
    }
  else if (pid == 0)
    {

    }
  return (0);
}
