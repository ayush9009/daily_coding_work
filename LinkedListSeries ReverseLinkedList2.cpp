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
    // void reverse(ListNode **r,ListNode *p){
    //     if(p!=NULL){
    //         p->next=(*r);
    //         (*r)=p;
    //     }
    // }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // ListNode *curr=head;
        // vector<int>result;
        // while(curr!=NULL){
        //     result.push_back(curr->val);
        //     curr=curr->next;
        // }
        // reverse(result.begin()+left-1,result.end()+right);
        // ListNode *r=NULL;
        // for(int i=result.size()-1;i>=0;i--){
        //     ListNode *p=new ListNode(result[i]);
        //     reverse(&r,p);
        // }
        // return r;
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
            dummy->next = head;
            for (int i = 0; i < left - 1; i++){
                pre = pre->next;
            }
            cur = pre->next;
            for (int i = 0; i < right - left; i++){
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            return dummy->next;
    }
};
