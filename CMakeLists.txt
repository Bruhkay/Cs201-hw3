cmake_minimum_required(VERSION 3.29)
project(Cs201_hw3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cs201_hw3 main.cpp
        BilkentBeats.h
        BilkentBeats.cpp
        User.h
        User.cpp
        Playlist.h
        Playlist.cpp
        Song.h
        Song.cpp
        main.cpp
        LinkedList.cpp
        LinkedList.h
)
