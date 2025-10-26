cmake_minimum_required(VERSION 3.29)
project(Proiect_POO)

set(CMAKE_CXX_STANDARD 26)

add_executable(Proiect_POO main.cpp
        Activity.h
        Transport.h
        Calendar.cpp
        Calendar.h
        Activity.cpp
        Transport.cpp
)
