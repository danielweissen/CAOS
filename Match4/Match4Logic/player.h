#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "chip.h"

/**
 * @class player
 * @author Daniel
 * @date 21/11/2018
 * @file player.h
 * @brief player has a name and a state if he won the game or not
 */
struct player {
    char * playerName;
    bool wonGame;
};

// this opperates like a constructor, always use this function when creating a player
// make sure not to create 2 players with the same name, or its gonna mess everything up
struct player * newPlayer(char * playerName) {
    struct player* newPlayer = malloc(sizeof(struct player));
    newPlayer->playerName = playerName;
    newPlayer->wonGame = false;
    
    return newPlayer;
}

#endif
