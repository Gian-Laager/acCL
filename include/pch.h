//
// Created by Gian Laager on 13.08.20.
//

#ifndef ACCL_PCH_H
#define ACCL_PCH_H

#include <OpenCL/opencl.h>
#include <exception>
#include <iostream>
#include <sstream>

namespace ac::cl::errors
{
    class clError : public std::exception
    {
        std::string message;
    public:
        clError(std::string msg);

        clError() = default;

        const char* what() const noexcept override;
    };
}

#define clCall(clFunction, message) if (int errorCode = clFunction != CL_SUCCESS)                            \
    throw ac::cl::errors::clError("Error code: " + std::to_string(errorCode) + "\nMessage: " + message)

#define clCallNoMsg(clFunction) if (int errorCode = clFunction != CL_SUCCESS)                            \
    throw ac::cl::errors::clError("Error code: " + std::to_string(errorCode))

#endif //ACCL_PCH_H
