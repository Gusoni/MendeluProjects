cmake_minimum_required(VERSION 3.25)
project(BattleShipGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(BattleShipGame main.cpp GameEngine.cpp Loader.cpp GameLogic.cpp)
