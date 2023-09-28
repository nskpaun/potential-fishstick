#ifndef PFWINDOWMANAGER_H
#define PFWINDOWMANAGER_H

#include <cstdlib>
#include <cstdint>

class PFWindowManager
{
public:
    virtual const char **getExtensions(uint32_t *extensionCount) = 0;
    virtual bool windowShouldClose() = 0;
    virtual void pollEvents() = 0;
    virtual void destroy() = 0;
};

#endif