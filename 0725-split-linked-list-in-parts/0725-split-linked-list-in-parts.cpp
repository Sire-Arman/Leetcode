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
    int len(ListNode* head){
        int l = 0;
        if(head == NULL) return l;
        while(head != NULL){
            head = head->next;
            l++;
        }
        return l;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = len(head);
        int sec =0;
        int left =0;
        if(n%k == 0){
            sec = n/k;
        }
        else{
           sec = n/k+1;
            left = k-n%k;
        }
        ListNode* temp = head;
        vector<ListNode* > ans;
        while(temp != NULL){
            if(k == left){
                sec--;
            }
            int x = sec;
            ans.push_back(temp);
            while(--x){
                temp=temp->next;
            }
            ListNode* p = temp;
            temp = temp->next;
            p ->next = NULL;
            k--;
        }
        while(k--){
            ans.push_back(NULL);
        }
        return ans;
        
    }
};