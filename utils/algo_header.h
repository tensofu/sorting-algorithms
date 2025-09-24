#ifndef ALGORITHM_HEADER_STRUCT
#define ALGORITHM_HEADER_STRUCT

#include <string>
#include <chrono>

struct AlgorithmHeader {
  std::string title = "None";
  std::chrono::duration<double> total_time;
  std::chrono::duration<double> individual_time;
  std::vector<int> result;
};

#endif
