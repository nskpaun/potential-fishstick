#ifndef PFAPPLICATION_H
#define PFAPPLICATION_H

#include <cstdlib>
#include <cstdint>
#include <vector>

#include <vulkan/vulkan.h>

#include "PFWindowManager.h"

// DEBUG MODE IS ENABLED!!! Uncomment the following line to disable
// #define NDEBUG

const uint32_t PF_APP_WINDOW_WIDTH = 800;
const uint32_t PF_APP_WINDOW_HEIGHT = 600;

const std::vector<const char *> validationLayers = {
    "VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class PFApplication
{
public:
    void run(PFWindowManager *windowManager);

private:
    VkInstance instance;
    VkDevice device;
    VkQueue graphicsQueue;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    void initVulkan(PFWindowManager *windowManager);
    void createInstance(PFWindowManager *windowManager);
    void mainLoop(PFWindowManager *windowManager);
    void cleanup(PFWindowManager *windowManager);
    void pickPhysicalDevice();
    void createLogicalDevice();
};

#endif