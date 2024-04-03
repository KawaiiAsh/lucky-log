#include "../include/logger.h"
#include <stdexcept>
#include <ctime>
#include <sstream>

Logger::Logger(const std::string &logFile) {
    logStream.open(logFile, std::ios::app); // 以追加模式打开文件
    if (!logStream.is_open()) {
        throw std::runtime_error("Unable to open log file: " + logFile);
    }
}

Logger::~Logger() {
    if (logStream.is_open()) {
        logStream.close();
    }
}

void Logger::log(const std::string &message, LogLevel level) {
    // 获取当前时间并格式化为字符串
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::string strTime = oss.str();

    // 写入日志条目
    logStream << "[" << strTime << "] [" << levelToString(level) << "] " << message << std::endl;
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}