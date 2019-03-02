/*
 * Subject: CMPE 135            Professor Ron Mak
 * Assignment 3: Command Line RPS Game
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */

#ifndef RPSGAME_PLAYER_H
#define RPSGAME_PLAYER_H
#include "Weapons.h"

class Player {
private:
    int wins, losses, ties;

public:
    Weapons playerWeapon;

public:
    Player(): wins(0), losses(0), ties(0){};

    virtual void playTurn() = 0;

    void setWins(){
        wins++;
    }

    int getWins(){
        return wins;
    }

    void setLosses(){
        losses++;
    }

    int getLosses(){
        return losses;
    }

    void setTies(){
        ties++;
    }

    int getTies(){
        return ties;
    }

};


#endif //RPSGAME_PLAYER_H
