#include "../include/log_rolling.h"
#include <sstream>
#include <filesystem>

LogRolling::LogRolling(const std::string& baseFilename, unsigned int maxSize)
        : baseFilename(baseFilename), maxSize(maxSize) {}

std::string LogRolling::getFilename() {
    if (currentSize >= maxSize) {
        rollOver();
    }
    std::stringstream ss;
    ss << baseFilename << "." << index;
    return ss.str();
}

void LogRolling::rollOver() {
    currentSize = 0;
    ++index;
    // 这里应该有额外的逻辑来处理文件的物理滚动，比如备份当前文件，创建新文件等。
    // 还没写完
}
