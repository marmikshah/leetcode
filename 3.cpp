#include <assert.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * ref:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * Problem Statement
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 */

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int start = 0, end = 0;
    unordered_map<char, int> cache;
    for (int i = 0; i < (int)s.size(); i++) {
      char c = s.at(i);
      // Building cache
      if (cache.find(c) == cache.end()) {
        cache[c] = i;
      }

      if (cache[c] != i) {
        if (!(c != s.at(start) && cache[c] < start)) {
          start = cache[c] + 1;
        }
        cache[c] = i;
      }
      end = i;
      maxLen = max(maxLen, end + 1 - start);
    }
    return max(maxLen, end - start);
  }
};

int main() {
  Solution sol;
  /**
   * s=0,e=0, {a:1, }, maxLen = 0
   * s=0,e=1, {a:0, b=1}, maxLen = 1
   * s=0,e=2, {a:0, b:1,c:2}, maxLen = 2
   * a exists, reset
   * s=1, e=3 {a:3, b:1,c:2}, maxLen = 2
   */

  unordered_map<std::string, int> tests;
  tests["abcabcbb"] = 3;
  tests["bbbbb"] = 1;
  tests["pwwkew"] = 3;
  tests["abcdeffghasasuiqwasoindauuiq[as[asj#3%$as"] = 8;
  tests["!@#sda 12342wef sdf l234p987 23d 2 "] = 12;
  tests["the quick brown fox jumps over the laxy dog"] = 11;

  for (auto const& [input, output] : tests) {
    assert(sol.lengthOfLongestSubstring(input) == output);
  }

  std::cout << "All tests passed" << std::endl;
}