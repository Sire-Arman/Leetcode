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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        k= k%cnt;
        int val = 0;
        while(k--){
            temp = head;
            val=temp->val;
            while(temp->next){
                int t = temp->next->val;
                temp->next->val = val;
                 val = t;
                temp = temp->next;
            }
            head->val = val;    
        }
        return head;
    }
};