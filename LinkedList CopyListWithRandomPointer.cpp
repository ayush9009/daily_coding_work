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
    //VVIP  QUESTION (Need Revision Also before going to coding round)
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        //First step
        while(temp!=NULL){
            Node *newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        //Second step
       Node* itr=head;
       while(itr!=NULL){
           if(itr->random!=NULL){
               itr->next->random=itr->random->next;
           }
           itr=itr->next->next;
       }
       //Third step
       Node* dummy=new Node(0);
       temp=dummy;
       itr=head;
       Node* fast;
       while(itr!=NULL){
           fast=itr->next->next;
           temp->next=itr->next;
           itr->next=fast;
           temp=temp->next;
           itr=fast;
       }
       return dummy->next;  //deep copy of 1 i.e 1'
    }
};
