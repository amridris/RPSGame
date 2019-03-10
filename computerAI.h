/*
 * Subject: CMPE 135            Professor Ron Mak
 * contributors: Aamer Idris, Jacob Balster-Gee, Dan Hoang, Andre Voloshin
 */


#ifndef RPSGAME_MARKOVAI_H
#define RPSGAME_MARKOVAI_H

#include<vector>
#include "Weapons.h"
#include "Player.h"
#include <map>
#include <fstream>
#include <sstream>

class computerAI{
    using matrix = vector<vector<long long>>;
private:
    matrix marcov_mat;
    weapons last_player_choice;
    weapons before_last_player_choice;
    map<weapons,long long> weaponInt;
    bool hard_diffculty = false;

public:
    computerAI(){

        //set the size of the matrix
        marcov_mat.resize(3, vector<long long>(3));

        //open matrix.csv file
        ifstream read_matrix("matrix.csv");

        // if file exits read its content
        if(read_matrix.is_open()){
            readMatrixTable(read_matrix);

        }
        // create a new file
        else {
            createNewMatrix();
        }

        //set weapons value to unknown
        last_player_choice = before_last_player_choice = weapons::UNKNOWN;

        // initialize the map variable (used to increment the table)
        weaponInt.insert(make_pair(weapons::ROCK, 0));
        weaponInt.insert(make_pair(weapons::PAPER, 1));
        weaponInt.insert(make_pair(weapons::SCISSOR, 2));

    }

    //If no file found create a new matrix (initialized to zeros)
    void createNewMatrix() {//set the table entries to be all 0
        for (auto row = marcov_mat.begin(); row != marcov_mat.end(); row++) {
                for (auto col = row->begin(); col != row->end(); col++) {
                    *col = 0;
                }
            }
    }

    // read previously created matrix file
    void readMatrixTable(ifstream &read_matrix)  {
        string matrix_line;
        char delimiter;
        int temporary_int;
        int row = 0, col = 0;

        while(getline(read_matrix, matrix_line)){
                stringstream iss(matrix_line);
                while(iss>>temporary_int){
                    marcov_mat[row][col] = temporary_int;
                    col++;
                }
                row++;
                col = 0;
            }
    }


    // for debugging purpose!
    void printMarkovTable(){
        int index = 0;
        bool firstTimeRock = true;
        bool firstTimePaper = true;
        bool firstTimeScissor= true;
        cout<<"\tRock\tPaper\tScissor"<<endl;

        for(auto row = marcov_mat.begin(); row != marcov_mat.end(); row++){
            if(index == 0 && firstTimeRock == true){
                cout<<"Rock\t";
                firstTimeRock = false;
            }
            else if(index == 1 && firstTimePaper == true){
                cout<<"Paper\t";
                firstTimePaper = false;
            }
            else if(index == 2 && firstTimeScissor == true){
                cout<<"Scissor\t";
                firstTimeScissor = false;
            }
            for(auto col = row->begin(); col != row->end(); col++){
                cout<<*col;
                cout<<"\t";
            }
            cout<<endl;
            index++;
        }
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

            marcov_mat[weaponInt[before_last_player_choice]][weaponInt[last_player_choice]]++;
    }

    /*
     * parameter: void
     *
     * chooseWeapon: for a current user weapon choice it traverse the table row and returns the highest value index
     * as a weapon choice for the computer to chose (Markov 2 state chain)
     *
     * returns:  an intelligent computer weapon choice
     */

    weapons chooseWeapon(){
        int highestValueIndex = 0;
        long long highestValue = 0;
        weapons choice;

        switch(last_player_choice){
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
            case 0: choice = weapons::PAPER; break;
            case 1: choice = weapons::SCISSOR; break;
            case 2: choice = weapons ::ROCK; break;
        }

        return choice;
    }


    /*
     * Set the game diffculty level
     * Parameter: bool
     * return: void
     */

    void setGameDifficulty(bool game_diffuclty){
        this->hard_diffculty = game_diffuclty;
    }


    /*
     * Game play function which checks the diffculty level and play accordingly.
     * In randomized mode: The computer plays randomly
     * In Machine Learning AI mode: The computer reads the user past play and create a matrix. The matrix will be used
     * to find pattern to play.
     */

    void play(User &player, Computer &cpu){
        if(hard_diffculty == false){
            randomizedPlay(cpu);
        }
        else{
            machineLearnedPlay(player, cpu);
        }
    }

    /*
     * Function to play randomized game (Easy setting)
     * Parameter: cpu
     * returns: void
     */
    void randomizedPlay(Computer &cpu){
        cpu.playTurn();
    }


    /*
     * Function to play intelligently using learned patter from matrix (Markov Chain).
     * parameter: user and cpu players
     * returns: void
     */
    void machineLearnedPlay(User &player, Computer &cpu){

        // Read past player choice and computer play randomly
        if(last_player_choice == weapons::UNKNOWN){
            last_player_choice = player.getUserWeapon();
            cpu.playTurn();
        }

        // sets the previous play for (2 state markov reading)
        else if(before_last_player_choice == weapons::UNKNOWN){
            before_last_player_choice = last_player_choice;
            last_player_choice = player.getUserWeapon();
            cpu.playTurn();
        }
        else{

            updateMatrix();

            // assign the old user throw to before last
            before_last_player_choice = last_player_choice;

            // Play the game by checking the matrix
            cpu.playerWeapon.setUserWeapon(chooseWeapon());

            // update the last play after the end of the round
            last_player_choice = player.getUserWeapon();
        }
    }


    /*
     * function to export AI matrix to file to enhance computer choices and for reuse.
     * parameter: void
     * returns: void
     */
    void exportMatrix(){
        ofstream exportFile;

        exportFile.open("matrix.csv");
        for(auto row = marcov_mat.begin(); row != marcov_mat.end(); row++){
            for(auto col = row->begin(); col != row->end(); col++){
                exportFile<<*col;
                exportFile<<"\t";
            }

            exportFile<<endl;
        }

        exportFile.close();

    }



};
#endif //RPSGAME_MARKOVAI_H
