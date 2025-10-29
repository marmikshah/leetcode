// ref: https://leetcode.com/problems/two-sum/
#include "common.hpp"

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
        result.push_back(cache[difference]);
        result.push_back(i);
        break;
      }
    }
    return result;
  }
};

struct TestCase {
  vector<int>& nums;
  int target; 
  vector<int> expectedOutput;

  TestCase(vector<int> nums, int target, vector<int> expectedOutput) {
    this->nums = nums;
    this->target = target;
    this->expectedOutput = expectedOutput;
  }

  bool didPassTest(Solution *sol){
    vector<int> result = sol->twoSum(this->nums, this->target);
    return result == expectedOutput;
  }
};

int main() {
  TestCase cases[] = {
    TestCase({}, 2, {})
  };
  Solution *soln;
  for(TestCase _case: cases){
    assert(_case.didPassTest(soln));
  }
  cout<<"All Tests Passed!"<<std::endl;
}