cmake_minimum_required(VERSION 3.6)
project(clion)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES test.cpp complex.cpp complex.h polynom.cpp TempVec.h)
set(SOURCE_FILES main.cpp complex.cpp complex.h polynom.cpp TempVec.h)
add_executable(clion ${SOURCE_FILES})