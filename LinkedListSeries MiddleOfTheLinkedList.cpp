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
    ListNode* middleNode(ListNode* head) {
        // ListNode *curr=head;
        // int c=0;
        // int middle;
        // while(curr!=NULL)
        // {
        //     c++;
        //     curr=curr->next;
        // }
        // curr=head;
        // if(c%2==0)
        //     middle=(c/2)+1;
        // else
        //     middle=(c+1)/2;
        // for(int i=1;i<middle;i++)
        // {
        //     curr=curr->next;
        // }
        // return curr;
        int cnt=0;
        int middle;
        ListNode* cur=head;
        while(cur!=NULL){
            cnt++;
            cur=cur->next;
        }
        if(cnt%2==0)middle=(cnt/2)+1;
        else middle=(cnt+1)/2;
        cur=head;
        for(int i=1;i<middle;i++){
            cur=cur->next;
        }
        return cur;
        
    }
};
