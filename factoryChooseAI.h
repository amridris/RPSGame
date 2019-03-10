//
// Created by Amer on 3/10/2019.
//

#ifndef RPSGAME_FACTORYCHOOSEAI_H
#define RPSGAME_FACTORYCHOOSEAI_H

#include <memory>
#include "randomAI.h"
#include "machineLearningAI.h"

class factoryChooseAI{
public:
    static chooseAI* choose_AI_algorithm(bool difficulty){

        if (difficulty == false) {
            return new randomAI;
        } else {
            return new machineLearningAI;
        }
    }
};


#endif //RPSGAME_FACTORYCHOOSEAI_H
