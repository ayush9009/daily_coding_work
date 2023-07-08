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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode *curr=new ListNode(0);
        // cout<<curr->val;
        
        // ListNode *root{curr};
        // cout<<root->val<<endl;
        // while(list1&&list2)
        // {
        //     if(list1->val<=list2->val)
        //     {
        //         curr->next=list1;
        //         list1=list1->next;
        //     }
        //     else{
        //         curr->next=list2;
        //         list2=list2->next;
        //     }
        //     curr=curr->next;
        // }
        // cout<<endl;
        // cout<<curr->val<<endl;
        // cout<<root->val;
        // if(list1)
        //     curr->next=list1;
        // else
        //     curr->next=list2;
        // return root->next;

        ListNode* cur=new ListNode(0);
        // cur=cur->next;
        ListNode* start=cur;
        while(list1 && list2){
            if(list1->val <= list2->val){
                cur->next=list1;
                list1=list1->next;
            }
            else{
                cur->next=list2;
                list2=list2->next;
            }
            cur=cur->next;
        }
        if(list1)cur->next=list1;
        if(list2)cur->next=list2;
        return start->next;
    }
};
