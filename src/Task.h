#pragma once
#include <functional>

class Task {
public:
    using WorkItem = std::function<void()>;

    Task(int id, int priority, WorkItem work);

    void perform() const;
    int getID() const;
    int getPriority() const;

    // Operator for priority comparisons (lower value means higher priority for simple sorting, 
    // but std::priority_queue puts max element at top. 
    // We generally want Higher Priority Value = Run First.
    // So 'a < b' should return true if 'a' has lower priority than 'b'.
    bool operator<(const Task& other) const;

private:
    int id;
    int priority;
    WorkItem work;
};
