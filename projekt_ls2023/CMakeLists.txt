cmake_minimum_required(VERSION 3.23)
project(projekt_ls2023)

set(CMAKE_CXX_STANDARD 14)

add_executable(projekt_ls2023 main.cpp Map.cpp Map.h Hero.cpp Hero.h Enemy.cpp Enemy.h Menu.cpp World.cpp World.h Inventory.cpp Item.cpp)
