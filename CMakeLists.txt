cmake_minimum_required(VERSION 3.5)
project(test)

# Plug In Library
add_library(spell SHARED spell.cpp)

# Executable that consumes the plug in provided function
add_executable(test test.cpp)
