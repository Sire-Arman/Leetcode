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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* nhead = new ListNode(0);
        ListNode* temp = head;
        ListNode* ntemp = nhead;
        queue<int> st;
        while(temp != NULL){
            if(temp->val == 0){
                int sum =0;
                while(!st.empty()){
                    sum += st.front();
                    st.pop();
                }
                if(sum){
                    ListNode* t = new ListNode(sum);
                    ntemp->next = t;
                    ntemp = ntemp->next;
                }
            }
            else{
                st.push(temp->val);
            }
            temp = temp->next;
        }
        while(!st.empty()){
             ListNode* t = new ListNode(st.front());
                    ntemp->next = t;
                    ntemp = ntemp->next;
            st.pop();
        }
        return nhead->next;
    }
};