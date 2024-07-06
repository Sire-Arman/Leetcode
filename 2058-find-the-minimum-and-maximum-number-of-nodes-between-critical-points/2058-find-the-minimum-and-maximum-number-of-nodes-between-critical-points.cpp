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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=1,f = -1, l = -1;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int mini = INT_MAX;
        while(temp ->next != NULL){
            if(prev == NULL){
                prev = temp;
                temp = temp ->next;
                i++;
                continue;
            }
            if(temp ->val < prev->val && temp ->val < temp->next->val){
                if(f == -1){
                    f = i;
                }
                if(l != -1) mini = min(mini, i-l);
                    l =i;
            }
            else if (temp ->val > prev->val && temp ->val > temp->next->val){
                if(f == -1){
                    f = i;
                }
                if(l != -1 ) mini = min(mini,i-l);
                l=i;
            }
            i++;
            prev = temp;
            temp = temp->next;
        }
        if(l==f || mini == INT_MAX) return {-1,-1};
        return {mini, l-f};
    }
};