/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode(0);
        ListNode * cur = dummy;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr ||carry!= 0){
            int x, y;
            if(l1 != nullptr){
                x= l1 -> val;
            }
            else x = 0;

            if(l2 != nullptr){
                y= l2 -> val;
            }
            else y = 0;

            int sum = x+ y+ carry;

            int digit = sum %10;
            carry = sum / 10;

            cur-> next = new ListNode(digit);
            cur = cur -> next;

            if(l1 != nullptr){
                l1= l1-> next;
            } 
            if(l2 != nullptr){
                l2= l2-> next;
            } 
        }
        return dummy-> next;
    }
};
