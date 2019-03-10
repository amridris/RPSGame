//
// Created by Amer on 3/10/2019.
//

#ifndef RPSGAME_CHOOSEAI_H
#define RPSGAME_CHOOSEAI_H

#include "User.h"
#include "Computer.h"

class Computer;

//Base AI prototype class to choose the appropriate algorithm
class chooseAI{
public:

    //pure virtual function implemented by algorithm subclasses
    virtual void play(User &player, Computer &cpu) = 0;
    virtual void printMarkovMatrix() = 0;
    virtual void exportMarkovMatrix() = 0;

    //class destructor
    virtual ~chooseAI(){};
};


#endif //RPSGAME_CHOOSEAI_H
