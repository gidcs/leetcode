#include <iostream>
#include <vector>
#include "src/solution.hpp"

using namespace std;

int main(){
    Solution s;

    vector<vector<int>> nums1;
    vector<vector<int>> nums2;

    nums1.resize(2);
    nums2.resize(2);

    // nums1 = [1, 3]
    // nums2 = [2]
    nums1[0].push_back(1);
    nums1[0].push_back(3);
    nums2[0].push_back(2);

    // nums1 = [1, 2]
    // nums2 = [3, 4]
    nums1[1].push_back(1);
    nums1[1].push_back(2);
    nums2[1].push_back(3);
    nums2[1].push_back(4);
    
    vector<double> ans = { 2.0, 2.5 };
    
    for(int i=0; i<ans.size(); i++){
        cout << "nums1: [";
        for(int j=0; j<nums1[i].size(); j++){
            cout << nums1[i][j];
            if(j != nums1[i].size() - 1){
                cout << ",";
            }
        }
        cout << "]" << endl;
        cout << "nums2: [";
        for(int j=0; j<nums2[i].size(); j++){
            cout << nums2[i][j];
            if(j != nums2[i].size() - 1){
                cout << ",";
            }
        }
        cout << "]" << endl;

        double output = s.findMedianSortedArrays(nums1[i], nums2[i]);
        cout << "The median is " << output << "(" << ans[i] << ")" << endl;
        cout << endl;
    }
}
