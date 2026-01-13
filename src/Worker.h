#pragma once
#include <thread>
#include <atomic>
#include "TaskQueue.h"

class Worker {
public:
    Worker(int id, TaskQueue& queue);
    ~Worker();

    void start();
    void stop();

private:
    void run();

    int id;
    TaskQueue& queue;
    std::thread workerThread;
    std::atomic<bool> running;
};
