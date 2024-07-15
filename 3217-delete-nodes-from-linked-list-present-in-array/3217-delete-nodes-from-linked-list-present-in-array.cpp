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
    void deleteNode(ListNode* node,ListNode* prev, ListNode* head) {
        if(node == head){
            head = head->next;
            ListNode* x = node;
            node = node->next;
            // return;
            delete x;
        }
        else{
            prev->next = node->next;
            cout<<node->val<<' ';
            ListNode* x = node;
            node = prev->next;
            delete x;
        }
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head == NULL) return NULL;
        map<int,bool> mp;
        for(auto it : nums) mp[it] = true;
        ListNode* temp = head;
        ListNode* prev = NULL;
        // bool update = true;
        while(temp != NULL){
            // update = true;
            if(mp[temp->val]){
                if(temp == head){
                    head = head->next;
                    temp = temp->next;
                }
                else{
                    prev->next = temp->next;
                    ListNode* h = temp;
                    temp = prev->next;
                    delete h;
                }
            }
            else{
                prev = temp;
                temp = temp ->next;
            }
        }
        return head;
    }
};