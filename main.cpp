
/*
 * Subject: CMPE 135            Professor Ron Mak
 * Assignment 3: Command Line RPS Game
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */

#include <iostream>
#include "RPSControl.h"
#include <unistd.h>



int main(int argc, char** argv) {

    bool hard_diffculty = false; // false for randomized game and true for machine learning game. Default => randomized
    int opt = 0;

    // parse the command line arguments
    while((opt = getopt(argc, argv, "rm")) != -1){
        switch(opt){
            case 'r': hard_diffculty = false; break;
            case 'm': hard_diffculty = true; break;
        }
    }
    RPSControl game(hard_diffculty);
    game.play();




    return 0;
}
