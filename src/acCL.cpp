#include "acCL.h"

const char* ac::cl::errors::clError::what() const noexcept
{
    return message.c_str();
}

ac::cl::errors::clError::clError(std::string msg) : message(std::move(msg)) {}
