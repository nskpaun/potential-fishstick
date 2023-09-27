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
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Potential Fishstick";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t extensionCount = 0;

    // TODO enabledExtensionCount and ppEnabledExtensionNames

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

