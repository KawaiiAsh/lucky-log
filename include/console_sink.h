#pragma once

#include "log_sink.h"
#include <string>

class ConsoleSink : public LogSink {
public:
    void log(const std::string& message) override;
};
