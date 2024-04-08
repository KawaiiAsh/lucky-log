#pragma once

#include <exception>
#include <string>

class LogException : public std::exception {
public:
    explicit LogException(const std::string& message);
    const char* what() const noexcept override;

private:
    std::string message;
};
