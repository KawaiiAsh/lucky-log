#ifndef LOG_FORMATTER_H
#define LOG_FORMATTER_H

#include <string>

// 定义日志消息格式化的接口
class LogFormatter {
public:
    virtual ~LogFormatter() {}

    // 格式化日志消息
    // level: 日志等级（例如，INFO, ERROR）
    // message: 原始日志消息
    // 返回: 格式化后的日志消息
    virtual std::string format(const std::string& level, const std::string& message) = 0;
};

#endif // LOG_FORMATTER_H
