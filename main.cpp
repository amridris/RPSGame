
/*
 * Subject: CMPE 135            Professor Ron Mak
 * Assignment 3: Command Line RPS Game
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */

#include <iostream>
#include "RPSControl.h"
#include "MarkovAi.h"

enum class color{
    red = 0,
    green = 1,
    blue = 2
};
int main() {

    RPSControl game;
    game.play();




    return 0;
}
