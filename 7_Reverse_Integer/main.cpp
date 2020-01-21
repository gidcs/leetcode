#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "src/solution.hpp"

using namespace std;

int main(){
    Solution s;
    vector<int> nums = {123, -123, 120, INT_MIN, INT_MAX};
    for(auto &x: nums){
        cout << "[input] " << x << endl;
        int r = s.reverse(x);
        cout << "[output] " << r << endl;
        cout << endl;
    }
}
