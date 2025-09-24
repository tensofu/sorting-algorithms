#include <array>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

// headers with sorting algorithms
#include "utils/algo_header.h"
#include "utils/bubble_sort.h"
#include "utils/merge_sort.h"
#include "utils/print.h"
#include "utils/quick_sort.h"

// Program to just compare different sorting algorithms
int main() {
  // Set up for setting the random numbers
  std::random_device rd;
  std::mt19937 engine{rd()};

  // different sizes to be tested
  std::array<int, 10> sizes = {1000,  2000,  5000,  10000, 20000,
                               30000, 40000, 50000, 70000, 100000};

  // for file writing + csv header
  std::ofstream outf("data/Benchmarks_Sorts.csv");
  outf << "algorithm,input_size,total_time,time_per_element" << std::endl;

  for (const auto& size : sizes) {
    // Generates the random array of numbers
    std::cout << "Size " << size << ":" << std::endl;

    // For a given input size, conduct three trials for each of the three
    // algorithms
    for (int j = 1; j <= 3; ++j) {
      // Generates random integers in the range [0, size/5]
      std::uniform_int_distribution<int> dist(0, size / 5);
      auto gen = [&]() { return dist(engine); };
      std::vector<int> random_nums(size);
      std::generate(random_nums.begin(), random_nums.end(), gen);

      // Starts the trials
      std::cout << "Trial " << j << ": " << std::endl;
      AlgorithmHeader current_header{};

      // Bubble Sort
      current_header = bubble_sort(random_nums);
      std::cout << std::fixed << current_header.title << ": "
                << std::setprecision(6) << current_header.total_time.count()
                << "s" << " | " << current_header.individual_time.count()
                << "s per element" << std::endl;
      outf << current_header.title << "," << size << ","
           << current_header.total_time.count() << ","
           << current_header.individual_time.count() << std::endl;

      // Quick Sort
      current_header = quick_sort(random_nums);
      std::cout << std::fixed << current_header.title << ": "
                << std::setprecision(6) << current_header.total_time.count()
                << "s" << " | " << current_header.individual_time.count()
                << "s per element" << std::endl;
      outf << current_header.title << "," << size << ","
           << current_header.total_time.count() << ","
           << current_header.individual_time.count() << std::endl;

      // Merge Sort
      current_header = merge_sort(random_nums);
      std::cout << std::fixed << current_header.title << ": "
                << std::setprecision(6) << current_header.total_time.count()
                << "s" << " | " << current_header.individual_time.count()
                << "s per element" << std::endl;
      outf << current_header.title << "," << size << ","
           << current_header.total_time.count() << ","
           << current_header.individual_time.count() << std::endl;
      std::cout << std::endl;
    }
  }

  // close the file
  outf.close();

  // SANITY CHECK
  int sanity = 100;

  std::uniform_int_distribution<int> dist(0, 100);
  auto gen = [&]() { return dist(engine); };
  std::vector<int> random_nums(sanity);
  std::generate(random_nums.begin(), random_nums.end(), gen);

  printf("Original Array: ");
  print_nums(random_nums);

  AlgorithmHeader sanity_check_bs = bubble_sort(random_nums, true);
  printf("Sorted Array (BUBBLE): ");
  print_nums(sanity_check_bs.result);

  AlgorithmHeader sanity_check_qs = quick_sort(random_nums, true);
  printf("Sorted Array (QUICKSORT): ");
  print_nums(sanity_check_qs.result);

  AlgorithmHeader sanity_check_ms = merge_sort(random_nums, true);
  printf("Sorted Array (MERGESORT): ");
  print_nums(sanity_check_ms.result);

  return 0;
}
