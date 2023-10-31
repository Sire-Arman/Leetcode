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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        stack<int> ans;
        ListNode* temp = head;
        while(temp){
            ans.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(!ans.empty()){
            if(ans.top()!= temp->val){
                return false;
            }
            ans.pop();
            temp = temp->next;
        }
        return true;
    }
};