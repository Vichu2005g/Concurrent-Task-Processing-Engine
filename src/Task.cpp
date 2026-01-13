#include "Task.h"
#include <utility>

Task::Task(int id, int priority, WorkItem work) 
    : id(id), priority(priority), work(std::move(work)) {}

void Task::perform() const {
    if (work) {
        work();
    }
}

int Task::getID() const {
    return id;
}

int Task::getPriority() const {
    return priority;
}

bool Task::operator<(const Task& other) const {
    // std::priority_queue puts the LARGEST element at the top.
    // If we want Priority 10 to run before Priority 1, then 1 < 10.
    return priority < other.priority;
}
