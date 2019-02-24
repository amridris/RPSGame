//
// Created by Amer on 2/22/2019.
//

#ifndef RPSGAME_RPSCONTROL_H
#define RPSGAME_RPSCONTROL_H


#include "Player.h"
#include "Stats.h"
#include "GameLogic.h"

class RPSControl {

public:
    bool startGame;

private:
    int numOfRounds;
    User user1;
    Computer cpu;
    Stats gameStats;
    GameLogic logic;


public:
    RPSControl(): user1(), cpu(){ };

    void play(){
        showMenu();
        showRule();
        system("Pause");
        selectRounds();
        int rounds = 1;
        while(rounds <= numOfRounds){
            cout<<"---------------------------Round "<<rounds<<" --------------------------------"<<endl;
            playTurns();
            logic.getRoundOutcome(user1, cpu);
            rounds++;
        }
        gameStats.printPlayerStats(user1, numOfRounds);
        gameStats.winner();
        endGameMessage();
    }
    int getRounds(){return numOfRounds;}

    void showRule(){
        cout<<"Before you start your game. Please review the game rule and press Enter to start the game..."<<endl<<endl;
        cout<<"1: Paper beats Rock"<<endl;
        cout<<"2: Rock beats Scissor"<<endl;
        cout<<"3: Scissor beats Paper"<<endl;
    }

    void setRounds(int rounds){
        numOfRounds = rounds;
    }

    void playTurns(){

        user1.playTurn();
        cpu.playTurn();
    }

    void showMenu(){
        cout<<"welcome to the best RPS Game"<<endl;
        user1.setUsername();
        cout<<"Hello, "<<user1.getUsername()<<endl;
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
