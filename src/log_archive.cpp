#include "../include/log_archive.h"
#include <filesystem>

LogArchive::LogArchive(const std::string& archivePath) : archivePath(archivePath) {}

void LogArchive::archive(const std::string& filename) {
    // 假设这个函数将文件移动到存档路径
    std::__fs::filesystem::path targetPath = std::__fs::filesystem::path(archivePath) / std::__fs::filesystem::path(filename).filename();
    std::__fs::filesystem::rename(filename, targetPath);
}
