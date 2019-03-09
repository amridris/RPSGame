/*
 * Subject: CMPE 135            Professor Ron Mak
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */

#ifndef RPSGAME_COMPUTER_H
#define RPSGAME_COMPUTER_H
#include "Player.h"
using namespace std;


class Computer: public Player {
public:
    Computer(){};


    void playTurn(){

        this->playerWeapon.setComputerWeapon();                     //Set computer weapon
    }
};


#endif //RPSGAME_COMPUTER_H
