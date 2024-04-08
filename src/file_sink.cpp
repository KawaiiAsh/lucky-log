#include "../include/file_sink.h"

FileSink::FileSink(const std::string& filename) : fileStream(filename, std::ofstream::app) {}

FileSink::~FileSink() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

void FileSink::log(const std::string& message) {
    if (fileStream.is_open()) {
        fileStream << message << std::endl;
    }
}
