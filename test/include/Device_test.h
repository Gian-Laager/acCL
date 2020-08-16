#ifndef ACCL_DEVICE_TEST_H
#define ACCL_DEVICE_TEST_H

#include "test_pch.h"
#include "Device.h"
#include "acCL.h"

class Device_test : public testing::Test
{
protected:
    ac::cl::devices::Device* device;

    void SetUp() override;

    void TearDown() override;

    bool deviceTypeAvailable = true;

public:
    static bool isIdValid(cl_device_id id);
};

class GpuDevice_test : public Device_test
{
protected:
    void SetUp() override;

    void TearDown() override;
};

class CpuDevice_test : public Device_test
{
protected:
    void SetUp() override;

    void TearDown() override;
};

class AcceleratorDevice_test : public Device_test
{
protected:
    void SetUp() override;

    void TearDown() override;
};

#endif //ACCL_DEVICE_TEST_H


