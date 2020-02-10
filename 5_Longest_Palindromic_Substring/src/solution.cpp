#include "solution.hpp"

#define DP_Smart

#ifdef DP_Smart
string Solution::longestPalindrome(string s){
    if(s.size() < 1){
        return "";
    }

    int max = 0;
    int max_i;

    for(int i=0; i<s.size(); i++){
        int p, q, value;
        { //case i, i
            p = i;
            q = i;
            value = 1;
            if(value > max){
                max_i = p;
                max = value;
            }
            while(--p >= 0 && ++q < s.size()){ // expand
                if(s[p] == s[q]){
                    value += 2;
                }
                else{
                    break;
                }
            }
            if(value > max){
                max_i = p+1;
                max = value;
            } 
        }
        { // case i, i+1
            p = i;
            q = i+1;
            if(q>s.size()) break; // reach end

            if(s[p] == s[q]){
                value = 2;
                if(value > max){
                    max_i = p;
                    max = value;
                }
                while(--p >= 0 && ++q < s.size()){ // expand
                    if(s[p] == s[q]){
                        value += 2;
                    }
                    else{
                        break;
                    }
                }
            }
            if(value > max){
                max_i = p+1;
                max = value;
            } 
        }
    }
    return s.substr(max_i, max);
}
#endif

#ifdef DP_Slow
string Solution::longestPalindrome(string s){
    if(s.size() < 1){
        return "";
    }

    int max = 0;
    int max_i, max_j;
    vector<vector<int>> dict;
    dict.resize(s.size());

    //init
    for(int i=0; i<s.size(); i++){
        dict[i].resize(s.size());
        for(int j=0; j<s.size(); j++){
            dict[i][j] = -1;
        }
    }

    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s.size(); j++){
            if(i > j) continue;
            int p, q, value;
            if(i==j){
                value = 1;
                dict[i][j] = value;
                p = i;
                q = j;
                while(--p >= 0 && ++q < s.size()){ // expand
                    if(value !=0 && s[p] == s[q]){
                        value += 2;
                    }
                    else{
                        value = 0;
                    }
                    dict[p][q] = value;
                }
            }
            else if(abs(i-j)==1){
                if(s[i] == s[j]){
                    value = 2;
                    dict[i][j] = value;
                    p = i;
                    q = j;
                    while(--p >= 0 && ++q < s.size()){ // expand
                        if(value !=0 && s[p] == s[q]){
                            value += 2;
                        }
                        else{
                            value = 0;
                        }
                        dict[p][q] = value;
                    }
                }
                else{
                    value = 0;
                    dict[i][j] = value;
                    p = i;
                    q = j;
                    while(--p >= 0 && ++q < s.size()){ // expand
                        dict[p][q] = value;
                    }
                }
            }
            else{ // expand will do the others
                continue;
            }
        }
    }
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s.size(); j++){
            if(i > j) continue;
            if(dict[i][j] > max){
                max_i = i;
                max_j = j;
                max = dict[i][j];
            }
            //cout << "dict[" << i << "][" << j << "]: " << dict[i][j] << endl;
        }
    }
    //cout << "max_i: " << max_i << " max_j:" << max_j << " max: " << max << endl;
    return s.substr(max_i, max);
}
#endif

#ifdef DP_Func
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
#endif
