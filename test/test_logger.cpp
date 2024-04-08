#include "../include/logger.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/stat.h> // 添加头文件以检查路径是否为目录
#include <sys/types.h>
#include <pwd.h>

// 读取配置文件中的日志路径
std::string readLogPathFromConfig(const std::string& configFile) {
    std::ifstream file(configFile);
    std::string line;
    std::string logPath;

    while (std::getline(file, line)) {
        if (line.find("log_path") != std::string::npos) {
            std::size_t found = line.find("=");
            if (found != std::string::npos) {
                logPath = line.substr(found + 1);
                // 去除字符串前后的空格
                logPath.erase(0, logPath.find_first_not_of(" \t\n\r"));
                logPath.erase(logPath.find_last_not_of(" \t\n\r") + 1);
                break;
            }
        }
    }

    return logPath;
}

// 检查指定的路径是否为目录
bool isDirectory(const std::string& path) {
    struct stat statbuf;
    if (stat(path.c_str(), &statbuf) != -1) {
        return S_ISDIR(statbuf.st_mode);
    }
    return false;
}

void testLogger() {
    // 从配置文件中读取日志路径
    std::string configFile = "/Users/ashe/Desktop/lucky-log/config/config.ini";
    std::string logPath = readLogPathFromConfig(configFile);

    // 如果logPath是一个目录，添加文件名
    if (isDirectory(logPath)) {
        logPath += "/test_logger.txt"; // 确保这是一个有效的文件路径
    }

    // 创建Logger实例
    Logger logger(logPath);

    // 记录不同级别的日志消息
    logger.log("This is a debug message", LogLevel::DEBUG);
    logger.log("This is an info message", LogLevel::INFO);
    logger.log("This is a warning message", LogLevel::WARNING);
    logger.log("This is an error message", LogLevel::ERROR);
    logger.log("This is a fatal message", LogLevel::FATAL);

    // 检查日志文件是否存在并且包含了一些内容
    std::ifstream logFile(logPath);
    std::stringstream buffer;
    buffer << logFile.rdbuf();

    std::string logContent = buffer.str();
    if (!logContent.empty()) {
        std::cout << "Test passed: Log file '" << logPath << "' has been created and contains log messages." << std::endl;
    } else {
        std::cerr << "Test failed: Log file '" << logPath << "' is empty or does not exist." << std::endl;
    }
}

//int main() {
//    testLogger();
//    return 0;
//}
