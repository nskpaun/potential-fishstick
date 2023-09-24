// #define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>

#include "model/GameModel.h"
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

int main() {
    std::cout << "Hello PF GAME!" << std::endl;
    auto model = new GameModel();
    model->nextFrame();

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    // glfwMakeContextCurrent(window);
    // glClearColor( 0.4f, 0.3f, 0.4f, 0.0f );

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
