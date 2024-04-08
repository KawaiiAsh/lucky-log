#pragma once

#include "log_sink.h"
#include <fstream>
#include <string>

class FileSink : public LogSink {
public:
    FileSink(const std::string& filename);
    ~FileSink();

    void log(const std::string& message) override;

private:
    std::ofstream fileStream;
};
