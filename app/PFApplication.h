#ifndef PFAPPLICATION_H
#define PFAPPLICATION_H

#include <cstdlib>
#include <cstdint>

#include <vulkan/vulkan.h>

const uint32_t PF_APP_WINDOW_WIDTH = 800;
const uint32_t PF_APP_WINDOW_HEIGHT = 600;

class PFApplication {
    public:
        void run();

    private:
        VkInstance instance;
        void initVulkan();
        void mainLoop();
        void cleanup();
};

#endif