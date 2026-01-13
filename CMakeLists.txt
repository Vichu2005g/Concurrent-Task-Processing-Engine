cmake_minimum_required(VERSION 3.20)
project(ConcurrentTaskEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConcurrentTaskEngine
    src/main.cpp
    src/Logger.cpp
    src/Utils.cpp
    src/Task.cpp
    src/TaskQueue.cpp
    src/Worker.cpp
    # later: src/Task.cpp src/TaskQueue.cpp src/Worker.cpp src/Utils.cpp
)
