#include <pch.h>

#include "acCL.h"

const char* ac::cl::exceptions::clException::what() const noexcept
{
    return message.c_str();
}

ac::cl::exceptions::clException::clException(int errorCode) : message(
"ErrorCode: " + std::to_string(errorCode)) {}

ac::cl::exceptions::clException::clException(std::string msg, int errorCode) : message(
        "ErrorCode: " + std::to_string(errorCode) + "\nMessage: " + std::move(msg)) {}
