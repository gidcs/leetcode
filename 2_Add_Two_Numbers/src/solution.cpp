#include "solution.hpp"

ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode *ret = new ListNode(0);
    ListNode *rp = ret;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    int carry = 0;

    while(p1 != NULL || p2 != NULL){
        int x = (p1 == NULL) ? 0 : p1->val;
        int y = (p2 == NULL) ? 0 : p2->val;
        int sum = x + y + carry;
        //cout << x << " + " << y << " + " << carry << " = ";
        carry = sum / 10;
        sum = sum % 10;
        rp->next = new ListNode(sum);
        rp = rp->next;
        //cout << rp->val << "(carry:"<< carry << ")" << endl;
        if(p1 != NULL) p1 = p1->next;
        if(p2 != NULL) p2 = p2->next;
    }

    if(carry){
        rp->next = new ListNode(carry);
        rp = rp->next;
    }

    return ret->next;
}
