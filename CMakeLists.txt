cmake_minimum_required(VERSION 3.0)

project(potential-fishstick)

set(CMAKE_CXX_STANDARD 11)

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( lib/glfw-3.3.8 )

add_executable(potential-fishstick main.cpp model/GameModel.cpp)

target_link_libraries(potential-fishstick glfw )

add_executable(PFTest test.cpp model/GameModel.cpp)

target_include_directories(potential-fishstick PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(PFTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME PFTest COMMAND PFTest)