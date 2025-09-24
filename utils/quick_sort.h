#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include <algorithm>
#include <chrono>

#include "algo_header.h"

// Modified from https://en.cppreference.com/w/cpp/algorithm/partition.html
template<class T>
void quicksort(T first, T last) {
  if (first == last)
    return;
  auto pivot = *std::next(first, std::distance(first, last) / 2);
  auto middle1 = std::partition(first, last, [pivot](const auto& em) {
    return em < pivot;
  });
  auto middle2 = std::partition(middle1, last, [pivot](const auto& em) {
    return !(pivot < em);
  });

  quicksort(first, middle1);
  quicksort(middle2, last);
}

AlgorithmHeader quick_sort(std::vector<int> nums, bool display=false) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();

  AlgorithmHeader header = {};
  // Quick Sort Algorithm
  auto it = std::partition(nums.begin(), nums.end(), [](int i) {return i % 2 == 0;});
  quicksort(nums.begin(), nums.end());

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> total_time = end - start;

  // Returns the values to the header
  header.title = "QUICKSORT";
  header.total_time = total_time;
  header.individual_time = total_time / nums.size();
  if (display) { header.result = nums; }
  else { header.result = {}; }
  
  return header;
}

#endif
