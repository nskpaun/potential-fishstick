#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <stdexcept>
#include <iostream>

#include "app/PFApplication.h"
#include "app/PFWindowManager.h"

class MainWindowManager : public PFWindowManager {
public:
    int getExtensions() override {
        return 0;
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

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    PFApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}
