find_package( Vulkan REQUIRED )
include_directories( ${VULKAN_INCLUDE_DIRS} )

add_library(App STATIC PFApplication.cpp GameModel.cpp)

target_link_libraries(App Vulkan::Vulkan)
target_include_directories(App PUBLIC ./)
