#include <iostream>
#include <string>
#include <vector>
#include "src/class.hpp"

using namespace std;

int main(){
    Solution s;
    //vector<int> nums = {2, 7, 11, 15};
    //int t = 9;
    vector<vector<int>> nums = {{2, 7, 11, 15}, {3, 2, 4}};
    vector<int> target = {9, 6};
    for(int i=0; i<nums.size(); i++){
        cout << "[input] nums: {";
        for(int j=0; j<nums[i].size(); j++){
            cout << nums[i][j];
            if(j != nums[i].size() - 1){
                cout << ", ";
            }
        }
        cout << "}, target: " << target[i] << endl;
        vector<int> r = s.twoSum(nums[i], target[i]);
        cout << "[output] ans: {" << r[0] << ", " << r[1] << "}" << endl;
        cout << endl;
    }
}
