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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp ->next;
        }
        for(int i=0;i<v.size();i++){
            int j =i;
            while(j && v[j]<v[j-1]){
                swap(v[j],v[j-1]);
                j--;
            }
        }
        temp = head;
        for(auto it : v){
            temp->val = it;
            temp = temp->next;
        }
        return head;
    }
};