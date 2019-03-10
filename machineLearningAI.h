//
// Created by Amer on 3/10/2019.
//

#ifndef RPSGAME_MACHINELEARNINGAI_H
#define RPSGAME_MACHINELEARNINGAI_H

#include "chooseAI.h"
#include "User.h"
#include "Computer.h"
#include "MarkovAlgorithm.h"

class machineLearningAI: public chooseAI{
public:
    //MarcoveAlgorithm variable will keep track of the user plays
    MarkovAlgorithm AI;


    void play(User &player, Computer &cpu){
        AI.play(player, cpu);
    }

    void printMarkovMatrix(){
        AI.printMarkovTable();
    }

    void exportMarkovMatrix(){
        AI.exportMatrix();
    }


};


#endif //RPSGAME_MACHINELEARNINGAI_H
