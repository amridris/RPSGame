//
// Created by Amer on 3/8/2019.
//

#ifndef RPSGAME_MARKOVAI_H
#define RPSGAME_MARKOVAI_H

#include<vector>
#include "Weapons.h"
#include "Player.h"
#include <map>

class MarkovAi{
    using matrix = vector<vector<long long>>;
private:
    matrix marcov_mat;
    weapons prevPlayerChoice;
    weapons currentPlayerChoice;
    map<weapons,long long> weaponInt;

public:
    MarkovAi(){

        //set the size of the matrix
        marcov_mat.resize(3, vector<long long>(3));


        //set the table entries to be all 0
        for(auto row = marcov_mat.begin(); row != marcov_mat.end(); row++){
            for(auto col = row->begin(); col != row->end(); col++){
                *col = 0;
            }
        }

        //set weapons value to unknown
        prevPlayerChoice = currentPlayerChoice = weapons::UNKNOWN;

        // initialize the map variable
        weaponInt.insert(make_pair(weapons::ROCK, 0));
        weaponInt.insert(make_pair(weapons::PAPER, 1));
        weaponInt.insert(make_pair(weapons::SCISSOR, 2));

    }


    // for debugging purpose!
    void printMarkovTable(){
        for(auto row = marcov_mat.begin(); row != marcov_mat.end(); row++){
            for(auto col = row->begin(); col != row->end(); col++){
                cout<<*col;
                cout<<"\t";
            }
            cout<<endl;
        }
    }


    // read in player weapon choice
    void readPlayerMove(User player){
        currentPlayerChoice = player.getUserWeapon();
    }

    //Once the new player choice is made. Set the previous player choice
    void setPlayerPrevChoice(){
        prevPlayerChoice = currentPlayerChoice;
    }

    //Returns previous player choice
    weapons getPrevPlayerMove(){
        return prevPlayerChoice;
    }

    /*
     * Update the matrix entires for computer to make an intelligent plays
     * The structure of the table:
     *          ROCK    PAPER   SCISSOR
     * ROCK
     * PAPER
     * SCISSOR
     *
     * increment the values depending on the user prev and current play choice!!
     */
    void updateMatrix(){
        if(prevPlayerChoice == weapons::UNKNOWN){
            return;
        }
        else if(currentPlayerChoice == weapons::UNKNOWN){
            return;
        }
        else{
            marcov_mat[weaponInt[prevPlayerChoice]][weaponInt[currentPlayerChoice]]++;
        }

    }

    /*
     * parameter: void
     *
     * chooseWeapon: for a current user weapon choice it traverse the table row and returns the highest value index
     * as a weapon choice for the computer to chose (Markov 2 set probability)
     *
     * returns:  an intelligent computer weapon choice
     */

    weapons chooseWeapon(){
        int highestValueIndex = 0;
        long long highestValue = 0;
        weapons choice;

        switch(currentPlayerChoice){
            case weapons::ROCK: {
                for(int i = 0; i<marcov_mat[0].size(); i++){
                    if(highestValue < marcov_mat[0][i]){
                        highestValueIndex = i;
                        highestValue = marcov_mat[0][i];
                    }
                }
            }break;

            case weapons::PAPER:{
                for(int i = 0; i<marcov_mat[1].size(); i++){
                    if(highestValue < marcov_mat[1][i]){
                        highestValueIndex = i;
                        highestValue = marcov_mat[1][i];
                    }
                }
            }break;

            case weapons::SCISSOR:{
                for(int i = 0; i<marcov_mat[2].size(); i++){
                    if(highestValue < marcov_mat[2][i]){
                        highestValueIndex = i;
                        highestValue = marcov_mat[2][i];
                    }
                }
            } break;
        }

        switch(highestValueIndex){
            case 1: choice = weapons::ROCK; break;
            case 2: choice = weapons::PAPER; break;
            case 3: choice = weapons ::SCISSOR; break;
        }

        return choice;
    }

};
#endif //RPSGAME_MARKOVAI_H
