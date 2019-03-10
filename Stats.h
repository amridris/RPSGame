/*
 * Subject: CMPE 135            Professor Ron Mak
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */

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

    // player stats
    void printPlayerStats(User userPlayer, int rounds){
        userWinPercentage = ((float)userPlayer.getWins()/(float)rounds) * 100;
        userLossPercentage = ((float)userPlayer.getLosses()/(float)rounds) * 100;
        cout<<endl<<"--------------------------- Player Stats ---------------------------"<<endl;
        cout<<userPlayer.getUsername()<<" Win Percentage: "<<userWinPercentage<<"%"<<endl;
        cout<<userPlayer.getUsername()<<" Loss Percentage: "<<userLossPercentage<<"%"<<endl;
    }

    // computer stats
    void printComputerStats(Computer player, int rounds){
        computerWinPercentage = ((float)player.getWins()/(float)rounds) * 100;
        computerLossPercentage = ((float)player.getLosses()/(float)rounds) * 100;
        cout<<endl<<"--------------------------- Computer Status ---------------------------"<<endl;
        cout<<"CPU Win Percentage: "<<computerWinPercentage<<"%"<<endl;
        cout<<"CPU Loss Percentage: "<<computerLossPercentage<<"%"<<endl;
    }


    void printGameStats(User userPlayer, Computer computerPlayer, int rounds){
        cout<<"--------------------------- Player Stats ---------------------------"<<endl;

        //Calculation of game wins and losses percentage
        userWinPercentage = ((float)userPlayer.getWins()/(float)rounds) * 100;
        userLossPercentage = ((float)userPlayer.getLosses()/(float)rounds) * 100;
        computerWinPercentage = ((float)computerPlayer.getWins()/(float)rounds) * 100;
        computerLossPercentage = ((float)computerPlayer.getLosses()/(float)rounds) * 100;

        // Print game stats
        cout<<"Total Rounds Played: "<<rounds<<endl<<endl;
        cout<<userPlayer.getUsername()<<" Stats: "<<endl;
        cout<<"Rounds Won: "<<userPlayer.getWins()<<"\tWins Percentage: "<<userWinPercentage<<"%"<<endl;
        cout<<"Rounds Lost: "<<userPlayer.getLosses()<<"\t Losses Percentage: "<<userLossPercentage<<"%"<<endl;
        cout<<"Rounds Tied: "<<userPlayer.getTies()<<endl;
    }

    void winner(){

        cout<<endl<<"--------------------------- GAME WINNER ----------------------------"<<endl;
        if(userWinPercentage > computerWinPercentage){
            cout<<"You Won!!!!"<<endl<<endl;
        }
        else if(userWinPercentage == computerWinPercentage){
            cout<<"The game is Tied"<<endl<<endl;
        }
        else{
            cout<<"CPU won the game"<<endl<<endl;
        }
    }

};


#endif //RPSGAME_STATS_H
