#ifndef PFAPPLICATION_H
#define PFAPPLICATION_H

#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>

#include <vulkan/vulkan.h>

#include "PFWindowManager.h"

// DEBUG MODE IS ENABLED!!! Uncomment the following line to disable
// #define NDEBUG

const uint32_t PF_APP_WINDOW_WIDTH = 800;
const uint32_t PF_APP_WINDOW_HEIGHT = 600;
const uint32_t MAX_FRAMES_IN_FLIGHT = 2;

const std::vector<const char *> validationLayers = {
    "VK_LAYER_KHRONOS_validation"};

const std::vector<const char *> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete()
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
    void *pUserData)
{

    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
}

class PFApplication
{
public:
    void run(PFWindowManager *windowManager);

private:
    VkInstance instance;
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain;
    std::vector<VkImage> swapchainImages;
    std::vector<VkImageView> swapchainImageViews;
    VkFormat swapchainFormat;
    VkExtent2D swapchainExtent;
    VkPipelineLayout pipelineLayout;
    VkRenderPass renderPass;
    VkPipeline graphicsPipeline;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> mCommandBuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkDebugUtilsMessengerEXT debugMessenger;

    uint32_t currentFrame = 0;

    void initVulkan(PFWindowManager *windowManager);
    void createInstance(PFWindowManager *windowManager);
    void mainLoop(PFWindowManager *windowManager);
    void cleanup(PFWindowManager *windowManager);
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSwapChain(PFWindowManager *windowManager);
    void createSurface(PFWindowManager *windowManager);
    void createRenderPass();
    void createGraphicsPipeline();
    void createImageViews();
    void createFrameBuffer();
    void createCommandPool();
    void createVertexBuffer();
    void createCommandBuffer();
    void createSyncObjects();
    void setupDebugMessenger();
    void drawFrame();
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    bool isDeviceSuitable(const VkPhysicalDevice &device);
    QueueFamilyIndices findQueueFamilies(const VkPhysicalDevice &device);
    SwapChainSupportDetails querySwapChainSupportDetails(const VkPhysicalDevice &device);
    VkShaderModule createShaderModule(const std::vector<char> &code);
};

#endif