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
    ListNode* removeZeroSumSublists(ListNode* head) {
       ListNode* curr = head;
        ListNode* prev = NULL;
        bool flag = false;
        while(curr != NULL){
            flag = false;
            ListNode* temp = curr;
            long long sum =0;
            while(temp != NULL){
                sum += temp->val;
                // cout<<sum<<' ';
                if(sum == 0){
                    flag = true;
                    if(curr == head){
                        head = temp->next;
                        prev = head;
                        curr = temp->next;
                        break;
                    }
                    else{
                        prev->next = temp->next;
                        curr = temp->next;
                        break;
                    }
                    
                }
                temp = temp->next;
            }
            // cout<<endl;
            if(curr == NULL) break;
            if(!flag){
                prev = curr;
                curr = curr->next;   
            }
        }
        return head;
    }
};