#include <Device_test.h>

void Device_test::SetUp()
{
    try
    {
        device = new ac::cl::devices::Device;
        device->print_device_info();
    } catch (ac::cl::errors::clError&)
    {
        deviceTypeAvailable = false;
        std::cout << std::endl << "[Device_test] No default device available" << std::endl << std::endl;
    }
}

void CpuDevice_test::SetUp()
{
    try
    {
        device = new ac::cl::devices::CpuDevice;
        device->print_device_info();
    } catch (ac::cl::errors::clError&)
    {
        deviceTypeAvailable = false;
        std::cout << std::endl << "[Device_test] No CPU device available" << std::endl << std::endl;
    }
}

void GpuDevice_test::SetUp()
{
    try
    {
        device = new ac::cl::devices::GpuDevice;
        device->print_device_info();
    } catch (ac::cl::errors::clError&)
    {
        deviceTypeAvailable = false;
        std::cout << std::endl << "[Device_test] No GPU device available" << std::endl << std::endl;
    }

}

void AcceleratorDevice_test::SetUp()
{
    try
    {
        device = new ac::cl::devices::AcceleratorDevice;
        device->print_device_info();
    } catch (ac::cl::errors::clError&)
    {
        deviceTypeAvailable = false;
        std::cout << std::endl << "[Device_test] No Accelerator device available" << std::endl << std::endl;
    }
}

void AcceleratorDevice_test::TearDown()
{
    Device_test::TearDown();
}

void Device_test::TearDown()
{
    delete device;
}

bool Device_test::isIdValid(cl_device_id id)
{
    return clGetDeviceInfo(id, CL_DEVICE_NAME, 128, nullptr, nullptr) == CL_SUCCESS;
}

void GpuDevice_test::TearDown()
{
    Device_test::TearDown();
}

void CpuDevice_test::TearDown()
{
    Device_test::TearDown();
}

TEST_F(Device_test, WillIdBeValidAfterInitialization)
{
    if (deviceTypeAvailable)
    {
        ASSERT_TRUE(Device_test::isIdValid(device->getDeviceId()));
    }
}

TEST_F(CpuDevice_test, WillIdBeValidAfterInitializationAndDeviceTypeBeCpu)
{
    if (deviceTypeAvailable)
    {
        ASSERT_TRUE(Device_test::isIdValid(device->getDeviceId()));
        ASSERT_EQ(device->getDeviceType(), CL_DEVICE_TYPE_CPU);
    }
}

TEST_F(GpuDevice_test, WillIdBeValidAfterInitializationAndDeviceTypeBeGpu)
{
    if (deviceTypeAvailable)
    {
        ASSERT_TRUE(Device_test::isIdValid(device->getDeviceId()));
        ASSERT_EQ(device->getDeviceType(), CL_DEVICE_TYPE_GPU);
    }
}

TEST_F(AcceleratorDevice_test, WillIdBeValidAfterInitializationAndDeviceTypeBeAccelerator)
{
    if (deviceTypeAvailable)
    {
        ASSERT_TRUE(Device_test::isIdValid(device->getDeviceId()));
        ASSERT_EQ(device->getDeviceType(), CL_DEVICE_TYPE_ACCELERATOR);
    }
}

TEST(DeviceIsIdValidTest, WillreturnRightValue)
{
    ASSERT_FALSE(Device_test::isIdValid(0x0));

    cl_device_id validId;
    clGetDeviceIDs(nullptr, CL_DEVICE_TYPE_DEFAULT, 1, &validId, nullptr);
    ASSERT_TRUE(Device_test::isIdValid(validId));
}