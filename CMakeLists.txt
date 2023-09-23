cmake_minimum_required(VERSION 3.0)

project(potential-fishstick)

set(CMAKE_CXX_STANDARD 11)

add_executable(potential-fishstick main.cpp model/GameModel.cpp)

add_executable(PFTest test.cpp model/GameModel.cpp)

target_include_directories(potential-fishstick PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(PFTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME PFTest COMMAND PFTest)