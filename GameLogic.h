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
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": TIE"<<endl;
            }
            else if(computer.playerWeapon.getWeapon() == weapons::PAPER){
                user.setLosses();
                computer.setWins();
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": PAPER WINS"<<endl;

            }
            else{
                user.setWins();
                computer.setLosses();
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": ROCK WINS"<<endl;

            }
        }


        else if(user.playerWeapon.getWeapon() == weapons::PAPER){
            if(computer.playerWeapon.getWeapon() == weapons::PAPER){
                user.setTies();
                computer.setTies();
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": TIE"<<endl;

            }
            else if(computer.playerWeapon.getWeapon() == weapons::SCISSOR){
                user.setLosses();
                computer.setWins();
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": SCISSOR WINS"<<endl;

            }
            else{
                user.setWins();
                computer.setLosses();
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": PAPER WINS"<<endl;

            }
        }

        else if(user.playerWeapon.getWeapon() == weapons::SCISSOR){
            if(computer.playerWeapon.getWeapon() == weapons::SCISSOR){
                user.setTies();
                computer.setTies();
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": TIE"<<endl;

            }
            else if(computer.playerWeapon.getWeapon() == weapons::ROCK){
                user.setLosses();
                computer.setWins();
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": ROCK WINS"<<endl;

            }
            else{
                user.setWins();
                computer.setLosses();
                cout<< user.getUsername()<<": "<<user.playerWeapon.to_string()<<" vs "<<"CPU "<<computer.playerWeapon.to_string()<<": SCISSORS WINS"<<endl;

            }
        }
    }

};

#endif //RPSGAME_GAMELOGIC_H
