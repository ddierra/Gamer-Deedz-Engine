cmake_minimum_required(VERSION 3.10)
project(GameEngine2025)

set(CMAKE_CXX_STANDARD 17)

# Path to SFML installed via MSYS2 MinGW64
set(SFML_DIR "/mingw64/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

add_executable(GameEngine 
    src/main.cpp
    src/InputManager.cpp
    src/EntityManager.cpp)

target_link_libraries(GameEngine sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
