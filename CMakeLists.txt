
cmake_minimum_required(VERSION 3.17)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment1
        Session.cpp
        Graph.cpp
        Agent.cpp
        Tree.cpp
        main.cpp
        Agent.h
        Session.h
        Graph.h
        Tree.h
        json.hpp)