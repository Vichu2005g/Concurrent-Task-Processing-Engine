# Concurrent Task Processing Engine (C++20)

## Overview
A high-performance, multi-threaded task processing engine designed to mimic real-world backend systems (like those used at Amazon or in Game Engine architecture). This system uses a **Thread Pool** pattern with a **Priority Queue** to efficiently process incoming tasks based on importance, ensuring thread safety and optimal resource utilization.

## Tech Stack
*   **Language**: C++20
*   **Concurrency**: `std::thread`, `std::mutex`, `std::condition_variable`
*   **Build System**: CMake
*   **CI/CD**: GitHub Actions

## Architecture
The system follows the **Producer-Consumer** pattern:

1.  **Main Driver (Producer)**: Generates tasks with random execution times and priorities.
2.  **TaskQueue (Thread-Safe Bridge)**: A synchronized queue that holds tasks. Uses `std::priority_queue` to ensure high-priority tasks are processed first.
3.  **Worker Pool (Consumers)**: A dynamic pool of worker threads that continuously pull tasks from the queue and execute them.

### Key Components
*   `Task`: Represents a unit of work (ID, Priority, Payload).
*   `TaskQueue`: Manages synchronization using Condition Variables to prevent "busy waiting".
*   `Worker`: Encapsulates a thread that lives for the duration of the application.
*   `Logger`: Ensures console output doesn't get garbled when multiple threads write simultaneously.

## Key Features
*   **Priority Scheduling**: Tasks are processed based on priority (1-100), not just arrival time.
*   **Graceful Shutdown**: System ensures all workers are stopped cleanly preventing resource leaks.
*   **Zero Busy-Waiting**: Workers sleep when the queue is empty, saving CPU cycles.

## How to Build & Run

### Prerequisites
*   CMake (3.20+)
*   C++ Compiler (GCC, Clang, or MSVC)

### Steps
```bash
# 1. Clone the repository
git clone https://github.com/Vichu2005g/Concurrent-Task-Processing-Engine.git

# 2. Create build directory
cmake -S . -B build

# 3. Build the project
cmake --build build

# 4. Run the engine
./build/Debug/ConcurrentTaskEngine.exe
```

## 📸 Output Example
```text
[Logger] Starting Concurrent Task Engine...
[Logger] Worker 1 started.
[Logger] Worker 2 started.
[Logger] Task 5 [Priority 99] processing (50ms)  <-- High Priority runs first!
[Logger] Task 1 [Priority 10] processing (120ms)
...
[Logger] Shutting down system...
[Logger] System exited cleanly.
```