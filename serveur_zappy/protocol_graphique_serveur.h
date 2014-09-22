/*
** protocol_graphique_serveur.h for zappy in /home/boyer_b//Documents
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Fri Jun 22 15:42:38 2012 bertrand boyer
** Last update Sun Jul 15 09:33:56 2012 camille tolsa
*/

#ifndef _PROTOCOL_GRAPHIQUE_SERVEUR_H_
#define _PROTOCOL_GRAPHIQUE_SERVEUR_H_

#define STR_SIZE	128

/* Functions in protocol_graphique_serveur_p1.c */
char		*s_mapsize(int x, int y);			/*Taille de la carte*/
char		*s_sendcas(int ***map, int x, int y);		/*Contenu d'une case*/
char		*s_sendmap(int ***map, int l, int h);		/*Contenu de la carte*/
char		*s_sendtea(char **team_name);			/*Nom des equipes*/

/* Functions in protocol_graphique_serveur_p2.c */
char		*s_playernew(t_light *p);			/*Connexion d'un nouveau player*/
char		*s_playerpos(t_light *p);			/*Position d'un joueur*/
char		*s_playerlvl(t_light *p);			/*Niveau d'un joueur*/
char		*s_playerinv(t_light *p);			/*Inventaire d'un joueur*/

/* Functions in protocol_graphique_serveur_p3.c */
char		*s_playerexp(t_light *p);			/*Un joueur expulse*/
char		*s_playerbro(t_light *p, char *m);		/*Un joueur fait un broadcast*/
char		*s_playerinc(t_player *p);			/*Premier joueur lance l’incantation pour tous les suivants sur la case*/
char		*s_playerend(int x, int y, int res);		/*Fin de l’incantation sur la case donnée avec le résultat R (0 ou 1)*/
char		*s_playerfrk(t_light *p);			/*Le joueur pond un oeuf*/

/* Functions in protocol_graphique_serveur_p4.c */
char		*s_playerdro(t_light *p, int ressource);	/*Le joueur jette une ressource*/
char		*s_playerget(t_light *p, int ressource);	/*Le joueur prend une ressource*/
char		*s_playerdie(t_light *p);			/*Le joueur est mort de faim*/

/* Functions in protocol_graphique_serveur_p5.c */
char		*s_eggnew(t_light *egg, t_light *p);		/*L'oeuf a été pondu sur la case par le joueur*/
char		*s_eggend(t_light *egg);			/*L'oeuf eclot*/
char		*s_eggcon(t_light *egg);			/*Un joueur s'est connecte pour l'oeuf*/
char		*s_eggdie(t_light *egg);			/*L'oeuf eclos est mort de faim*/

/* Functions in protocol_graphique_serveur_p6.c */
char		*s_servtim(int speed);				/*Demande de l'unite de temps courante sur le serveur*/
char		*s_endgame(char *team);				/*Fin du jeu. L'equipe donnee remporte la partie*/
char		*s_message(char *msg);				/*Message du serveur*/
char		*s_unkncmd();					/*Commande inconnue*/
char		*s_badpara();					/*Mauvais parametre pour la commande*/

#endif /* !_PROTOCOL_GRAPHIQUE_H_ */
