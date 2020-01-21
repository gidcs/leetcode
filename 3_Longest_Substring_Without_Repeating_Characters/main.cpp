#include <iostream>
#include <string>
#include <vector>
#include "src/solution.hpp"

using namespace std;

int main(){
    Solution s;
    vector<string> inputs = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "Aabuydawa",
        "TESTAWE",
        "dvdf",
        "abba"
    };
    vector<int> ans = {
        3,
        1,
        3,
        6,
        5,
        3,
        2
    };
    for(int i=0; i<inputs.size(); i++){
        cout << "input: " << inputs[i] << endl;
        int output = s.lengthOfLongestSubstring(inputs[i]);
        cout << "output: " << output << "(" << ans[i] << ")" << endl;
        cout << endl;
    }
}
