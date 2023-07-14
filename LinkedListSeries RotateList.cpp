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
    // void rotate(vector<int>&result,int low,int high)
    // {
    //     while(low<high)
    //     {
    //         swap(result[low],result[high]);
    //         low++;
    //         high--;
    //     }
    // }
    // void traverse(ListNode**r,ListNode *p)
    // {
    //     if(p!=NULL)
    //     {
    //         p->next=(*r);
    //         (*r)=p;
    //     }
    // }
    // ListNode* rotateRight(ListNode* head, int k) {
    //     vector<int>result;
    //     if(head==NULL||k==0)
    //         return head;
    //     ListNode *curr=head;
    //     while(curr!=NULL)
    //     {
    //         result.push_back(curr->val);
    //         curr=curr->next;
    //     }
    //     int n=result.size();
    //     k=k%n;
    //     rotate(result,0,n-k-1);
    //     rotate(result,n-k,n-1);
    //     rotate(result,0,n-1);
    //     ListNode*r=NULL;
    //     for(int i=n-1;i>=0;i--){
    //         ListNode *p=new ListNode(result[i]);
    //         traverse(&r,p);
    //     }
    //     return r;
    // }

    
    //optimised apporach
     ListNode* rotateRight(ListNode* head, int k) {
         for(int i=0;i<k;i++){
             ListNode* cur=head;
             while(cur->next->next!=NULL){
                 cur=cur->next;
             }
             ListNode* end=cur->next;
             cur->next=NULL; //means 4 kai next mai null daldo
             end->next=head;
             head=end;
         }
         return head;
     }
};
