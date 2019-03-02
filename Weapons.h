/*
 * Subject: CMPE 135            Professor Ron Mak
 * Assignment 3: Command Line RPS Game
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */

#ifndef RPSGAME_WEAPONS_H
#define RPSGAME_WEAPONS_H
#include "iostream"
#include "random"
#include <time.h>
#include <stdlib.h>

using namespace std;


enum class weapons{
    ROCK = 0,
    PAPER = 1,                  // weapon enum declaration (0->2)
    SCISSOR = 2
};

class Weapons {

private:
    weapons playerWeapon;           // weapon enum member variable

public:
    Weapons(){

        srand(time(NULL));          // seed srand for random choices

    }

    void setUserWeapon(weapons userChoice) {
        playerWeapon = userChoice;                  // set weapon
    }

    void setComputerWeapon(){


        int option = rand()%3 + 1;                  // random choice from 1-3

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
        return playerWeapon;                // return weapon
    }

    string to_string(){

        string weaponName;
        switch(playerWeapon){
            case weapons::ROCK: weaponName = "ROCK";
            break;
            case weapons::PAPER: weaponName = "PAPER";
            break;
            case weapons::SCISSOR: weaponName = "SCISSOR";
            break;
        }

        return weaponName;
    }

    void printWeaponList() {

        cout << "Choose your weapon:" << endl;                      // print weapon to the user to choose
        cout << "1: ROCK" << std::endl;
        cout << "2: PAPER" << endl;
        cout << "3: SCISSOR" << endl;
    }

};


#endif //RPSGAME_WEAPONS_H
