cmake_minimum_required(VERSION 3.0)

project(potential-fishstick)

set(CMAKE_CXX_STANDARD 17)

find_package( OpenGL REQUIRED )
find_package( Vulkan REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )
include_directories( ${VULKAN_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( lib/glfw )
add_subdirectory( app )

add_executable(potential-fishstick main.cpp)

target_link_libraries(potential-fishstick ${OPENGL_LIBRARIES} glfw Vulkan::Vulkan App)

add_executable(PFTest test.cpp)

target_include_directories(potential-fishstick PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(PFTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} App)

add_test(NAME PFTest COMMAND PFTest)