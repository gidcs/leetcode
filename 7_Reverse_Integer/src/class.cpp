#include "class.hpp"

int Solution::reverse(int x) {
    int ret = 0;
    int q, r;
    q = x;
    while(q){
        r = q % 10;
        q = q / 10;
        if((ret > INT_MAX/10) || 
            (ret == INT_MAX/10 && r > INT_MAX%10) ||
            (ret < INT_MIN/10) ||
            (ret == INT_MIN/10 && r < INT_MIN%10)
        ){
            ret = 0;
            //cout << "overflow !!!" << endl;
            break;
        }
        ret = ret * 10 + r;
        //cout << "q = " << q << ", r = " << r << ", ret = " << ret << endl;
    }
    return ret;
}
