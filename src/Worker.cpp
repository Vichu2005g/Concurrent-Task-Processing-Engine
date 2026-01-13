#include "Worker.h"
#include "Logger.h"
#include <iostream>

Worker::Worker(int id, TaskQueue& queue) 
    : id(id), queue(queue), running(false) {}

Worker::~Worker() {
    stop();
}

void Worker::start() {
    running = true;
    workerThread = std::thread(&Worker::run, this);
    Logger::log("Worker " + std::to_string(id) + " started.");
}

void Worker::stop() {
    if (running) {
        running = false;
        if (workerThread.joinable()) {
            workerThread.join();
        }
        Logger::log("Worker " + std::to_string(id) + " stopped.");
    }
}

void Worker::run() {
    while (running) {
        try {
            if (queue.isShutdown() && !running) break;
            
            Task task = queue.pop();
            // Logger::log("Worker " + std::to_string(id) + " processing task " + std::to_string(task.getID()));
            task.perform();
        } catch (const std::exception&) {
            // Queue was shutdown
            break;
        }
    }
}
