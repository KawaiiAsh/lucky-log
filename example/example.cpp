#include <iostream>
#include <string>
#include "../include/console_sink.h"
#include "../include/file_sink.h"
#include "../include/log_archive.h"
#include "../include/log_formatter.h"
#include "../include/log_rolling.h"
#include "../include/logger.h"

int main() {
    // Set up formatter
    SimpleLogFormatter formatter;

    // Set up console logger
    ConsoleSink consoleSink;

    // Set up file logger with rolling functionality
    std::string baseFilename = "app_log";
    unsigned int maxSize = 1024 * 1024 * 5; // 5 MB for demonstration
    LogRolling rolling(baseFilename, maxSize);
    std::string logFile = rolling.getFilename();
    FileSink fileSink(logFile);

    // Optional: Set up a log archive (not used directly in this example)
    LogArchive archive("log_archive/");

    // Simulate a log message
    std::string level = "INFO";
    std::string message = "This is a test log message.";

    // Format the message
    std::string formattedMessage = formatter.format(level, message);

    // Log to console
    consoleSink.log(formattedMessage);

    // Log to file
    fileSink.log(formattedMessage);

    // Simulate reaching the max size and rolling over
    // Note: This is just a simulation; your actual implementation should check the file size
    //    rolling.rollOver();

    // New log message to demonstrate file rollover
    std::string newMessage = formatter.format("DEBUG", "This is a post-rollover log message.");
    fileSink.log(newMessage);

    // Optional: Archive the old log file (actual implementation details might differ)
    // archive.archive(logFile);

    return 0;
}
