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
ListNode* detectLoop(ListNode* head){
    if(head == NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!= NULL && slow!= NULL){
        fast=fast->next;
    if(fast != NULL){
        fast = fast->next;
    }
    slow = slow->next;
    if(slow == fast){
        return slow;
    }
    }
    return NULL;

}
ListNode* firstNode(ListNode* head)
{
    if(head == NULL){
        return NULL;
    }
   ListNode* intersection = detectLoop(head);
   if(intersection == NULL){
       return NULL;
   }
    ListNode* slow = head;
while(slow != intersection){
    slow = slow->next;
    intersection = intersection->next;
}
return slow;

}
ListNode* detectCycle(ListNode* head)
{
    if(head == NULL){
        return NULL;
    }
    ListNode* start = firstNode(head);
    if(start == NULL){
        return NULL;
    }
   
    return start ;
    
}
};