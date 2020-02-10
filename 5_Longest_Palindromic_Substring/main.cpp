#include <iostream>
#include <vector>
#include "src/solution.hpp"

using namespace std;

int main(){
    Solution s;

    vector<string> input;
    vector<string> ans;

    input.push_back("bab");
    input.push_back("baaaab");
    input.push_back("babad");
    input.push_back("cbbd");
    input.push_back("1881");
    input.push_back("1298188189210");
    input.push_back("adam");
    input.push_back("zzzzzzzadam");
    input.push_back("zxcdfvgadam");
    input.push_back("babadada");
    input.push_back("ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy");
    ans.push_back("bab");
    ans.push_back("baaaab");
    ans.push_back("bab");
    ans.push_back("bb");
    ans.push_back("1881");
    ans.push_back("129818818921");
    ans.push_back("ada");
    ans.push_back("zzzzzzz");
    ans.push_back("ada");
    ans.push_back("adada");
    ans.push_back("fklkf");
    
    for(int i=0; i<ans.size(); i++){
        cout << "input: " << input[i] << endl;
        string output = s.longestPalindrome(input[i]);
        cout << "output: " << output << endl;
        cout << "ans: " << ans[i] << endl;
        cout << endl;
    }
}
