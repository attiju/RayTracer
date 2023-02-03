#ifndef TIMER_HH
#define TIMER_HH

#include <core.hpp>

class Timer {
 public:
  inline Timer();

 public:
  long long elapsed_time() const;

 private:
  std::chrono::steady_clock::time_point begin;
};

#include <timer.inl>

#endif