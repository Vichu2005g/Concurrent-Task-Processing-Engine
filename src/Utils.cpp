#include "Utils.h"
#include <random>
#include <thread>
#include <chrono>

namespace Utils {
    int random(int min, int max) {
        // Static thread_local to ensure unique seeding per thread
        static thread_local std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(generator);
    }

    void sleep(int milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
}
