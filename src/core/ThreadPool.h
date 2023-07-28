//
// Created by yuhi y on 2023/07/28.
//

#ifndef CPP_HTTP_SERVER_THREADPOOL_H
#define CPP_HTTP_SERVER_THREADPOOL_H

#include <cstdio>
#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

class ThreadPool {
public:
    explicit ThreadPool(size_t threads) : stop(false) {
        for(size_t i = 0; i < threads; ++i){
            workers.emplace_back([this] {
                 for(;;) {
                     std::packaged_task<void()> task;
                     {
                         std::unique_lock<std::mutex> lock(this->queue_mutex);
                         this->condition.wait(lock,
                                              [this] { return this->stop || !this->tasks.empty(); });
                         if(this->stop && this->tasks.empty())
                             return;
                         task = std::move(this->tasks.front());
                         this->tasks.pop();
                     }
                     task();
                 }
            });
        }

    }

    template<class F>
    void enqueue(F&& f) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if(stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");
            tasks.emplace(std::forward<F>(f));
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for(std::thread &worker: workers)
            worker.join();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::packaged_task<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

#endif //CPP_HTTP_SERVER_THREADPOOL_H
