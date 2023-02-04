#include <assert.h>
#include <math.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

/**
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search
 * target in nums. If target exists, then return its index. Otherwise, return -1. You must write an algorithm with O(log
 * n) runtime complexity.
 */
class Solution {
 public:
  int search(vector<int> nums, int target) {
    int start = 0, end = nums.size() - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(nums[mid] < target) start = mid + 1;
        else if(nums[mid] > target) end = mid - 1;
        else return mid;
    }
    return -1;
  }
};

int main(){
    Solution soln;
    assert(soln.search({0}, 0) == 0);
    assert(soln.search({-1,0,3,5,9,12}, 9) == 4);
    assert(soln.search({-1,0,3,5,9,12}, 2) == -1);
    std::cout<<"All tests passed";
}