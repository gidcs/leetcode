#include "solution.hpp"

string Solution::convert(string s, int numRows){
    string output = "";
    vector<string> zigzag;
    for(int i=0; i<numRows; i++){
        zigzag.push_back("");
    }
    int i = 0;
    int k = 0;
    while(i<s.size()){
        zigzag[k] += s[i++];
        //cout << "k:" << k << " i:" << i << endl;
        k++;
        if(k == numRows){
            --k;
            //cout << "Reach End" << endl;
            while(i<s.size() && --k > 0){
                zigzag[k] += s[i++];
                //cout << "[i]k:" << k << " i:" << i << endl;
            }
            if(k < 0){
                k = 0;
            }
        }
    }
    for(int i=0; i<zigzag.size(); i++){
        output += zigzag[i];
    }
    return output;
}
