//
// Created by Gian Laager on 13.08.20.
//

#ifndef ACCL_PCH_H
#define ACCL_PCH_H

#include <OpenCL/opencl.h>
#include <exception>
#include <iostream>
#include <sstream>

namespace ac::cl::exceptions
{
    class clException : public std::exception
    {
        std::string message;
    public:
        clException(std::string msg, int errorCode);
        clException(int errorCode);

        clException() = default;

        const char* what() const noexcept override;
    };
}

#define clCall(clFunction, message) if (int errorCode = clFunction != CL_SUCCESS)                            \
    throw ac::cl::exceptions::clException(errorCode, message)

#define clCallNoMsg(clFunction) if (int errorCode = clFunction != CL_SUCCESS)                            \
    throw ac::cl::exceptions::clException(errorCode)

#endif //ACCL_PCH_H
