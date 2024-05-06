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
//     reverse LL and return new head
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
//     Remove Nodes
    ListNode* remove(ListNode* head){
        ListNode* temp = NULL;
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
    
    
    ListNode* removeNodes(ListNode* head) {
//         rHEAD - reversed LL head pointer
        ListNode* rHEAD = reverse(head);
        ListNode* temp = rHEAD;
//         Compare val with previous max and check if they are to be removed or not
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
//         Now reverse the LL again and remove all marked nodes
        head = reverse(rHEAD);
//         remove elements
        return remove(head);
    }
};