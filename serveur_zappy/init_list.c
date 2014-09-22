/*
** init_list.c for ZAPPY in /home/bourle_b//afs/B3/unix/zappy/project
**
** Made by baptiste bourlet-de-la-vallee
** Login   <bourle_b@epitech.net>
**
** Started on  Mon May 21 23:58:28 2012 baptiste bourlet-de-la-vallee
** Last update Sun Jul 15 08:03:58 2012 camille tolsa
*/

#include	"./serveur.h"

void		init_pos(t_player_lst *p, t_init *data)
{
  p->player.light.pos.y = rand() % (data->width);
  p->player.light.pos.x = rand() % (data->height);
}

/* food ==> 1 = 126 * unite de temps en vie */
void		init_inv(t_player_lst *p)
{
  p->player.light.inv[0] = 10;
  p->player.light.inv[1] = 0;
  p->player.light.inv[2] = 0;
  p->player.light.inv[3] = 0;
  p->player.light.inv[4] = 0;
  p->player.light.inv[5] = 0;
  p->player.light.inv[6] = 0;
}

void		init_action(t_init *p)
{
  p->action[AVANCER] = &ahead;
  p->action[DROITE] = &right;
  p->action[GAUCHE] = &left;
  p->action[VOIR] = &see;
  p->action[INVENTAIRE] = &inventory;
  p->action[PRENDRE] = &take;
  p->action[POSER] = &put;
  p->action[EXPULSER] = &expel;
  p->action[BROADCAST] = &broadcast;
  p->action[INCANTER] = &incantation;
  p->action[FORKER] = &fork_egg;
  p->action[CONNECTER] = &connect_nbr;
  p->action[MAPSIZE] = &msz;
  p->action[GETCASE] = &bct;
  p->action[GETMAP] = &mct;
  p->action[GETTEAM] = &tna;
  p->action[PLAYERPOS] = &ppo;
  p->action[PLAYERINV] = &pin;
  p->action[PLAYERLVL] = &plv;
  p->action[GETTIME] = &sgt;
  p->action[SETTIME] = &sst;
}

void		init_all(t_player_lst *l, int socket_client, t_init *data)
{
  l->next = NULL;
  l->player.fd = socket_client;
  l->player.ghost = 1;
  l->player.answer = NULL;
  l->player.timer = 10;
  l->player.start = 0;
  l->player.end = 0;
  l->player.incant = 0;
  l->player.life = time(NULL);
  if ((l->player.save_time = time(NULL)) == -1)
    merror("time");
  l->player.light.lvl = 1;
  l->player.light.team = NULL;
  l->player.light.nb = socket_client - 3;
  l->player.light.dir = DOWN;
  init_pos(l, data);
  init_inv(l);
  init_action(data);
  init_buffer(&(l->player.buf));
  init_buffer(&(l->player.ans));
  printf("\033[33;36mAdded new player %d at (%d, %d)\033[33;0m\n",
	 l->player.light.nb, l->player.light.pos.x, l->player.light.pos.y);
}
