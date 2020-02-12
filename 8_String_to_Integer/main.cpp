#include <iostream>
#include <vector>
#include "src/solution.hpp"

using namespace std;

int main(){
    Solution s;

    vector<string> input_s;
    vector<int> ans;

    input_s.push_back("42");
    input_s.push_back("   -42");
    input_s.push_back("4193 with words");
    input_s.push_back("words and 987");
    input_s.push_back("-91283472332");
    input_s.push_back("-2147483649");
    input_s.push_back("-2147483648");
    input_s.push_back("2147483647");
    input_s.push_back("2147483648");
    input_s.push_back("12147483648");
    input_s.push_back("- 12147483648");
    input_s.push_back("3.14159");
    input_s.push_back("+1");
    input_s.push_back("+ 1");
    input_s.push_back("-+1");
    input_s.push_back("  0000000000012345678");
    input_s.push_back("  -0000000000012345678");
    input_s.push_back("- 0000000000012345678");
    input_s.push_back("0-1");
    ans.push_back(42);
    ans.push_back(-42);
    ans.push_back(4193);
    ans.push_back(0);
    ans.push_back(-2147483648);
    ans.push_back(-2147483648);
    ans.push_back(-2147483648);
    ans.push_back(2147483647);
    ans.push_back(2147483647);
    ans.push_back(2147483647);
    ans.push_back(0);
    ans.push_back(3);
    ans.push_back(1);
    ans.push_back(0);
    ans.push_back(0);
    ans.push_back(12345678);
    ans.push_back(-12345678);
    ans.push_back(0);
    ans.push_back(0);
    
    for(int i=0; i<ans.size(); i++){
        cout << "input: " << input_s[i] << endl;
        int output = s.myAtoi(input_s[i]);
        cout << "output: " << output << endl;
        cout << "ans: " << ans[i] << endl;
        cout << endl;
    }
}
