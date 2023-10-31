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
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> mp;
        ListNode* temp = head;
        while(temp && !mp[temp]){
            mp[temp] = true;
            temp = temp->next;
        }
        if(temp == NULL){
            return false;
        }
        return true;
    }
};