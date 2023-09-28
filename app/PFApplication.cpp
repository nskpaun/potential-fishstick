#include "PFApplication.h"

#include <vulkan/vulkan.h>

#include <iostream>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

void PFApplication::run(PFWindowManager *windowManager) {
    initVulkan(windowManager);
    mainLoop(windowManager);
    cleanup(windowManager);
}

void PFApplication::initVulkan(PFWindowManager *windowManager) {
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
    const char ** extensions;
    extensions = windowManager->getExtensions(&extensionCount);

    createInfo.enabledExtensionCount = extensionCount;
    createInfo.ppEnabledExtensionNames = extensions;

    createInfo.enabledLayerCount = 0;

    if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create vulkan instance");
    }

    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported\n";
}

void PFApplication::mainLoop(PFWindowManager *windowManager) {
    std::cout << "Main Loop" << std::endl;
    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;


    /* Loop until the user closes the window */
    while (!windowManager->windowShouldClose())
    {
        /* Poll for and process events */
        windowManager->pollEvents();
    }
}

void PFApplication::cleanup(PFWindowManager *windowManager) {
    std::cout << "cleanup" << std::endl;
    vkDestroyInstance(instance, nullptr);
    windowManager->destroy();
}

