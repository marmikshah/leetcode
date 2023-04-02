#include "common.hpp"

using namespace std;

unordered_set<char> _invalid({'7', '8', '9'});
// ref: https://leetcode.com/problems/decode-ways/

class Solution {
public:

    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        // To submit on LC, set int dp[101] = {0};
        int dp[s.length()] = {0};
        dp[s.length()] = 1;

        for(int i=s.length() - 1;i>=0;--i) {
            if (s[i] == '0') dp[i] = 0;
            else {
                dp[i] = dp[i + 1];
                if(i < s.length() - 1) {
                    if (s[i] == '1') dp[i] += dp[i+2];
                    if (s[i] == '2' && _invalid.find(s[i+1]) ==_invalid.end()) dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }

};

struct TestCase {
    string input;
    int expectedOutput;

    TestCase(string input, int expectedOutput) {
        this->input = input;
        this->expectedOutput = expectedOutput;
    }
    bool didPassTest(Solution *sol){ 
    
        int output = sol->numDecodings(input);
        std::cout<<"Case: "<<this->input<<", "<<this->expectedOutput<<" => "<< output<<endl;
        return output == expectedOutput;
    
    }
};

int main() {
    Solution *sol;
    TestCase cases[] = {
        TestCase("12", 2),
        TestCase("12121", 8),
        TestCase("00000010101010101010100000000001", 0),
        TestCase("1010101010101011", 2),
        TestCase("226", 3)
    };
    for(auto _case: cases) {
        assert(_case.didPassTest(sol));
    }
    cout<<"All tests passed";
    return 0;
}