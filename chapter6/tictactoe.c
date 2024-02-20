#include <stdio.h>


int main() {
    stateT state;
    moveT move;

    GiveInstructions();
    state = NewGame();
    while (!GameIsOver(state)) {
        DisplayGame(state);
        switch (WhoseTurn(state)) {
            case Human:
                move = GetUserMove(state);
                break;
            case Computer:
                move = ChooseComputerMove(state);
                break;
        }
        MakeMove(state, move);
    }
    AnnounceResult(state);
}