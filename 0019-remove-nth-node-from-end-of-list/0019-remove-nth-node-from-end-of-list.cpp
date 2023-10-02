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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =0;
        if(head == NULL){
            return NULL;
        }
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        count -= n;
        if(count == 0){
            return head->next;
        }
        temp = head;
        while(--count){
            temp = temp->next;
        }
        ListNode* t= temp->next;
        temp ->next = t->next;
        delete(t);
        return head;
        
    }
};