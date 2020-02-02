#include "solution.hpp"

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    double median = 0;
    double temp;
    int num_of_median = 1;
    int total = nums1.size() + nums2.size();
    int q = (total+1)/2;
    if(total%2 == 0){
        num_of_median = 2;
        q++;
    }

    //cout << "[d] num_of_median: " << num_of_median << endl;
    //cout << "[d] q: " << q << endl;
    
    int i=0, j=0, k=0;
    while(k<q){
        double p;
        if(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                p = nums1[i];
                i++;
            }
            else{
                p = nums2[j];
                j++;
            }
        }
        else if(i == nums1.size() && j < nums2.size()){
            p = nums2[j];
            j++;
        }
        else if(i < nums1.size() && j == nums2.size()){
            p = nums1[i];
            i++;
        }
        else{
            cout << "bug!!!" << endl;
        }
        //cout << "[k] " << k << ": " << p << endl;
        k++;
        if(k == q - 1){
            if(num_of_median == 2){
                temp = p;
            }
        }
        else if(k == q){
            if(num_of_median == 1){
                median = p;
            }
            else{
                median = (temp + p) / 2;
            }
        }
    }
    return median;
}
