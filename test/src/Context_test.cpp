#include "Context_test.h"

void Context_test::SetUp()
{
    context = ac::cl::Context(device);
}

bool Context_test::isIdValid(cl_context context)
{
    return clGetContextInfo(context, CL_CONTEXT_DEVICES, 0, nullptr, nullptr) == CL_SUCCESS;
}

TEST(ContextConstructor_test, WillNotThrowAnException)
{
    ac::cl::devices::Device devices[] = {ac::cl::devices::CpuDevice(),
                                         ac::cl::devices::GpuDevice()};
    ac::cl::Context context;
    ASSERT_NO_THROW(context = ac::cl::Context(devices, 2));
    ASSERT_TRUE(Context_test::isIdValid(context.getContext()));
}

TEST_F(Context_test, WillIdBeVaild)
{
    ASSERT_TRUE(isIdValid(context.getContext()));
}