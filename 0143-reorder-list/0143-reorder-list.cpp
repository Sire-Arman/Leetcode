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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev= NULL;
        ListNode* temp = head;
        while(temp){
            ListNode* next = temp ->next;
            temp ->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        int cnt =0;
        while(fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            cnt++;
            if(fast) {fast =fast->next;cnt++;}
        }
        prev->next = reverse(slow);
         // cout<<slow->val<<endl;
        slow = prev->next;
        ListNode* t1 = head;
        if(cnt&1)
        while(slow){
            ListNode* temp1 = t1->next;
            prev->next = slow->next;
            t1->next = slow;
            slow->next = temp1;
            t1 = temp1;
            slow = prev->next;
        }
        else{ 
            while(slow && slow->next){
            ListNode* temp1 = t1->next;
            prev->next = slow->next;
            t1->next = slow;
            slow->next = temp1;
            t1 = temp1;
            slow = prev->next;
        }
        }
    }
};