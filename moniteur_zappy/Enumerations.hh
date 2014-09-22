/*
** Enumerations.hh for moniteur in /home/boyer_b//Documents/Epitech/projets/zappy-2015-2014s-tolsa_c/moniteur_zappy
**
** Made by bertrand boyer
** Login   <boyer_b@epitech.net>
**
** Started on  Thu Jul  5 15:01:57 2012 bertrand boyer
// Last update Sun Jul 15 17:02:16 2012 erick clarivet
*/

#ifndef __ENUMERATIONS_HH__
#define __ENUMERATIONS_HH__

enum		Position
  {
    UP = 1,
    RIGHT = 2,
    DOWN = 3,
    LEFT = 4,
    NONE = 5,
    BROADCAST = 6,
    START_INCANT = 7,
    SUCCESS_INCANT = 8,
    POND = 9,
    JETTE = 10,
    PREND = 11,
    MORT = 12,
    OEUF = 13,
    OEUF_ECLOT = 14,
    EXPULSE = 15,
    FAIL_INCANT = 16
    // oeuf a ete pondu par le joueur kesako?
    // le joueur s'est connecte pour loeuf, wtf?
    // loeuf eclo est mort de faim, omg de wtf de pain de bread!
    
  };

enum		Ressource
  {
    NOURRITURE,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

enum		Action
  {
    MSZ,
    BCT,
    TNA,
    PNW,
    PPO,
    PLV,
    PIN,
    PEX,
    PBC,
    PIC,
    PIE,
    PFK,
    PDR,
    PGT,
    PDI,
    ENW,
    EHT,
    EBO,
    EDI,
    SGT,
    SEG,
    SMG,
    SUC,
    SBP
  };

#endif
