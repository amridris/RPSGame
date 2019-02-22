//
// Created by Amer on 2/22/2019.
//

#ifndef RPSGAME_COMPUTER_H
#define RPSGAME_COMPUTER_H
#include "Player.h"
using namespace std;

class Computer: public Player {
public:
    Computer(){};
    void playTurn(){
        //computer implementation
        this->playerWeapon.setComputerWeapon();
    }
};


#endif //RPSGAME_COMPUTER_H
