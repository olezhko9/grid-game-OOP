cmake_minimum_required(VERSION 3.21)
project(game)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(game main.cpp board.cpp board.h Tile.cpp Tile.h game_object/GameObject.cpp game_object/GameObject.h game_object/player.cpp game_object/player.h utils/random.cpp utils/random.h Engine.cpp Engine.h game_object/GameObjectsManager.cpp game_object/GameObjectsManager.h utils/Vector2d.cpp utils/Vector2d.h definitions.h)

target_link_libraries(game sfml-graphics)
