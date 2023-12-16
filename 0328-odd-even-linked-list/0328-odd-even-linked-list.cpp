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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int cnt =0;
        ListNode* evenh = NULL;
        ListNode* even = NULL;
        ListNode* odd = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            if(odd==NULL){
                odd = temp;
            }
            else if(cnt%2 != 0){
                odd->next = temp;
                odd=odd->next;
            }
            else if(even == NULL){
                even = temp;
                evenh = even;
            } 
            else{
                even->next = temp;
                even = even->next;
            }
            temp = temp->next;
        }
        even->next = NULL;
       odd->next = evenh; 
        return head;
    }
};