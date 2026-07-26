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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<>> pq;
        ListNode* list = new ListNode(INT_MIN);
        for(auto &it : lists){
            ListNode* t = it;
            while(t != NULL){
                pq.push(t->val);
                t=t->next;
            }
        }
        ListNode* res = NULL;
        while(!pq.empty()){
            if(list->val == INT_MIN){
                res = list;
                list->val = pq.top();
            }
            else{
                ListNode* t = new ListNode(pq.top());
                list->next = t;
                list = list->next;
            }
            pq.pop();
        }
        return res;
    }
};