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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int n=0;
        while(temp){
            n++;
                temp =temp->next;
        }
        if(n<k){
            return head;
        }
           temp = head;
        ListNode* st = head;
        while(n>=k){
        stack<int> ans;
        int val = k;
        while(val--){
            ans.push(temp->val);
            temp = temp->next;
        }
        temp = st;
        while(!ans.empty()){
            temp->val = ans.top();
            ans.pop();
            temp = temp->next;
        }
            st = temp;
            n-=k;
        }
        return head;
    }
};