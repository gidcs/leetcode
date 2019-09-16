#include <iostream>
#include <vector>
#include "src/class.hpp"

using namespace std;

int main(){
    Solution s;
    vector<vector<int>> nums = {{2, 4, 3}, {5, 6, 4}, {9, 2, 8}, {2, 8, 2},
                                {}, {1, 2, 3}, {1, 3, 3}, {9},
                                {1, 2}, {9, 9, 9}
                                };
    for(int i=0; i<nums.size()-1; i++){
        ListNode *l1 = new ListNode(0), *l2 = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2;

        //ListNode initialization
        for(int k=0; k<nums[i].size(); k++){
            p1->next = new ListNode(nums[i][k]);
            p1 = p1->next;
        }
        for(int k=0; k<nums[i+1].size(); k++){
            p2->next = new ListNode(nums[i+1][k]);
            p2 = p2->next;
        }

        //print input
        cout << "[input] ";
        cout << "(";
        p1 = l1->next;
        while(p1){
            cout << p1->val;
            if(p1->next != NULL){
                cout << " -> ";
            }
            p1 = p1->next;
        }
        cout << ") + (";
        p2 = l2->next;
        while(p2){
            cout << p2->val;
            if(p2->next != NULL){
                cout << " -> ";
            }
            p2 = p2->next;
        }
        cout << ")" << endl;

        //add two numbers
        ListNode *r = s.addTwoNumbers(l1->next, l2->next);
        
        //print output
        cout << "[output] ";
        while(r){
            cout << r->val;
            if(r->next != NULL){
                cout << " -> ";
            }
            r = r->next;
        }
        cout << endl;
        cout << endl;

        //cleanup
        while(p1){
            ListNode *t = p1;
            p1 = p1->next;
            delete t;
        }
        while(p2){
            ListNode *t = p2;
            p2 = p2->next;
            delete t;
        }
        while(r){
            ListNode *t = r;
            r = r->next;
            delete r;
        }
    }
}
