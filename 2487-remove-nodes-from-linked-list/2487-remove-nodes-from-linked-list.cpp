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
    ListNode* reverse(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* rHEAD = reverse(head);
        ListNode* temp = rHEAD;
        int maxi = INT_MIN;
        while(temp != NULL){
            // cout<<temp->val<<' ';
            if(temp->val >= maxi){
                maxi = temp->val;
            }
            else{
                temp->val = -1;
            }
            temp = temp->next;
        }
        head = reverse(rHEAD);
        temp = NULL;
        ListNode* next = head;
        while(next != NULL){
            if(next->val == -1){
                if(temp == NULL) head = head->next;
                else temp->next = next->next;
            }
            else{
                temp = next;
            }
            next = next->next;
        }
        return head;
    }
};