#include "../src/core/logger.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void testLogger() {
    std::string testLogFile = "test_log.txt"; // 测试日志文件的名称

    // 创建Logger实例
    Logger logger(testLogFile);

    // 记录不同级别的日志消息
    logger.log("This is a debug message", LogLevel::DEBUG);
    logger.log("This is an info message", LogLevel::INFO);
    logger.log("This is a warning message", LogLevel::WARNING);
    logger.log("This is an error message", LogLevel::ERROR);
    logger.log("This is a fatal message", LogLevel::FATAL);

    // 检查日志文件是否存在并且包含了一些内容
    std::ifstream logFile(testLogFile);
    std::stringstream buffer;
    buffer << logFile.rdbuf();

    std::string logContent = buffer.str();
    if (!logContent.empty()) {
        std::cout << "Test passed: Log file '" << testLogFile << "' has been created and contains log messages." << std::endl;
    } else {
        std::cerr << "Test failed: Log file '" << testLogFile << "' is empty or does not exist." << std::endl;
    }

    // 清理：删除测试日志文件
    if (logFile) {
        logFile.close();
        std::remove(testLogFile.c_str());
    }
}

int main() {
    testLogger();
    return 0;
}