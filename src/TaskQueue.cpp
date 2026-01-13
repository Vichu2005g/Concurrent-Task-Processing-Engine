#include "TaskQueue.h"

void TaskQueue::push(Task task) {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        queue.push(std::move(task));
    }
    condition.notify_one();
}

Task TaskQueue::pop() {
    std::unique_lock<std::mutex> lock(queueMutex);
    condition.wait(lock, [this] { return !queue.empty() || shutdownFlag; });

    if (queue.empty() && shutdownFlag) {
        throw std::runtime_error("Queue is shutdown");
    }

    Task task = queue.top();
    queue.pop();
    return task;
}

std::optional<Task> TaskQueue::tryPop() {
    std::lock_guard<std::mutex> lock(queueMutex);
    if (queue.empty()) {
        return std::nullopt;
    }
    Task task = queue.top();
    queue.pop();
    return task;
}

void TaskQueue::shutdown() {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        shutdownFlag = true;
    }
    condition.notify_all();
}

bool TaskQueue::isShutdown() const {
    std::lock_guard<std::mutex> lock(queueMutex);
    return shutdownFlag;
}
