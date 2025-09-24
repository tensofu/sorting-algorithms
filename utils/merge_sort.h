#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <algorithm>
#include <chrono>

#include "algo_header.h"

void merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
  size_t i = 0; // Index for the left subarray (L)
  size_t j = 0; // Index for the right subarray (R)
  size_t k = 0; // Index for the main array (arr)

  // Merging
  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < left.size()) {
    arr[k] = left[i];
    i++;
    k++;
  }

  // Copy any remaining elements from the right subarray
  while (j < right.size()) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void mergesort(std::vector<int>& arr) {
  // Base case: An array with 0 or 1 element is already sorted
  if (arr.size() <= 1) {
    return;
  }

  // Get the middle of the array
  size_t mid = arr.size() / 2;
  
  // Create temporary left and right subarrays
  std::vector<int> left(arr.begin(), arr.begin() + mid);
  std::vector<int> right(arr.begin() + mid, arr.end());

  // Recursively sort the two halves
  mergesort(left);
  mergesort(right);

  // Merge the sorted halves back into the original array
  merge(arr, left, right);
}

AlgorithmHeader merge_sort(std::vector<int> nums, bool display=false) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();

  AlgorithmHeader header = {};
  // Merge Sort Algorithm
  mergesort(nums);

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> total_time = end - start;

  // Returns the values to the header
  header.title = "MERGESORT";
  header.total_time = total_time;
  header.individual_time = total_time / nums.size();
  if (display) { header.result = nums; }
  else { header.result = {}; }
  
  return header;
}

#endif
