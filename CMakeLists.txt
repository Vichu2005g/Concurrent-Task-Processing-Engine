cmake_minimum_required(VERSION 3.20)
project(ConcurrentTaskEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

    src/main.cpp
    src/Logger.cpp
    # later: src/Task.cpp src/TaskQueue.cpp src/Worker.cpp src/Utils.cpp
)
