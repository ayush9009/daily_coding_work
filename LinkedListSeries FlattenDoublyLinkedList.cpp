/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
   vector<int>result;
    void helper(Node* head){
        Node* cur=head;
        if(cur==NULL)return;
        if(cur->next== NULL && cur->child==NULL){
            result.push_back(cur->val);
            return;
        }
        while(cur!=NULL){
            result.push_back(cur->val);
            if(cur->child!=NULL)helper(cur->child);
            cur=cur->next;
        }
    }
    Node* flatten(Node* head) {
        helper(head);
        for(auto it:result)cout<<it<<" ";
        Node* r=NULL,*temp=NULL;
        for(int i=0;i<result.size();i++){
            if(r==NULL){
                r=new Node(result[i]);
                r->prev=NULL;
                r->child=NULL;
                temp=r;
            }else{
                Node* newNode=new Node(result[i]);
                temp->next=newNode;
                newNode->prev=temp;
                temp=temp->next;
                temp->child=NULL;
            }
        }
        return r;
    }
};
