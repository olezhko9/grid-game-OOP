cmake_minimum_required(VERSION 3.21)
project(game)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(game main.cpp Board.cpp Board.h Tile.cpp Tile.h game_object/GameObject.cpp game_object/GameObject.h game_object/player/Player.cpp game_object/player/Player.h utils/Random.cpp utils/Random.h Engine.cpp Engine.h GameObjectsManager.cpp GameObjectsManager.h utils/Vector2d.cpp utils/Vector2d.h definitions.h ResourcesManager.cpp ResourcesManager.h game_object/items/Item.cpp game_object/items/Item.h)

target_link_libraries(game sfml-graphics)
