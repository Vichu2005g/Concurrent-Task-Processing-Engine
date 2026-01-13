#pragma once
#include <functional>

class Task {
public:
    using WorkItem = std::function<void()>;

    Task(int id, WorkItem work);

    void perform() const;
    int getID() const;

private:
    int id;
    WorkItem work;
};
