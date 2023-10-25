find_package( Vulkan REQUIRED )
include_directories( ${VULKAN_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 17)


add_subdirectory( glm )

add_library(App STATIC PFApplication.cpp GameModel.cpp)

target_link_libraries(App Vulkan::Vulkan glm)
target_include_directories(App PUBLIC ./)
