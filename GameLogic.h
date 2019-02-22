//
// Created by Amer on 2/22/2019.
//

#ifndef RPSGAME_GAMELOGIC_H
#define RPSGAME_GAMELOGIC_H

#include "RPSControl.h"


class GameLogic {

public:
    void getRoundOutcome(User &user, Computer &computer) {

        if (user.playerWeapon.getWeapon() == weapons::ROCK){
            if(computer.playerWeapon.getWeapon() == weapons::ROCK){
                user.setTies();
                computer.setTies();
            }
            else if(computer.playerWeapon.getWeapon() == weapons::PAPER){
                user.setLosses();
                computer.setWins();
            }
            else{
                user.setWins();
                computer.setLosses();
            }
        }


        else if(user.playerWeapon.getWeapon() == weapons::PAPER){
            if(computer.playerWeapon.getWeapon() == weapons::PAPER){
                user.setTies();
                computer.setTies();
            }
            else if(computer.playerWeapon.getWeapon() == weapons::SCISSOR){
                user.setLosses();
                computer.setWins();
            }
            else{
                user.setWins();
                computer.setLosses();
            }
        }

        else if(user.playerWeapon.getWeapon() == weapons::SCISSOR){
            if(computer.playerWeapon.getWeapon() == weapons::SCISSOR){
                user.setTies();
                computer.setTies();
            }
            else if(computer.playerWeapon.getWeapon() == weapons::ROCK){
                user.setLosses();
                computer.setWins();
            }
            else{
                user.setWins();
                computer.setLosses();
            }
        }
    }

};

#endif //RPSGAME_GAMELOGIC_H
