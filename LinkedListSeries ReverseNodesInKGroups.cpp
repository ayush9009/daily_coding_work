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
//BADiya question isme reverse to hum kar hi rahe,sath sath linked list concept lag
// ra badiya vale
12345 k=2
if suppose cnt=2 k=5 to kaise 5 kai grp mai reverse karoge ,isliye return head
12345 k=2
to pahle 21 hoga then 43 aur 5 to 5 kuki cnt<k(i.e 1<2)
21 karna easy h aapke liye,
head=1 reverse hoke 21 hogya to aap chate ho 21->next=3,to vo hi to kara head->next=3
return prev yani 2 to 2->1 to ab 1 tohdey return karogey 2 karogey 
    ListNode* reverseKGroup(ListNode* head, int k) {
      
        // if(head==NULL)return NULL;
        // ListNode *curr=head,*prev=NULL,*next=NULL;
        //   int count=0;
        // while(curr!=NULL){
        //       count++;
        //     curr=curr->next;
          
        // }
        // if(count<k)return head;
        // count=0;
        // curr=head;
        // while(curr!=NULL && count <k){
        //     next=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=next;
        //     count++;
        // }
        // if(next!=NULL)
        //     head->next=reverseKGroup(next,k);
        // return prev;
        if(head==NULL)return NULL;
        ListNode *cur=head, *nxt=NULL, *prev=NULL;
        int count=0;
        while(cur!=NULL){
            count++;
            cur=cur->next;
        }
        if(count<k)return head;
        count=0;
        cur=head;
        while(cur!=NULL && count<k){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            count++;
        }
        if(nxt!=NULL){  //jaise 12 reverse kar liye ab 34 reverse karo agr k=2 h
             head->next=reverseKGroup(nxt,k);
        }
        return prev; 
    }
};
