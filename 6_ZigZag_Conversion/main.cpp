#include <iostream>
#include <vector>
#include "src/solution.hpp"

using namespace std;

int main(){
    Solution s;

    vector<string> input_s;
    vector<int> input_n;
    vector<string> ans;

    input_s.push_back("PAYPALISHIRING");
    input_n.push_back(3);
    input_s.push_back("PAYPALISHIRING");
    input_n.push_back(4);
    input_s.push_back("AB");
    input_n.push_back(1);
    input_s.push_back("ABAB");
    input_n.push_back(2);
    ans.push_back("PAHNAPLSIIGYIR");
    ans.push_back("PINALSIGYAHRPI");
    ans.push_back("AB");
    ans.push_back("AABB");
    
    for(int i=0; i<ans.size(); i++){
        cout << "input: " << input_s[i] << " " << input_n[i] << endl;
        string output = s.convert(input_s[i], input_n[i]);
        cout << "output: " << output << endl;
        cout << "ans: " << ans[i] << endl;
        cout << endl;
    }
}
