/*
 * Subject: CMPE 135            Professor Ron Mak
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */


#ifndef RPSGAME_USER_H
#define RPSGAME_USER_H

#include "Player.h"
#include <iostream>


class User: public Player{
private:
    std::string name;
    bool userPlay;

public:
    User(): name(""), userPlay(false){};

    std::string getUsername(){ return name; }               //get username

    void setUsername(){
        cout<<"Please enter your name?"<<endl;              // set username using cin
        getline(cin, name);
    }

    void playTurn() {

        userPlay = true;
        int option = 0;

        do {

            playerWeapon.printWeaponList();                     // Ask user to choose weapon and check the input value
            cin >> option;

        } while (option < 1 || option > 3);


        switch (option) {
            case 1:
                playerWeapon.setUserWeapon(weapons::ROCK);          // switch statment to assign user weapon
                break;
            case 2:
                playerWeapon.setUserWeapon(weapons::PAPER);
                break;
            case 3:
                playerWeapon.setUserWeapon(weapons::SCISSOR);
                break;
            default:
                break;
        }
    }

};


#endif //RPSGAME_USER_H
