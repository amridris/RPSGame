/*
 * Subject: CMPE 135            Professor Ron Mak
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */


#ifndef RPSGAME_RPSCONTROL_H
#define RPSGAME_RPSCONTROL_H


#include "Player.h"
#include "Stats.h"
#include "GameLogic.h"
#include <stdlib.h>
#include "MarkovAi.h"

class RPSControl {

public:
    bool startGame;

private:
    int numOfRounds;
    User user1;
    Computer cpu;
    Stats gameStats;
    GameLogic logic;
    MarkovAi AI;

public:
    RPSControl(): user1(), cpu(){ };

    // Game main logic
    void play(){
        showMenu();
        showRule();
        cin.ignore();
        selectRounds();
        int rounds = 1;
        while(rounds <= numOfRounds){
            cout<<"---------------------------Round "<<rounds<<" --------------------------------"<<endl;
            playTurns();
            logic.getRoundOutcome(user1, cpu);
            rounds++;
        }
        gameStats.printGameStats(user1, cpu, numOfRounds);
        gameStats.winner();
        endGameMessage();
        cout<<"----------------------------------------Matrix of Player Moves---------------------------"<<endl;
        AI.printMarkovTable();
    }
    int getRounds(){return numOfRounds;}

    // prints game rules
    void showRule(){
        cout<<endl<<"Before you start your game. Please review the game rules below:"<<endl;
        cout<<"1: Paper beats Rock"<<endl;
        cout<<"2: Rock beats Scissor"<<endl;
        cout<<"3: Scissor beats Paper"<<endl;
        cout<<"Press Enter to start the game..."<<endl;
    }

    void setRounds(int rounds){
        numOfRounds = rounds;
    }


    // function to read user and computer weapons
    void playTurns(){

        user1.playTurn();
        AI.readPlayerMove(user1);
        AI.updateMatrix();
        if(AI.getPrevPlayerMove() == weapons::UNKNOWN) {
            //random choice
            cpu.playTurn();
        }
        else{
            // Intelligent computer choice
            cpu.playerWeapon.setUserWeapon(AI.chooseWeapon());
        }
        AI.setPlayerPrevChoice();
    }

    //prints menu to user
    void showMenu(){
        user1.setUsername();
        cout<<endl<<"Hello, "<<user1.getUsername()<<". Welcome to the RPS Game."<<endl;
    }

    void selectRounds(){
        cout<<"Please enter the number of rounds you want to play"<<endl;
        cin>>this->numOfRounds;
    }

    void endGameMessage(){
        cout<<endl<<"Thank you "<<this->user1.getUsername()<<" for playing the game. GoodBye!!"<<endl;
    }
};

#endif //RPSGAME_RPSCONTROL_H
