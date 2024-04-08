#pragma once

#include <string>

class LogArchive {
public:
    LogArchive(const std::string& archivePath);
    void archive(const std::string& filename);

private:
    std::string archivePath;
};
