#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <vector>
#include <algorithm>
#include <chrono>

#include "algo_header.h"

AlgorithmHeader bubble_sort(std::vector<int> nums, bool display=false) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();

  AlgorithmHeader header = {};
  // Bubble Sort Algorithm
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i; j < nums.size(); j++) {
      if (nums[j] < nums[i]) {
        std::swap(nums[i], nums[j]);
      }
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> total_time = end - start;

  // Returns the values to the header
  header.title = "BUBBLESORT";
  header.total_time = total_time;
  header.individual_time = total_time / nums.size();
  if (display) { header.result = nums; }
  else { header.result = {}; }
  
  return header;
}

#endif
