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
    bool isPalindrome(ListNode* head) {
       
       int flag=0;
       stack<int>st;
       ListNode* cur=head;
       while(cur!=NULL){
           st.push(cur->val);
           cur=cur->next;
       }
       cur=head;
       while(cur!=NULL){
           if(cur->val!=st.top()){
               flag=1;
               break;
           }
           
           st.pop();
           cur=cur->next;
       }
       return !flag;
 



        // string str,st;
        // ListNode* cur=head;
        // while(cur!=NULL){
        //     str.push_back(cur->val+'0');
        //     cur=cur->next;
        // }
        // st=str;
        // reverse(str.begin(),str.end());
        // return st==str;

















        // int flag=0;
        // stack<int>s;
        // ListNode *curr=head;
        // while(curr!=NULL)
        // {
        //     s.push(curr->val);
        //     curr=curr->next;
        // }
        // curr=head;
        // while(curr!=NULL)
        // {
        //     int u=s.top();
        //     if(curr->val!=u)
        //         flag=1;
        //     s.pop();
        //     curr=curr->next;
        // }
        // if(flag==1)
        //     return false;
        // else
        //     return true;
    }
};
