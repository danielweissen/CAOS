#ifndef MATCH4_H
#define MATCH4_H


#include "player.h"
#include <stdbool.h>
#include "gamefield.h"


void insertChip(struct player * thisplayer, struct gamefield * thisgamefield, int collumn);
struct match4 * newMatch4(char * player1Name, char * player2Name);
void changeTurn(struct match4 * thismatch4);
int whichCollumn(int fieldindex);




/**
 * @class match4
 * @author Daniel
 * @date 21/11/2018
 * @file match4.h
 * @brief this struct is used to put all the elements together neccesarry for the match4 game, it is to be used when creating a match4 game
 */
struct match4 {
    struct player player1;
    struct player player2;
    struct gamefield mainfield;
    char * turn;
    char * congratulations;
    int startingpoint;
    int endpoint;
};

/**
 * @brief this method is used to setup the match4 struct, it should be used when creating a match4 struct
 * @param player1Name name used to identify player 1
 * @param player2Name name used to identify player 2
 * @return the match4 struct as a pointer
 */
struct match4 * newMatch4(char * player1Name, char * player2Name) {
    struct player * player1 = newPlayer(player1Name);
    struct player * player2 = newPlayer(player2Name);
    struct gamefield * mainfield = newGamefield();
    
    struct match4 * newMatch4 = malloc(sizeof(struct match4));
    
    newMatch4->player1 = *player1;
    newMatch4->player2 = *player2;
    newMatch4->mainfield = *mainfield;
    newMatch4->turn = player1->playerName;
    newMatch4->congratulations = NULL;
    newMatch4->startingpoint = 0;
    newMatch4->endpoint = 0;
    
    
    return newMatch4;
    
}

char * whoWon(struct match4 * thismatch4) {
    if(thismatch4->player1.wonGame&&!thismatch4->player2.wonGame) {
        return thismatch4->player1.playerName;
    } else if(thismatch4->player2.wonGame&&!thismatch4->player1.wonGame) {
        return thismatch4->player2.playerName;
    } else {
        return "DRAW";
    }
}


/**
 * @brief inserts a chip at the specified collumn, also checks if there is enough space to insert the chip
 * @param thisplayer player who inserts the chip
 * @param thisgamefield gamefield the chip gets inserted into
 * @param collumn collumn the chip should be inserted into, collumn 0 is the collumn to the very left of the gameboard, collumn 6 is the last collumn
 */
void insertChip(struct player * thisplayer, struct gamefield * thisgamefield, int collumn) {
    collumn += 35;
    if(collumn < 35 || collumn > 41) {
        printf("only put in numbers between 0 and 6");
        return;
    }
    
    while(strcmp(thisgamefield->field[collumn].playerName," ")!=0) {
        collumn -= 7;
        if(collumn<0) {
            printf("collumn is full");
            return;
        }
    }
    
    thisgamefield->field[collumn].playerName = thisplayer->playerName;
}


int whichCollumn(int fieldindex) {
    while(1) {
        if(fieldindex==0) {
            return 0;
        } else if(fieldindex==1) {
            return 1;
        } else if(fieldindex==2) {
            return 2;
        } else if(fieldindex==3) {
            return 3;
        } else if(fieldindex==4) {
            return 4;
        } else if(fieldindex==5) {
            return 5;
        } else if(fieldindex==6) {
            return 6;
        }
        fieldindex-=7;
    }
}



/**
 * @brief changes turn variable that is part of match4 structure
 * @param thismatch4
 */
void changeTurn(struct match4 * thismatch4) {
    if(strcmp(thismatch4->player1.playerName,thismatch4->turn)==0) {
        thismatch4->turn = thismatch4->player2.playerName;
    } else {
        thismatch4->turn = thismatch4->player1.playerName;
    }
}

/**
 * @brief mathod to print a gamefield
 * @param thisgamefield
 */
void printField(struct match4 * thismatch4) {
    int length = sizeof(thismatch4->mainfield.field)/sizeof(struct chip);
    for(int i = 0; i<7;i++) {
        printf(" %d\t",i);
    }
    for(int i = 0; i<length; i++) {
        if(i%7==0) {
            printf("\n");
        }
        printf("%s\t",thismatch4->mainfield.field[i].playerName);
    }
    printf("\n");
}




#endif