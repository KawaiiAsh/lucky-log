cmake_minimum_required(VERSION 3.27)
project(lucky_log)

set(CMAKE_CXX_STANDARD 11)

add_executable(ver_log
        src/logger.cpp
        include/logger.h
        src/log_formatter.cpp
        include/log_formatter.h
        include/log_sink.h
        include/console_sink.h
        src/console_sink.cpp
        include/file_sink.h
        src/file_sink.cpp
        include/log_rolling.h
        src/log_rolling.cpp
        include/log_archive.h
        src/log_archive.cpp
        include/log_exception.h
        src/log_exception.cpp
        example/example.cpp
        #        test/test_logger.cpp
        #        test/test_formatter.cpp
)