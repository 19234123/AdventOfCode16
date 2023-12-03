cmake_minimum_required(VERSION 3.26)
project(AdventOfCode16)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode16 main.cpp
        Navigator.cpp
        Navigator.h
        Keypad.cpp
        Keypad.h
        md5.cpp
        md5.h
        PasswordGenerator.cpp
        PasswordGenerator.h
        LetterList.cpp
        LetterList.h
)
