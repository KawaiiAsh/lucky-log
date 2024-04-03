#include "../include/log_formatter.h"
#include <sstream>
#include <ctime>
#include <iomanip>

// 一个简单的日志格式化器实现
class SimpleLogFormatter : public LogFormatter {
public:
    std::string format(const std::string& level, const std::string& message) override {
        std::ostringstream formattedMessage;
        // 获取当前时间
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        // 格式化消息
        formattedMessage << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << " [" << level << "] " << message;
        return formattedMessage.str();
    }
};
