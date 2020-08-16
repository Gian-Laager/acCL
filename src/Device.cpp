#include "Device.h"

ac::cl::devices::GpuDevice::GpuDevice(cl_platform_id platformId) : Device(CL_DEVICE_TYPE_GPU, platformId) {}

ac::cl::devices::CpuDevice::CpuDevice(cl_platform_id platformId) : Device(CL_DEVICE_TYPE_CPU, platformId) {}

ac::cl::devices::Device::Device(cl_device_type deviceType, cl_platform_id platformId) : deviceType(deviceType), platformId(platformId)
{
    clGetDeviceIDs(platformId, deviceType, 1, &id, nullptr);
}

cl_device_type ac::cl::devices::Device::getDeviceType()
{
    return deviceType;
}

void ac::cl::devices::Device::print_device_info()
{
    char name[128];
    char vendor[128];

    clCallNoMsg(clGetDeviceInfo(id, CL_DEVICE_NAME, 128, name, nullptr));
    clCallNoMsg(clGetDeviceInfo(id, CL_DEVICE_VENDOR, 128, vendor, nullptr));

    std::cout << vendor << " : " << name << std::endl;
}

cl_device_id ac::cl::devices::Device::getDeviceId()
{
    return id;
}

ac::cl::devices::AcceleratorDevice::AcceleratorDevice(cl_platform_id platformId) : Device(CL_DEVICE_TYPE_ACCELERATOR, platformId) {}
