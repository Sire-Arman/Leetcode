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
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode* head = l1;
        ListNode* travel = l1;
        int carry =0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val +carry;
            l1->val = sum%10;
            carry = sum/10;
            travel = l1;
            l1= l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            l1->val = sum%10;
            carry = sum/10;
            travel = l1;
            l1=l1->next;
        }
        while(l2 != NULL){
            int sum = l2->val + carry;
            int value = sum%10;
            carry = sum/10;
            ListNode* temp = new ListNode(value);
            travel->next = temp;
            temp->next = NULL;
            l1 = travel->next;
            travel = travel->next;
            l2=l2->next;
        }
        if(carry != 0){
             int sum = carry;
            ListNode* temp = new ListNode(sum);
           travel ->next = temp;
            temp->next = NULL;
            l1 = travel->next;
        }
        return head;
    }
};