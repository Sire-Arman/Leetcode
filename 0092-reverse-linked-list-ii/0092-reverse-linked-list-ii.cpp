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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        stack<int> st;
        int cnt=1;
        ListNode* temp = head;
        while(cnt <left){
            temp = temp->next;
            cnt++;
        }
        ListNode* two = temp;
        while(cnt<=right){
            st.push(temp->val);
            temp=temp->next;
            cnt++;
        }
        while(!st.empty()){
            two->val = st.top();
            st.pop();
            two = two->next;
        }
        return head;
    }
};