cmake_minimum_required(VERSION 3.26)
project(ask_fm)

set(CMAKE_CXX_STANDARD 20)

add_executable(ask_fm main.cpp
        askFmSys.cpp
        askFmSys.h
        user.cpp
        user.h
        question.cpp
        question.h)
