/*
** generating.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Thu May 31 10:37:41 2012 baptiste bourlet-de-la-vallee
** Last update Sat Jul 14 06:16:55 2012 camille tolsa
*/

#include	"./serveur.h"

void		generating_cmd_graphic(t_init *data)
{
  data->cmd[12] = xmalloc(sizeof(char) * (strlen("msz") + 1));
  sprintf(data->cmd[12], "msz");
  data->cmd[13] = xmalloc(sizeof(char) * (strlen("bct") + 1));
  sprintf(data->cmd[13], "bct");
  data->cmd[14] = xmalloc(sizeof(char) * (strlen("mct") + 1));
  sprintf(data->cmd[14], "mct");
  data->cmd[15] = xmalloc(sizeof(char) * (strlen("tna") + 1));
  sprintf(data->cmd[15], "tna");
  data->cmd[16] = xmalloc(sizeof(char) * (strlen("ppo") + 1));
  sprintf(data->cmd[16], "ppo");
  data->cmd[17] = xmalloc(sizeof(char) * (strlen("plv") + 1));
  sprintf(data->cmd[17], "pin");
  data->cmd[18] = xmalloc(sizeof(char) * (strlen("pin") + 1));
  sprintf(data->cmd[18], "plv");
  data->cmd[19] = xmalloc(sizeof(char) * (strlen("sgt") + 1));
  sprintf(data->cmd[19], "sgt");
  data->cmd[20] = xmalloc(sizeof(char) * (strlen("sst") + 1));
  sprintf(data->cmd[20], "sst");
  data->cmd[21] = NULL;
}

void		generating_cmd(t_init *data)
{
  data->cmd[0] = xmalloc(sizeof(char) * (strlen("avance") + 1));
  sprintf(data->cmd[0], "avance");
  data->cmd[1] = xmalloc(sizeof(char) * (strlen("droite") + 1));
  sprintf(data->cmd[1], "droite");
  data->cmd[2] = xmalloc(sizeof(char) * (strlen("gauche") + 1));
  sprintf(data->cmd[2], "gauche");
  data->cmd[3] = xmalloc(sizeof(char) * (strlen("voir") + 1));
  sprintf(data->cmd[3], "voir");
  data->cmd[4] = xmalloc(sizeof(char) * (strlen("inventaire") + 1));
  sprintf(data->cmd[4], "inventaire");
  data->cmd[5] = xmalloc(sizeof(char) * (strlen("prend") + 1));
  sprintf(data->cmd[5], "prend");
  data->cmd[6] = xmalloc(sizeof(char) * (strlen("pose") + 1));
  sprintf(data->cmd[6], "pose");
  data->cmd[7] = xmalloc(sizeof(char) * (strlen("expulse") + 1));
  sprintf(data->cmd[7], "expulse");
  data->cmd[8] = xmalloc(sizeof(char) * (strlen("broadcast") + 1));
  sprintf(data->cmd[8], "broadcast");
  data->cmd[9] = xmalloc(sizeof(char) * (strlen("incantation") + 1));
  sprintf(data->cmd[9], "incantation");
  data->cmd[10] = xmalloc(sizeof(char) * (strlen("fork") + 1));
  sprintf(data->cmd[10], "fork");
  data->cmd[11] = xmalloc(sizeof(char) * (strlen("connect_nbr") + 1));
  sprintf(data->cmd[11], "connect_nbr");
  generating_cmd_graphic(data);
}

void		generating_time(t_init *data)
{
  data->time[0] = 7;
  data->time[1] = 7;
  data->time[2] = 7;
  data->time[3] = 7;
  data->time[4] = 1;
  data->time[5] = 7;
  data->time[6] = 7;
  data->time[7] = 7;
  data->time[8] = 7;
  data->time[9] = 300;
  data->time[10] = 42;
  data->time[11] = 0;
  data->time[12] = 0;
  data->fd_graphic = 0;
}

void		generating_name_inv(t_init *data)
{
  int		x;

  x = 0;
  while (x != 7)
    bzero(data->name_inv[x++], 11);
  sprintf(data->name_inv[0], "nourriture");
  sprintf(data->name_inv[1], "linemate");
  sprintf(data->name_inv[2], "deraumere");
  sprintf(data->name_inv[3], "sibur");
  sprintf(data->name_inv[4], "mendiane");
  sprintf(data->name_inv[5], "phiras");
  sprintf(data->name_inv[6], "thystame");
  sprintf(data->objets[0], " nourriture");
  sprintf(data->objets[1], " linemate");
  sprintf(data->objets[2], " deraumere");
  sprintf(data->objets[3], " sibur");
  sprintf(data->objets[4], " mendiane");
  sprintf(data->objets[5], " phiras");
  sprintf(data->objets[6], " thystame");
  sprintf(data->objets[7], " joueur");
}

void			generating(t_init *data)
{
  generating_cmd(data);
  generating_time(data);
  generating_name_inv(data);
  data->egg_lst = NULL;
}
