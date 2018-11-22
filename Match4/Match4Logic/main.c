#include <stdio.h>
#include <stdlib.h>
#include "match4.h"
#include "winningConditions.h"

void clrscr()   {
    system("@cls||clear");
}

int main(int argc, char **argv) {
    struct match4 * myGame = newMatch4("XXX","000");
    
    int a;
    while(!myGame->player1.wonGame&&!myGame->player2.wonGame) {
        if(strcmp(myGame->turn,myGame->player1.playerName)==0) {
            printf("\n\nPlayer1 put number between 0 and 6: ");
            scanf("%d", &a);
            clrscr();
            if(a<0||a>6) {
                continue;
            }
            insertChip(&myGame->player1,&myGame->mainfield,a);
            printField(myGame);
        } else if(strcmp(myGame->turn,myGame->player2.playerName)==0) {
            printf("\n\nPlayer2 put number between 0 and 6: ");
            scanf("%d", &a);
            clrscr();
            if(a<0||a>6) {
                continue;
            }
            insertChip(&myGame->player2,&myGame->mainfield,a);
            printField(myGame);
        }
        checkWinningConditions(myGame);
        changeTurn(myGame);
        }
        
        printf(myGame->congratulations,whoWon(myGame),myGame->startingpoint,myGame->endpoint);
    }
    
    
    
    
