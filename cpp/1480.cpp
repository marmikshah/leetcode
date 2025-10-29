#include <assert.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using vec = std::vector<int>;

/**
 * ref: https://leetcode.com/problems/running-sum-of-1d-array/
 * Problem Statement
 * Given an array nums. We define a running sum of an array as runningSum[i] =
 * sum(nums[0]…nums[i]). Return the running sum of nums.
 */

class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    std::vector<int> result;
    int sum = 0;
    for (auto item : nums) {
      sum += item;
      result.push_back(sum);
    }
    return result;
  }
};

int main() {
  Solution sol;

  /**
   * Array Size Constraint:
   * 1 <= nums.length <= 1000
   */

  vec inputA = {1, 1, 1};
  vec outputA = {1, 2, 3};
  assert(sol.runningSum(inputA) == outputA);

  vec inputB = {1, 2, 3, 4};
  vec outputB = {1, 3, 6, 10};
  assert(sol.runningSum(inputB) == outputB);

  // Edge Case (len = 1)
  vec inputC = {1};
  vec outputC = {1};
  assert(sol.runningSum(inputC) == outputC);

  std::cout << "All tests passed" << std::endl;
}