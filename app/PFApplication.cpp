#include "PFApplication.h"

#include <vulkan/vulkan.h>

#include <iostream>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

void PFApplication::run() {
    initVulkan();
    mainLoop();
    cleanup();
}

void PFApplication::initVulkan() {
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported\n";
}

void PFApplication::mainLoop() {
    std::cout << "Main Loop" << std::endl;
    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;
}

void PFApplication::cleanup() {
    std::cout << "cleanup" << std::endl;
}

