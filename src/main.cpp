#include <iostream>
#include "Logger.h"
#include "TaskQueue.h"
#include "Worker.h"
#include "Utils.h"

int main() {
    Logger::log("Starting Concurrent Task Engine...");

    TaskQueue queue;
    const int numWorkers = 4;
    std::vector<std::unique_ptr<Worker>> workers;

    // 1. Spawn Workers
    for (int i = 0; i < numWorkers; ++i) {
        auto worker = std::make_unique<Worker>(i + 1, queue);
        worker->start();
        workers.push_back(std::move(worker));
    }

    // 2. Generate Tasks
    for (int i = 1; i <= 20; ++i) {
        queue.push(Task(i, [i]{ 
            int duration = Utils::random(50, 200);
            Logger::log("Task " + std::to_string(i) + " processing (" + std::to_string(duration) + "ms)");
            Utils::sleep(duration); 
        }));
    }

    // 3. Wait for completion (Simple duration wait for demo)
    Logger::log("All tasks submitted. Waiting for completion...");
    Utils::sleep(3000);

    // 4. Shutdown
    Logger::log("Shutting down system...");
    queue.shutdown();
    
    for (auto& worker : workers) {
        worker->stop();
    }
    
    Logger::log("System exited cleanly.");

    return 0;
}
