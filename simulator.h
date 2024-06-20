#ifndef SIMULATOR_H
#define SIMULATOR_H

#define RANDOM_SEED 369369

#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>


class Schedule {
private:
  double time_;
  std::function<void()> function_;

public:
  double time() { return time_; }
  void call() { function_(); }

  Schedule(double time, std::function<void()> function)
      : time_(time), function_(function) {}
  
  bool operator<(const Schedule &other) const {
    return time_ > other.time_;
  }
};

class Simulator {
private:
  static double time_;
  static std::priority_queue<Schedule> schedule_queue;

public:
  static double now() { return time_; }

  static void prepare() { srand(RANDOM_SEED); }

  static void schedule(double time, std::function<void()> function) {
    // 스케줄 큐에 스케줄을 추가한다.
    // TODO: 구현
    schedule_queue.push(Schedule(time, function));
  }

  static void run() {
    // 모든 스케줄을 실행한다.
    // TODO: 구현
    while (!schedule_queue.empty()) {
      Schedule schedule = schedule_queue.top();
      schedule_queue.pop();
      schedule.call();
      time_ += schedule.time();
    }
  }
};

#endif