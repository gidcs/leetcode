#include "solution.hpp"

int Solution::lengthOfLongestSubstring(string s){
    int max = 0;
    int cnt = 0;
    string str_m = "";
    vector<int> check;
    check.resize(128);

    for(int i=0; i<check.size(); i++){
        check[i] = -1;
    }

    int p = 0; //start pointer to the current string
    for(int i=0; i<s.length(); i++){
        if(check[s[i]] < p){ //i does not exist
            //cout << "n ";
            check[s[i]]=i;
            cnt++;
        }
        else{ //i exists
            //cout << "y ";
            if(cnt > max){ //save last string
                max = cnt;
                str_m = s.substr(p, cnt);
            }
            int last_i = check[s[i]]; //get index of last i
            //start from next char of last i
            if(last_i + 1 < i){ 
                p = last_i + 1;
                cnt = (i-1)-(last_i+1)+1;
            }
            else{ //last_i + 1 == i
                p = i;
                cnt = 0;
            }
            check[s[i]] = i;
            cnt++;
        }
        //cout << i << "-> p: " << p << " str_c: " << s.substr(p, cnt) << " length: " << cnt << endl;
    }
    if(cnt > max){ //save last string
        max = cnt;
        str_m = s.substr(p, cnt);
    }
    //cout << "str_m: " << str_m << " max: " << max << endl;
    return max;
}
