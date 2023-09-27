find_package( Vulkan REQUIRED )
include_directories( ${VULKAN_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glm )

add_library(App STATIC PFApplication.cpp GameModel.cpp)

target_link_libraries(App Vulkan::Vulkan glm)
target_include_directories(App PUBLIC ./)
