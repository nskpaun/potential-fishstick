#ifndef PFAPPLICATION_H
#define PFAPPLICATION_H

#include <cstdlib>
#include <cstdint>

#include <vulkan/vulkan.h>

#include "PFWindowManager.h"

const uint32_t PF_APP_WINDOW_WIDTH = 800;
const uint32_t PF_APP_WINDOW_HEIGHT = 600;

class PFApplication {
    public:
        void run(PFWindowManager *windowManager);

    private:
        VkInstance instance;
        void initVulkan(PFWindowManager *windowManager);
        void mainLoop(PFWindowManager *windowManager);
        void cleanup(PFWindowManager *windowManager);
};

#endif