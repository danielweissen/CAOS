#ifndef WINNING_CONDITIONS_H
#define WINNING_CONDITIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "match4.h"

bool chipBelongsToPlayer(struct chip chipToCheck, struct player * playerToCheck);
bool match4Occured(bool * a, int length);
void checkHorizontal(struct match4 * thismatch4);
void checkWinningConditions(struct match4 * currentGame);
void checkVertical(struct match4 * thismatch4);
void checkNorthEast(struct match4 * thismatch4);
void checkNorthWest(struct match4 * thismatch4);

void checkWinningConditions(struct match4 * currentGame) {
    checkHorizontal(currentGame);
    checkVertical(currentGame);
    checkNorthEast(currentGame);
    checkNorthWest(currentGame);
}


void checkHorizontal(struct match4 * thismatch4) {
    struct chip * chips = thismatch4->mainfield.field;
    struct player * playerToCheck = &thismatch4->player1;
    int length = sizeof(thismatch4->mainfield.field)/sizeof(struct chip);
    bool won[] = {false,false,false,false};
    
    for(int player = 0; player <2; player++) {
        if(player==1) {
            playerToCheck = &thismatch4->player2;
        }
        for(int i = 0; i<length;i++) {
            if(chipBelongsToPlayer(chips[i],playerToCheck)) {
                if(whichCollumn(i)==4||whichCollumn(i)==5||whichCollumn(i)==6) {
                    continue;
                }
                for(int e = 0; e<4;e++) {
                    won[e] = chipBelongsToPlayer(chips[i+e],playerToCheck);
                }
                if(match4Occured(won,(sizeof(won)/sizeof(bool)))) {
                    playerToCheck->wonGame = true;
                    thismatch4->congratulations = "\n\n\n\nCongratulations!\n%s won by matching horizontally from position %d to position %d \n";
                    thismatch4->startingpoint = i;
                    thismatch4->endpoint = i+3;
                    return;
                }
            }
            won[0] = false; won[1] = false; won[2] = false; won[3] = false;
        }
    }
}

void checkNorthEast(struct match4 * thismatch4) {
    struct chip * chips = thismatch4->mainfield.field;
    struct player * playerToCheck = &thismatch4->player1;
    int length = sizeof(thismatch4->mainfield.field)/sizeof(struct chip);
    bool won[] = {false,false,false,false};
    
    for(int player = 0; player <2; player++) {
        if(player==1) {
            playerToCheck = &thismatch4->player2;
        }
        for(int i = 0; i<length;i++) {
            if(chipBelongsToPlayer(chips[i],playerToCheck)) {
                if(whichCollumn(i)==4||whichCollumn(i)==5||whichCollumn(i)==6) {
                    continue;
                }
                int temp = i;
                for(int e = 0; e<4;e++) {
                    won[e] = chipBelongsToPlayer(chips[temp],playerToCheck);
                    temp-=6;
                    if(temp<0) {
                        break;
                    }
                }
                if(match4Occured(won,(sizeof(won)/sizeof(bool)))) {
                    playerToCheck->wonGame = true;
                    thismatch4->congratulations = "\n\n\n\nCongratulations!\n%s won by matching diagonally from position %d to position %d \n";
                    thismatch4->startingpoint = i;
                    thismatch4->endpoint = temp+6;
                    return;
                }
            }
            won[0] = false; won[1] = false; won[2] = false; won[3] = false;
        }
    }
}

void checkNorthWest(struct match4 * thismatch4) {
    struct chip * chips = thismatch4->mainfield.field;
    struct player * playerToCheck = &thismatch4->player1;
    int length = sizeof(thismatch4->mainfield.field)/sizeof(struct chip);
    bool won[] = {false,false,false,false};
    
    for(int player = 0; player <2; player++) {
        if(player==1) {
            playerToCheck = &thismatch4->player2;
        }
        for(int i = 0; i<length;i++) {
            if(chipBelongsToPlayer(chips[i],playerToCheck)) {
                if(whichCollumn(i)==0||whichCollumn(i)==1||whichCollumn(i)==2) {
                    continue;
                }
                int temp = i;
                for(int e = 0; e<4;e++) {
                    won[e] = chipBelongsToPlayer(chips[temp],playerToCheck);
                    temp-=8;
                    if(temp<0) {
                        break;
                    }
                }
                if(match4Occured(won,(sizeof(won)/sizeof(bool)))) {
                    playerToCheck->wonGame = true;
                    thismatch4->congratulations = "\n\n\n\nCongratulations!\n%s won by matching diagonally from position %d to position %d \n";
                    thismatch4->startingpoint = i;
                    thismatch4->endpoint = temp+8;
                    return;
                }
            }
            won[0] = false; won[1] = false; won[2] = false; won[3] = false;
        }
    }
}


void checkVertical(struct match4 * thismatch4) {
    struct chip * chips = thismatch4->mainfield.field;
    struct player * playerToCheck = &thismatch4->player1;
    int length = sizeof(thismatch4->mainfield.field)/sizeof(struct chip);
    bool won[] = {false,false,false,false};
    
    for(int player = 0; player <2; player++) {
        if(player==1) {
            playerToCheck = &thismatch4->player2;
        }
        for(int i = 0; i<length;i++) {
            if(chipBelongsToPlayer(chips[i],playerToCheck)) {
                int temp = i;
                for(int e = 0; e<4;e++) {
                    won[e] = chipBelongsToPlayer(chips[temp],playerToCheck);
                    temp-=7;
                    if(temp<0) {
                        break;
                    }
                }
                if(match4Occured(won,(sizeof(won)/sizeof(bool)))) {
                    playerToCheck->wonGame = true;
                    thismatch4->congratulations = "\n\n\n\nCongratulations!\n%s won by matching vertically from position %d to position %d \n";
                    thismatch4->startingpoint = i;
                    thismatch4->endpoint = temp+7;
                    return;
                }
            }
            won[0] = false; won[1] = false; won[2] = false; won[3] = false;
        }
    }
}


bool chipBelongsToPlayer(struct chip chipToCheck, struct player * playerToCheck) {
    if(strcmp(chipToCheck.playerName,playerToCheck->playerName)==0) {
        return true;
    } else {
        return false;
    }
}

bool match4Occured(bool * a, int length) {
    for(int i = 0; i < length; i++) {
        if(!a[i]) {
            return false;
        }
    }
    return true;
}



#endif