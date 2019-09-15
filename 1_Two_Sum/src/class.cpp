#include "class.hpp"

#ifdef BRUTE_FORCE
vector<int> Solution::twoSum(vector<int>& nums, int target) {
    vector<int> r;
    int i, j;
    for(i=0; i<nums.size(); i++){
        for(j=0; j<nums.size(); j++){
            if(i==j) continue;
            int t = nums[i] + nums[j];
            if(t == target){
                r.push_back(i);
                r.push_back(j);
                return r;
            }
        }
    }
    return r;
}
#else
vector<int> Solution::twoSum(vector<int>& nums, int target) {
    vector<int> r;
    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); i++){
        m.insert(make_pair(nums[i], i));
    }
    for(int i=0; i<nums.size(); i++){
        int n = target - nums[i];
        auto p = m.find(n);
        if(p != m.end()){
            if(i != p->second){
                r.push_back(i);
                r.push_back(p->second);
                return r;
            }
        }
    }
    return r;
}
#endif
