#include <iostream>
#include "Logger.h"
#include "TaskQueue.h"

int main() {
    Logger::log("Starting Concurrent Task Engine...");

    TaskQueue queue;
    
    // Simulate adding tasks
    queue.push(Task(1, []{ Logger::log("Task 1 executed"); }));
    queue.push(Task(2, []{ Logger::log("Task 2 executed"); }));

    // Simulate consuming tasks
    Task t1 = queue.pop();
    t1.perform();

    Task t2 = queue.pop();
    t2.perform();

    return 0;
}
