//
// Created by Amer on 2/22/2019.
//

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

    std::string getUsername(){ return name; }

    void setUsername(){
        cout<<"Please enter your name?"<<endl;
        getline(cin, name);
    }

    void playTurn() {

        userPlay = true;
        int option = 0;

        do {

            playerWeapon.printWeaponList();
            cin >> option;

        } while (option < 1 && option > 3);


        switch (option) {
            case 1:
                playerWeapon.setUserWeapon(weapons::ROCK);
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
