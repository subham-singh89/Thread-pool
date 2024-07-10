#include <iostream>
#include <chrono>
#include <thread>
#include "ThreadPool.h"

void printTask(int n) {
    std::cout << "Processing task " << n << " on thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * n)); // Simulate work by sleeping
}

int main() {
    ThreadPool pool(4);

    std::vector<std::future<void>> results;
    for (int i = 0; i < 10; ++i) {
        results.emplace_back(pool.enqueue(printTask, i));
    }

    for (auto &&result : results) {
        result.get();
    }

    pool.shutdown();

    std::cout << "All tasks completed." << std::endl;

    return 0;
}
