#include "solution.hpp"

int Solution::myAtoi(string str){
    int ret = 0;
    int digit = 0;
    int sign = 0;
    int zero = 0;

    int max = INT_MAX;
    int max_digit = 0;
    int last_max = INT_MAX%10;
    int last_min = (INT_MIN%10)*-1;

    while(max > 10){
        max = max / 10;
        max_digit++;
    }
    max_digit++;

    /*
    cout << "INT_MIN: " << INT_MIN << "(" << max_digit << ")" <<
        " last: " << last_min << endl;
    cout << "INT_MAX: " << INT_MAX << "(" << max_digit << ")" <<
        " last: " << last_max << endl;
    */

    for(int i=0; i<str.size(); i++){
        // special case
        if(str[i] == ' '){
            if(digit == 0 && sign == 0 && zero == 0) continue;
            else break;
        }
        else if(str[i] == '+'){
            if(digit == 0 && sign == 0 && zero == 0){
                sign = 1;
                //cout << "[+] Val: " << str[i] << endl;
                continue;
            }
            else break;
        }
        else if(str[i] == '-'){
            if(digit == 0 && sign == 0 && zero == 0){
                sign = -1;
                //cout << "[-] Val: " << str[i] << endl;
                continue;
            }
            else break;
        }
        else if(str[i] == '0' && digit == 0){
            zero++;
            continue;
        }

        int val = str[i] - '0';
        if(val >=0 && val <= 9){
            if(digit == 0){
                if(sign == 0){
                    sign = 1;
                }
                ret = sign * val;
                //cout << "[f] Val: " << val << " Ret: " << ret << endl;
            }
            else{
                if(sign == 1){
                    if(digit == max_digit){
                        ret = INT_MAX;
                        /*
                        cout << "[s] Val: " << val << " Ret: " << ret <<
                            "(overflow)" << endl;
                        */
                        break;
                    }
                    else if(digit == max_digit - 1){
                        if(ret > INT_MAX/10){
                            ret = INT_MAX;
                            /*
                            cout << "[s] Val: " << val << " Ret: " << ret <<
                                "(overflow)" << endl;
                            */
                            break;
                        }
                        else if(ret == INT_MAX/10 && val > last_max){
                            ret = INT_MAX;
                            /*
                            cout << "[s] Val: " << val << " Ret: " << ret <<
                                "(overflow)" << endl;
                            */
                            break;
                        }
                    }
                    ret = ret*10 + val;
                    //cout << "[s] Val: " << val << " Ret: " << ret << endl;
                }
                else{
                    if(digit == max_digit){
                        ret = INT_MIN;
                        /*
                        cout << "[s] Val: " << val << " Ret: " << ret <<
                            "(overflow)" << endl;
                        */
                        break;
                    }
                    else if(digit == max_digit - 1){
                        if(ret < INT_MIN/10){
                            ret = INT_MIN;
                            /*
                            cout << "[s] Val: " << val << " Ret: " << ret <<
                                "(overflow)" << endl;
                            */
                            break;
                        }
                        else if(ret == INT_MIN/10 && val > last_min){
                            ret = INT_MIN;
                            /*
                            cout << "[s] Val: " << val << " Ret: " << ret <<
                                "(overflow)" << endl;
                            */
                            break;
                        }
                    }
                    ret = ret*10 - val;
                    //cout << "[n] Val: " << val << " Ret: " << ret << endl;
                }
            }
            digit++;
        }
        else{
            break;
        }
    }
    return ret;
}
