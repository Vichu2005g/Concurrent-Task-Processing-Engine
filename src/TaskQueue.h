#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>
#include "Task.h"

class TaskQueue {
public:
    void push(Task task);
    
    // Blocking pop: waits if queue is empty
    Task pop();
    
    // Non-blocking pop attempts
    std::optional<Task> tryPop();

    void shutdown();
    bool isShutdown() const;

private:
    std::priority_queue<Task> queue;
    mutable std::mutex queueMutex;
    std::condition_variable condition;
    bool shutdownFlag = false;
};
