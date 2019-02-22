//
// Created by Amer on 2/22/2019.
//

#ifndef RPSGAME_WEAPONS_H
#define RPSGAME_WEAPONS_H
#include "iostream"
#include "random"

using namespace std;
enum class weapons{
    ROCK = 0,
    PAPER = 1,
    SCISSOR = 2
};

class Weapons {

private:
    weapons playerWeapon;

public:
    Weapons(){

    }

    void setUserWeapon(weapons userChoice) {
        playerWeapon = userChoice;
    }

    void setComputerWeapon(){
        int option = 1;
        switch(option){
            case 1: playerWeapon = weapons::ROCK;
            break;
            case 2: playerWeapon = weapons::PAPER;
            break;
            case 3: playerWeapon = weapons::SCISSOR;
            break;
            default: playerWeapon = weapons::ROCK;
            break;
        }
    };

    weapons  getWeapon(){
        return playerWeapon;
    }

    void printWeaponList() {

        cout << "Choose your weapon:" << endl;
        cout << "1: ROCK" << std::endl;
        cout << "2: PAPER" << endl;
        cout << "3: SCISSOR" << endl;
    }

};


#endif //RPSGAME_WEAPONS_H
