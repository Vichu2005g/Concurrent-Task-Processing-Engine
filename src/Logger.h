#pragma once
#include <iostream>
#include <mutex>
#include <string>

class Logger {
public:
    static void log(const std::string& message);

private:
    static std::mutex logMutex;
};
