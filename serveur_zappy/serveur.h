/*
** zappy.h for zappy in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/serveur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Fri Jun 22 16:08:06 2012 bertrand boyer
** Last update Sun Jul 15 18:04:09 2012 baptiste bourlet-de-la-vallee
*/

#ifndef		__SERVEUR_H__
#define		__SERVEUR_H__

#include "./structures.h"
#include "./protocol_graphique_serveur.h"

/* Functions */
int		snprintf(char *str, size_t size, const char *format, ...);
int		usleep(int usec);
char		*strdup(const char *s);

/* Functions in add_players.c */
int		nb_place_dispo(t_init *data, char *name);
int		find_team(t_init *data, t_player_lst *p, char *name);
int		conversation(t_init *data, t_player_lst *p, char *buf);
int		add_player(t_init *data, t_player_lst *p, char *buf);
int		add_player_graphic(t_init *data, t_player_lst *p);

/* Functions in add_player_spec.c */
int		connection_to_egg(t_init *data, t_player_lst *p, char *name);

/* Functions in broadcast.c */
int		from(t_player*, t_player*, int, int);
int		from2(t_player*, t_player*, int, int);
int		broadcast(t_init *, t_player*, char*);

/* Functions in buffer.c */
void		init_buffer(struct s_buffer*);

/* Functions in buffer_functions.c */
int		write_buffer(struct s_buffer *b, char *s);
char		*read_buffer(struct s_buffer *b);
char		*get(struct s_buffer *b);
void		clear_buffer(t_buffer *b);
void		multi_command(t_buffer *b, int *);

/* Functions in check_timer.c */
int		check_timer(t_init*);

/* Functions in command_graphic_p1.c */
int             msz(t_init *data, t_player *g, char *msg);
int             bct(t_init *data, t_player *g, char *msg);
int             mct(t_init *data, t_player *g, char *msg);
int             tna(t_init *data, t_player *g, char *msg);
int             ppo(t_init *data, t_player *g, char *msg);

/* Functions in command_graphic_p2.c */
int             plv(t_init *data, t_player *g, char *msg);
int             pin(t_init *data, t_player *g, char *msg);
int             sgt(t_init *data, t_player *g, char *msg);
int             sst(t_init *data, t_player *g, char *msg);

/* Functions in connect_nbr.c */
int		connect_nbr(t_init *data, t_player *p, char *msg);

/* Functions in do_client.c */
int		do_client(int socket_client, t_player_lst **tmp, t_init *data);

/* Functions in do_server.c */
int		do_server(t_init *data);

/* Functions in end.c */
void		do_the_end(t_init *data, char *name);
int		check_lvl_players(t_init *data, t_player_lst *tmp);
void		test_end(t_init *data);

/* Functions in expulse.c */
void		goU(t_player *p, int mapx, int mapy, int);
void		goR(t_player *p, int mapx, int mapy, int);
void		goD(t_player *p, int mapx, int mapy, int);
void		goL(t_player *p, int mapx, int mapy, int);
int		expel(t_init *data, t_player *p, char *msg);

/* Functions in fork_egg.c */
t_egg		*create_egg(t_player *p, t_init *data);
int		fork_egg(t_init *data, t_player *p, char *msg);
t_egg		*delete_egg(t_egg **egg_list, t_egg *egg);

/* Functions in functions.c */
void		functions(t_init *data, t_player *p, char *msg);

/* Functions in generating.c */
void		generating_cmd_graphic(t_init *data);
void		generating_cmd(t_init *data);
void		generating_time(t_init *data);
void		generating_name_inv(t_init *data);
void		generating(t_init *data);

/* Functions in get_option.c */
void		is_a_n(int c, char **av, t_init *data);
int		aff_options(t_init *data);
int		get_option_init(int ac, char **av, t_init *data);

/* Functions in init_list.c*/
void		init_pos(t_player_lst *p, t_init *data);
void		init_inv(t_player_lst *p);
void		init_action(t_init *p);
void		init_all(t_player_lst *node, int socket_client, t_init *data);

/* Functions in inv.c */
int		inventory(t_init *data, t_player *p, char *msg);

/* Functions in list.c */
int		new_player(int socket_client, t_init *data);
void            send_die(t_player *p, t_init *data);
int		init_delete(t_init *data, t_player_lst *save);
t_player_lst	*del_player(int socket_client, t_init *data);

/* Functions in main.c */
int		free_all(t_init *d);
void		ctrl_c(int sig);
/* int		main(int ac, char **av); */

/* Functions in map.c */
int		*generate_stuff();
int		generating_map(t_init *d);

/* Functions in message.c **/
int		received(t_player *p, char *buf);
int		sending(t_init *data, t_player *p, char *msg);

/* Functions in move.c */
int		ahead(t_init *data, t_player *p, char *msg);
int		left(t_init *data, t_player *p, char *msg);
int		right(t_init *data, t_player *p, char *msg);

/* Functions in file incantation.c */
int             how_many_players_on_my_case(t_init *data, int x, int y, int level);
int             is_there_enough_ressources(t_init *data, int x, int y, int level);
void            send_msg_to_all(t_init *data, t_player *p, char *msg, int flag);
int             incantation(t_init *data, t_player *p, char *msg);
int             incantation_end(t_init *data, t_player *p);

/* Functions in put.c */
int		put(t_init *data, t_player *p, char *msg);

/* Functions in send_all.c */
int		send_all(t_init *data, t_player *g);

/* Functions in server.c */
int		max(t_init *data);
void		set_fd(t_init *data);
int		init_monitor(t_init *data, struct timeval *tv, int *ret, t_player_lst **tmp);
int		monitor(t_init *data);
int		fillstruct(struct sockaddr_in *sin, t_init *data);

/* Functions in take.c */
int		take(t_init *data, t_player *p, char *msg);

/* Functions in timer.c */
void		update_timer(t_player*);
int		setup_timer(t_player*, t_init*);
int		istimeout(t_player*);
int		istimeout_next(t_player*);

/* Functions in utils.c */
void		usage();
void		*xrealloc(void *ptr, size_t size);
void		*xmalloc(int size);
int		merror(const char *str);

/* Functions in view.c */
int		see(t_init *d, t_player *p, char *msg);
char		*viewInit(char *str, int lvl[8], int i[2]);
int		goToNextLine(t_init *d, t_player *p, int viewXY[2], int lvl);
int		goToNextCase(t_init *d, t_direction dir, int viewXY[2]);
char		*append(t_init *d, t_player *p, int viewXY[2], char *str);

/* Functions in world_options.c */
void		is_a_p(int c, char *str, t_init *data);
void		is_a_x(int c, char *str, t_init *data);
void		is_a_y(int c, char *str, t_init *data);
void		is_a_c(int c, char *str, t_init *data);
void		is_a_t(int c, char *str, t_init *data);

#endif
