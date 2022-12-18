#ifndef __GAME_H__
#define __GAME_H__

#include "Rules.h"

#include <string>

class Game {
    bool _running;

public:
    Game();
    ~Game();
    bool isRunning();
    void StartNewGame();

private:
    Rules::Options GetUserOption();
    Rules::Options GetPCOption();
    Rules::Players CheckWinner(Rules::Options playerOption, Rules::Options pcOption);
    void ShowOptions(Rules::Options playerOption, Rules::Options pcOption);
    std::string OptionToString(Rules::Options option);
    void EndGame();

};

#endif