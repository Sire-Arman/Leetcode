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
     ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp){
            ListNode* next = temp ->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast){
            slow = slow ->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        fast = head;
        slow = reverse(slow);
        while(slow){
            if(fast->val != slow ->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};