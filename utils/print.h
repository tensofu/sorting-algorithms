#ifndef PRINT_H
#define PRINT_H

#include <vector>

void print_nums(const std::vector<int>& nums) {
  for (const auto& num : nums) {
    printf("%d ", num);
  }
  printf("\n");
}

#endif
