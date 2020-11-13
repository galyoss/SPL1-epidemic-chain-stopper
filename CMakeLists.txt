
cmake_minimum_required(VERSION 3.17)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment1
        src/Session.cpp
        src/Graph.cpp
        src/Agent.cpp
        src/Tree.cpp
        src/main.cpp

        Include/Agent.h
        Include/Session.h
        Include/Graph.h
        Include/Tree.h
        Include/json.hpp)