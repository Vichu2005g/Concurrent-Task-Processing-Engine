#include <iostream>
#include "Logger.h"
#include "TaskQueue.h"
#include "Worker.h"
#include "Utils.h"

int main() {
    Logger::log("Starting Concurrent Task Engine...");

    TaskQueue queue;
    
    // Create and start a worker
    Worker worker(1, queue);
    worker.start();

    // Push tasks
    for (int i = 1; i <= 5; ++i) {
        queue.push(Task(i, [i]{ 
            Logger::log("Task " + std::to_string(i) + " executing...");
            Utils::sleep(100); 
        }));
    }

    // Give time for processing
    Utils::sleep(1000);

    // Shutdown
    queue.shutdown();
    worker.stop();

    return 0;
}
