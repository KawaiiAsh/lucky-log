#include "../include/log_exception.h"

LogException::LogException(const std::string& message) : message(message) {}

const char* LogException::what() const noexcept {
    return message.c_str();
}
