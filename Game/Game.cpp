#include "Game.h"

#include <iostream>
#include <cstdlib>

Game::Game() {
    std::cout << "Paper, Scissors, Rock Game\n==========================\n\n";

    _running = true;
}

Game::~Game() {
}

bool Game::isRunning() {
    return _running;
}

Rules::Options Game::GetUserOption() {
    int option;

    std::cin >> option;

    if (option == 1) {
        return Rules::Options::Paper;
    } else if (option == 2) {
        return Rules::Options::Scissors;
    } else if (option == 3) {
        return Rules::Options::Rock;
    }

    return Rules::Options::EndGame;
}

Rules::Options Game::GetPCOption() {
    return static_cast<Rules::Options>(1 + (rand() % 3));
}

void Game::StartNewGame() {
    std::cout << "Select your option (1-Paper, 2-Scissors, 3-Rock, 0-End Game): ";

    auto playerOption = GetUserOption();

    if (playerOption == Rules::Options::EndGame) {
        EndGame();
        return;
    }

    auto pcOption = GetPCOption();

    CheckWinner(playerOption, pcOption);
}

Rules::Players Game::CheckWinner(Rules::Options playerOption, Rules::Options pcOption) {
    auto winner = Rules::CheckWinner(playerOption, pcOption);

    ShowOptions(playerOption, pcOption);

    if (winner == Rules::Players::Human) {
        std::cout << "You win!\n";
    } else if (winner == Rules::Players::PC) {
        std::cout << "PC wins!\n";
    } else {
        std::cout << "Draw game!\n";
    }

    return winner;
}

void Game::ShowOptions(Rules::Options playerOption, Rules::Options pcOption) {
    std::cout << "You choose : " << OptionToString(playerOption)
        << " and PC choose : " << OptionToString(pcOption) << "\n";
}

std::string Game::OptionToString(Rules::Options option) {
    if (option == Rules::Options::Paper) {
        return "Paper";
    } else if (option == Rules::Options::Scissors) {
        return "Scissors";
    } else if (option == Rules::Options::Rock) {
        return "Rock";
    }
    
    return "Invalid option!";
}

void Game::EndGame() {
    _running = false;
    std::cout << "End of game.\n\n";
}