cmake_minimum_required(VERSION 3.10)
project(OurProject)
add_executable(OurProject main.cpp factorials.cpp factorials.h combinations.cpp combinations.h countGoodStrings.cpp countGoodStrings.h)


target_link_libraries(OurProject gtest boost)