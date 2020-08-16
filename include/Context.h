#ifndef ACCL_CONTEXT_H
#define ACCL_CONTEXT_H

#include "pch.h"
#include "Device.h"

namespace ac::cl
{
    class Context
    {
        cl_context context;
    public:
        Context(const ac::cl::devices::Device* devices, int numberOfDevices);

        Context(ac::cl::devices::Device device);

        Context();

        cl_context getContext() const;
    };
}

#endif //ACCL_CONTEXT_H


