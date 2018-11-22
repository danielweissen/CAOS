#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"

/**
 * @class gamefield
 * @author Daniel
 * @date 21/11/2018
 * @file gamefield.h
 * @brief 
 */
struct gamefield {
    struct chip field[42];
};

/**
 * @brief acts like a constructer, all chips get set to " ", so " " idicates a empty space, if a chip is inserted, the string gets changed to the name of the player who inserted the chip
 * @return constructed object
 */
struct gamefield * newGamefield() {
    struct gamefield* newGamefield = malloc(sizeof(struct gamefield));
    int length = sizeof(newGamefield->field)/sizeof(struct chip);
    for(int i = 0; i<length;i++) {
        newGamefield->field[i].playerName = " ";
    }
    return newGamefield;
}




#endif