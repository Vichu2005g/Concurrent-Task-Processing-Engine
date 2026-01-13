#include "Task.h"
#include <utility>

Task::Task(int id, WorkItem work) : id(id), work(std::move(work)) {}

void Task::perform() const {
    if (work) {
        work();
    }
}

int Task::getID() const {
    return id;
}
