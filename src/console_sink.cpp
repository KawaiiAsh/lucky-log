#include "../include/console_sink.h"
#include <iostream>

void ConsoleSink::log(const std::string& message) {
    std::cout << message << std::endl;
}
