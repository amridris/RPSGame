cmake_minimum_required(VERSION 3.13)
project(RPSGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(RPSGame main.cpp Player.h User.h Weapons.h Stats.h GameLogic.h Computer.h RPSControl.h)