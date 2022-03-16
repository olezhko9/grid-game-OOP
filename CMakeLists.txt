cmake_minimum_required(VERSION 3.21)
project(game)

set(CMAKE_CXX_STANDARD 17)

add_executable(game main.cpp board.cpp board.h cell.cpp cell.h game_object/GameObject.cpp game_object/GameObject.h game_object/player.cpp game_object/player.h utils/random.cpp utils/random.h Scene.cpp Scene.h)
