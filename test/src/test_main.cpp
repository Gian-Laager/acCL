//
// Created by Gian Laager on 13.08.20.
//
#include "test_pch.h"

TEST(InitialTest, WillTestFunctionInLibraryReturnOne)
{
    ASSERT_EQ(test(), 1);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}