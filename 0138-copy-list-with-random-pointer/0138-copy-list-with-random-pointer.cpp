/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node* head2 = NULL;  
        if(head == NULL){
            return head2;
        }
        
        map<Node* , int> nodeTopos;
        map<int, Node* > posTonode;
        
        int cnt=0;
        
        Node* head1 = head;
        Node* temp1 = head2;
        while(head1){
            int val = head1->val;
            Node* temp = new Node(val);
            cnt++;
            nodeTopos[head1] = cnt;
            head1=head1->next;
            if(cnt ==1){
                head2 = temp;
                temp1 = temp;
            }
            else{
            temp1->next = temp;
            temp1 = temp1->next;  
            }
            posTonode[cnt] = temp; 
            
        }
        head1 = head;
        temp1 = head2;
        while(head1 && temp1){
            if(head1->random == NULL){
                temp1->random = NULL;
            }
            else{
            int pos = nodeTopos[head1->random];
            Node* rand = posTonode[pos];
            temp1->random = rand;
            }
            
            head1 = head1->next;
            temp1 = temp1->next;
        }
        return head2;
    }
};