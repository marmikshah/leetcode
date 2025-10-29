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

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    //
    long long start = 0, end = n;
    while (start <= end) {
      long long mid = (start + end) / 2;
      if (isBadVersion(mid)) {
        if (isBadVersion(mid - 1)) {
          end = mid - 1;
        } else {
          return mid;
        }
      } else {
        start = mid + 1;
      }
    }
    return -1;
  }
};

// Cannot mock as isBasVersion definition is not available.