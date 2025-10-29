#include <assert.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * ref: https://leetcode.com/problems/find-pivot-index
 * Given an array of integers nums, calculate the pivot index of this array.
 * The pivot index is the index where the sum of all the numbers strictly to the
 * left of the index is equal to the sum of all the numbers strictly to the
 * index's right. If the index is on the left edge of the array, then the left
 * sum is 0 because there are no elements to the left. This also applies to the
 * right edge of the array. Return the leftmost pivot index. If no such index
 * exists, return -1.
 */
class Solution {
 public:
  // NOTE: For the sake of initializing in functioncall, the arg is pass by
  // value. (Change to reference on submission)
  int pivotIndex(vector<int> nums) {
    int totalSum = 0;
    for (auto& item : nums) totalSum += item;

    int leftSum = 0, rightSum = totalSum;
    for (int pivot = 0; pivot < nums.size(); pivot++) {
      if (rightSum - nums[pivot] == leftSum) {
        return pivot;
      } else {
        leftSum += nums[pivot];
        rightSum -= nums[pivot];
      }
    }
    return -1;
  }
};

int main() {
  /*
   * Edge case
    - Pivot index = 0;
    - Pivot index = n - 1;
  */

  Solution sol;

  assert(sol.pivotIndex({1, 7, 3, 6, 5, 6}) == 3);
  assert(sol.pivotIndex({0, 0, 0, 1,  13, 1, 2,  3,   5,   1,   1,   3, 1,  2,
                         1, 2, 0, 10, 1,  1, 10, 111, 120, 120, 101, 0, 101}) ==
         -1);                                                // Not found
  assert(sol.pivotIndex({[-1, 1, -1, 1, -1, 1, -1]} == 0));  // Leftmost
  assert(sol.pivotIndex({-1, 1, -2, 2, 0}) == 4);            // Rightmost

  std::cout << "All tests passed" << std::endl;

  return 0;
}