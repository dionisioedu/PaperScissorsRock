#ifndef __RULES_H__
#define __RULES_H__

class Rules {
public:
    enum Options {
        EndGame,
        Paper,
        Scissors,
        Rock,
    };

    enum Players {
        Human,
        PC,
        Draw,
    };

    static Players CheckWinner(Options p1, Options p2) {
        if (p1 == Paper && p2 == Rock
            || p1 == Scissors && p2 == Paper
            || p1 == Rock && p2 == Scissors) {
            return Players::Human;
        } else if (p2 == Paper && p1 == Rock
            || p2 == Scissors && p1 == Paper
            || p2 == Rock && p1 == Scissors) {
                return Players::PC;
        }

        return Players::Draw;
    }
};

#endif