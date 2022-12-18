#include <iostream>

#include "Game/Game.h"

int main() {

    Game paperScissorsRockGame;

    while (paperScissorsRockGame.isRunning()) {
        paperScissorsRockGame.StartNewGame();
    }

    return 0;
}