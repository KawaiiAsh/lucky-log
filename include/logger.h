#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <fstream>

/**
 * 枚举定义不同的日志级别用于记录消息。
 * 枚举值及其含义如下：
 * - DEBUG: 调试级别，用于详细调试信息。
 * - INFO: 信息级别，用于一般信息消息。
 * - WARNING: 警告级别，用于可能不会停止程序的潜在问题。
 * - ERROR: 错误级别，用于可能影响程序功能的错误。
 * - FATAL: 致命级别，用于导致程序终止的关键错误。
 */
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
};

class Logger {
public:
    /**
     * 构造函数
     * @param logFile 日志文件路径
     */
    Logger(const std::string &logFile);

    // 析构函数
    ~Logger();

    // 禁止拷贝构造和赋值
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    /**
     * 记录信息
     * @param message 记录的消息
     * @param level 日志级别
     */
    void log(const std::string &message, LogLevel level);

private:
    std::ofstream logStream; // 文件流

    /**
     * 根据日志级别获取字符串表示
     * @param level 日志级别
     * @return 对应的字符串表示
     */
    std::string levelToString(LogLevel level);
};

#endif // LOGGER_H