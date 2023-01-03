#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/two-sum/

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> result;
    if (nums.size() < 2) return result;
    std::unordered_map<int, int> cache;
    for (int i = 0; i < nums.size(); i++) {
      int item = nums[i];
      int difference = target - item;
      if (cache.find(difference) == cache.end()) {
        cache[item] = i;
      } else {
        // Item found
        result.push_back(cache[difference]);
        result.push_back(i);
        break;
      }
    }
    return result;
  }
};