cmake_minimum_required(VERSION 3.4)
project(Rational)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES rational.h)
add_executable(Rational ${SOURCE_FILES})