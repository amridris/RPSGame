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
#include "factoryChooseAI.h"
class RPSControl {

public:
    bool startGame;

private:
    int num_of_rounds;
    User user;
    Computer cpu;
    Stats gameStats;
    GameLogic logic;
    factoryChooseAI createAI;
    bool game_difficulty;

public:
    RPSControl(bool difficulty): user(), cpu(), game_difficulty(difficulty){ };

    // Game main logic
    void play(){
        showMenu();
        auto AI = createAI.choose_AI_algorithm(game_difficulty);
        showRule();
        cin.ignore();
        selectRounds();
        int rounds = 1;
        while(rounds <= num_of_rounds){
            cout<<"\n---------------------------Round "<<rounds<<" --------------------------------"<<endl;
            playTurns(AI);
            logic.getRoundOutcome(user, cpu);
            rounds++;
        }
        cout<<endl;
        gameStats.printGameStats(user, cpu, num_of_rounds);
        gameStats.winner();
        
        //prints the matrix only if the game is not random
        if (game_difficulty)
        {
            cout<<"---------------------- Matrix of Player Moves ----------------------"<<endl;
            AI->printMarkovMatrix();
            endGameMessage();
            AI->exportMarkovMatrix();
        }

    }


    int getRounds(){return num_of_rounds;}

    // prints game rules
    void showRule(){
        cout<<endl<<"Before you start your game. Please review the game rules below:"<<endl;
        cout<<"1: Paper beats Rock"<<endl;
        cout<<"2: Rock beats Scissor"<<endl;
        cout<<"3: Scissor beats Paper"<<endl;
        cout<<endl<<"Press Enter to start the game..."<<endl;
    }

    void setRounds(int rounds){
        num_of_rounds = rounds;
    }


    // function to read user and computer weapons
    void playTurns(chooseAI *AI){

        user.playTurn();
        AI->play(user, cpu);
    }

    //prints menu to user
    void showMenu(){
        user.setUsername();
        cout<<endl<<"Hello, "<<user.getUsername()<<". Welcome to the RPS Game."<<endl;
    }

    void selectRounds(){
        cout<<"Please enter the number of rounds you want to play"<<endl;
        cin>>this->num_of_rounds;
    }

    void endGameMessage(){
        cout<<endl<<"Thank you "<<this->user.getUsername()<<" for playing the game. GoodBye!!"<<endl;
    }
};

#endif //RPSGAME_RPSCONTROL_H
