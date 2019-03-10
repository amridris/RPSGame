//
// Created by Amer on 3/10/2019.
//

#ifndef RPSGAME_RANDOMAI_H
#define RPSGAME_RANDOMAI_H

#include "chooseAI.h"
#include "User.h"
#include "Computer.h"


class randomAI: public chooseAI{

    //virtual function override for playing
    void play(User &player, Computer &cpu){
        cpu.playTurn();
    }


    void printMarkovMatrix(){
        // Do nothing since randomized function doesn't have a matrix
    }

    void exportMarkovMatrix(){
        // Do nothing since randomized function doesn't have a matrix
    }

};

#endif //RPSGAME_RANDOMAI_H
