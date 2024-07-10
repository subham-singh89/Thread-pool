#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for(size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back(&ThreadPool::workerThread, this);
    }
}

ThreadPool::~ThreadPool() {
    shutdown();
}

void ThreadPool::shutdown() {
    stop.store(true);
    condition.notify_all();
    for(std::thread &worker : workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

void ThreadPool::workerThread() {
    while(!stop.load()) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this] { return stop.load() || !tasks.empty(); });
            if (stop.load() && tasks.empty()) {
                return;
            }
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}
