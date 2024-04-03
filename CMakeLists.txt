cmake_minimum_required(VERSION 3.27)
project(lucky_log)

set(CMAKE_CXX_STANDARD 11)

add_executable(ver_log
        src/core/logger.cpp
        src/core/logger.h
        test/test_logger.cpp)