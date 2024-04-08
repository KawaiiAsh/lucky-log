#pragma once

#include <string>

class LogSink {
public:
    virtual ~LogSink() = default;
    virtual void log(const std::string& message) = 0;
};
