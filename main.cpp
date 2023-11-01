#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <cstdlib>
#include <cstdint>
#include <stdexcept>
#include <iostream>

#include <limits>
#include <algorithm>

#include "app/PFApplication.h"
#include "app/PFWindowManager.h"

class MainWindowManager : public PFWindowManager
{
public:
    GLFWwindow *window;
    MainWindowManager(GLFWwindow *w) : window(w) {}
    const char **getExtensions(uint32_t *extensionCount) override
    {
        const char **glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(extensionCount);
        return glfwExtensions;
    }

    bool windowShouldClose() override
    {
        return glfwWindowShouldClose(window);
    }

    void pollEvents() override
    {
        glfwPollEvents();
    }

    void destroy() override
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void createSurface(VkInstance instance, VkSurfaceKHR *surface)
    {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create window surface!");
        }
    }

    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &
                                    capabilities)
    {
        if (capabilities.currentExtent.width != (std::numeric_limits<uint32_t>::max)())
        {
            return capabilities.currentExtent;
        }
        else
        {
            int width, height;
            glfwGetFramebufferSize(window, &width, &height);

            VkExtent2D actualExtent = {
                static_cast<uint32_t>(width),
                static_cast<uint32_t>(height)};

            actualExtent.width = std::clamp(actualExtent.width,
                                            capabilities.minImageExtent.width,
                                            capabilities.maxImageExtent.width);
            actualExtent.height = std::clamp(actualExtent.height,
                                             capabilities.minImageExtent.height,
                                             capabilities.maxImageExtent.height);

            return actualExtent;
        }
    }
};

int main()
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(PF_APP_WINDOW_WIDTH, PF_APP_WINDOW_WIDTH, "Vulkan window", nullptr, nullptr);
    MainWindowManager *windowManager = new MainWindowManager(window);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    PFApplication app;

    try
    {
        app.run(windowManager);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
