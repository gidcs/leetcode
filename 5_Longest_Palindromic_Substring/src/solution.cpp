#include "solution.hpp"

int expandFromCenter(string &s, int l, int r){
    //cout << "[init] " << s << " " << l << " " << r << endl;
    while(l >=0 && r < s.size()){
        if(s[l] == s[r]){
            l--;
            r++;
        }
        else{
            break;
        }
    }
    l++; r--;
    //cout << "[final] start: " << l << " end: " << r << endl;
    if(r>=l){
        //cout << "[finaln] " << s << " " << (r-l)+1 << endl;
        return (r-l)+1;
    }
    else{
        //cout << "[finalz] " << s << " " << 0 << endl;
        return 0;
    }
}

string Solution::longestPalindrome(string s){
    if(s.size() < 1){
        return "";
    }

    int start=0;
    int end=0;
    for(int k=0; k<s.size(); k++){
        int len1=expandFromCenter(s, k, k); //odd
        int len2=expandFromCenter(s, k, k+1); //even
        if(len1 > len2){ //odd
            if(len1 > end-start+1){ //assume zbabc k=2, len=3
                start = k - len1/2; //start=2-1=1
                end = k + len1/2;   //end=2+1=3
                //cout << "[o] start: " << start << " end: " << end << endl;
            }
        }
        else{ //even
            if(len2 > end-start+1){ //assume baaaab k=2, k+1=3, len2=6
                start = k - len2/2 + 1; //start=2-3+1=0
                end = k+1 + len2/2 - 1; //end=3+3-1=5
                //cout << "[e] start: " << start << " end: " << end << endl;
            }
        }
    }
    return s.substr(start, end-start+1);
}
