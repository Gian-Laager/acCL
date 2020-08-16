#ifndef ACCL_CONTEXT_TEST_H
#define ACCL_CONTEXT_TEST_H

#include "test_pch.h"
#include "acCL.h"

class Context_test : public testing::Test
{
protected:
    ac::cl::devices::Device device;
    ac::cl::Context context;

    void SetUp() override;
public:
    static bool isIdValid(cl_context context);
};



#endif //ACCL_CONTEXT_TEST_H
