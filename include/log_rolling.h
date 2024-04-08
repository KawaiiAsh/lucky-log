#pragma once

#include <string>

class LogRolling {
public:
    LogRolling(const std::string& baseFilename, unsigned int maxSize);
    std::string getFilename();

private:
    std::string baseFilename;
    unsigned int maxSize;
    unsigned int currentSize = 0;
    unsigned int index = 0;

    void rollOver();
};
