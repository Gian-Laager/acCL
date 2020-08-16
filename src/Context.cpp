#include "Context.h"

ac::cl::Context::Context(const ac::cl::devices::Device* devices, int numberOfDevices)
{
    cl_device_id deviceIds[numberOfDevices];
    for (int i = 0; i < numberOfDevices; i++)
        deviceIds[i] = devices[i].getDeviceId();

    int errorCode;
    context = clCreateContext(nullptr, numberOfDevices, deviceIds,
                              nullptr,
                              nullptr, &errorCode);

    if (!context)
        throw ac::cl::exceptions::clException(errorCode);
}

ac::cl::Context::Context(ac::cl::devices::Device device)
{
    int errorCode;
    context = clCreateContext(nullptr, 1, &(const cl_device_id&) device.getDeviceId(),
                              nullptr,
                              nullptr, &errorCode);

    if (!context)
        throw ac::cl::exceptions::clException(errorCode);
}

cl_context ac::cl::Context::getContext() const
{
    return context;
}

ac::cl::Context::Context() : context(0) {}
