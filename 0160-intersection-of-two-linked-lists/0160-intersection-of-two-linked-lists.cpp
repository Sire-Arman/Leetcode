/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int Length(ListNode* head){
        int len =0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int A =Length(headA),B=Length(headB);
        if(A>B){
            while(A>B){
                headA = headA->next;
                A--;
            }
        }
        else{
            while(B>A){
                headB = headB->next;
                B--;
            }  
        }
        while(A && B){
            if(headA == headB){
                return headA;
            }
            headB= headB->next;
            headA= headA->next;
        }
        return NULL;
    }
};