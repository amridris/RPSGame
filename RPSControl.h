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

    void showMenu(){
        cout<<"welcome to the best RPS Game"<<endl<<endl;
        user1.setUsername();
        cout<<"Hello, "<<user1.getUsername()<<endl<<endl;
        cout<<"Please enter the number of rounds you want to play"<<endl<<endl;
        cin>>this->numOfRounds;
        cout<<"Before you start your game. Please review the game rule and press Enter to start the game"<<endl<<endl;
        showRule();
        system("Pause");
        int option = numOfRounds;
        while(option > 0){
            playGame();
            logic.getRoundOutcome(user1, cpu);
            option--;
        }
        gameStats.printPlayerStats(user1, numOfRounds);
        gameStats.printComputerStats(cpu, numOfRounds);
        gameStats.winner();
        cout<<"Thank you for playing!!!"<<endl;
    }
    int getRounds(){return numOfRounds;}

    void showRule(){
        cout<<"1: Paper beats Rock\nRock beats Scissor\nScissor beats Paper"<<endl;
    }

    void setRounds(int rounds){
        numOfRounds = rounds;
    }

    void playGame(){
        user1.playTurn();
        cpu.playTurn();
    }

};

#endif //RPSGAME_RPSCONTROL_H
