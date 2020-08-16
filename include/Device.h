//
// Created by Gian Laager on 14.08.20.
//

#ifndef ACCL_DEVICE_H
#define ACCL_DEVICE_H

#include "pch.h"

namespace ac::cl::devices
{
    class Device
    {
    private:
        cl_device_type deviceType;
        cl_platform_id platformId;
    protected:
        cl_device_id id;
    public:
        Device(cl_device_type deviceType = CL_DEVICE_TYPE_DEFAULT, cl_platform_id platformId = nullptr);
        cl_device_type getDeviceType();
        cl_device_id getDeviceId();
        void print_device_info();
    };

    class CpuDevice : public Device
    {
    public:
        CpuDevice(cl_platform_id platformId = nullptr);
    };

    class GpuDevice : public Device
    {
    public:
        GpuDevice(cl_platform_id platformId = nullptr);
    };

    class AcceleratorDevice : public Device
    {
    public:
        AcceleratorDevice(cl_platform_id platformId = nullptr);
    };
}

#endif //ACCL_DEVICE_H
