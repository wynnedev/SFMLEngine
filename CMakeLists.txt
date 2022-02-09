cmake_minimum_required(VERSION 3.16)
project(SFML_Engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SFML_Engine
        managers/assetmanager.cpp
        managers/assetmanager.hpp
        definitions.hpp
        game.cpp
        game.hpp
        managers/inputmanager.cpp
        managers/inputmanager.hpp
        main.cpp
        states/splashstate.cpp
        states/splashstate.hpp
        states/state.cpp
        states/state.hpp
        states/statemachine.cpp
        states/statemachine.hpp utils/logger.cpp utils/logger.hpp states/exitstate.cpp states/exitstate.hpp states/mainmenustate.cpp states/mainmenustate.hpp UI_Elements/button.cpp UI_Elements/button.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(c:/Libraries/SFML-2.5.1/include)
target_link_libraries(SFML_Engine sfml-window sfml-system sfml-audio sfml-network sfml-graphics)