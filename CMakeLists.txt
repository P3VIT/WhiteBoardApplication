cmake_minimum_required(VERSION 3.10)
project(ChalkBoardApp)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(whiteboard ${SOURCES})

target_link_libraries(whiteboard sfml-graphics sfml-window sfml-system)
