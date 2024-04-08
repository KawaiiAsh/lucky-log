#include "../include/log_formatter.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <regex>
#include <iomanip>

class SimpleLogFormatter : public LogFormatter {
public:
    std::string format(const std::string& level, const std::string& message) override {
        std::ostringstream formattedMessage;
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        formattedMessage << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << " [" << level << "] " << message;
        return formattedMessage.str();
    }
};

bool testSimpleLogFormatter() {
    SimpleLogFormatter formatter;
    std::string level = "INFO";
    std::string message = "Test message";
    std::string formattedMessage = formatter.format(level, message);

    // 检查是否正确地格式化了消息
    // 这里仅示范使用正则表达式做简单验证，实际项目中应更细致地测试
    std::regex pattern("^\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2} \\[INFO\\] Test message$");
    bool isMatch = std::regex_match(formattedMessage, pattern);

    std::cout << "Test result: " << (isMatch ? "PASSED" : "FAILED") << std::endl;
    return isMatch;
}

//int main() {
//    bool result = testSimpleLogFormatter();
//    return result ? 0 : 1;
//}