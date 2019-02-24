//
// Created by Amer on 2/22/2019.
//

#ifndef RPSGAME_STATS_H
#define RPSGAME_STATS_H

#include "RPSControl.h"
#include<iostream>
#include "Player.h"
#include "User.h"
#include "Computer.h"


using namespace std;

class Stats {
private:
    float userWinPercentage, userLossPercentage;
    float computerWinPercentage, computerLossPercentage;




public:
    Stats(): userWinPercentage(0.0), userLossPercentage(0.0), computerLossPercentage(0), computerWinPercentage(0){}

    void printPlayerStats(User userPlayer, int rounds){
        userWinPercentage = ((float)userPlayer.getWins()/(float)rounds) * 100;
        userLossPercentage = ((float)userPlayer.getLosses()/(float)rounds) * 100;
        cout<<endl<<"------------------------------- Player Status--------------------------------------"<<endl;
        cout<<userPlayer.getUsername()<<" Win Percentage: "<<userWinPercentage<<"%"<<endl;
        cout<<userPlayer.getUsername()<<" Loss Percentage: "<<userLossPercentage<<"%"<<endl;
    }

    void printComputerStats(Computer player, int rounds){
        computerWinPercentage = ((float)player.getWins()/(float)rounds) * 100;
        computerLossPercentage = ((float)player.getLosses()/(float)rounds) * 100;
        cout<<endl<<"------------------------------- Computer Status--------------------------------------"<<endl;
        cout<<"CPU Win Percentage: "<<computerWinPercentage<<"%"<<endl;
        cout<<"CPU Loss Percentage: "<<computerLossPercentage<<"%"<<endl;
    }


    void printGameStats(User userPlayer, Computer computerPlayer, int rounds){
        printPlayerStats(userPlayer, rounds);
        printComputerStats(computerPlayer, rounds);
        cout<<"Total Rounds Played: "<<rounds<<endl;
    }

    void winner(){

        cout<<endl<<"---------------------GAME WINNER-----------------------------"<<endl;
        if(userWinPercentage > computerWinPercentage){
            cout<<"You Won!!!!"<<endl;
        }
        else{
            cout<<"CPU Won!!!!"<<endl;
        }
    }

};


#endif //RPSGAME_STATS_H
