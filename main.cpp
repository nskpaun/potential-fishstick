#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <cstdlib>
#include <cstdint>
#include <stdexcept>
#include <iostream>

#include "app/PFApplication.h"
#include "app/PFWindowManager.h"

class MainWindowManager : public PFWindowManager {
public:
    GLFWwindow* window;
    MainWindowManager(GLFWwindow* w) : window(w) {}
    const char** getExtensions(uint32_t *extensionCount) override {
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(extensionCount);
        return glfwExtensions;
    }

    bool windowShouldClose() override {
        return glfwWindowShouldClose(window);
    }

    void pollEvents() override {
        glfwPollEvents();
    }

    void destroy() override {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(PF_APP_WINDOW_WIDTH, PF_APP_WINDOW_WIDTH, "Vulkan window", nullptr, nullptr);
    MainWindowManager* windowManager = new MainWindowManager(window);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    PFApplication app;

    try {
        app.run(windowManager);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
