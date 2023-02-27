/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void insert(TreeNode **r,TreeNode *p){
    //     if(*r==NULL){
    //         *r=p;
    //     } 
    //     else{
    //         if(p->val < (*r)->val)
    //         insert(&(*r)->left,p);
    //         else
    //         insert(&(*r)->right,p);
    //     }
    // }
    void insert(TreeNode **cur,TreeNode *p){
        if(*cur==NULL){
            *cur=p;
        }
        else{
            if(p->val < (*cur)->val)
            insert(&(*cur)->left,p);
            else
            insert(&(*cur)->right,p);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // TreeNode *r=NULL,p;
        // for(int i=0;i<preorder.size();i++){
        //     TreeNode *p=new TreeNode(preorder[i]);
        //     insert(&r,p);
        // }
        // return r;
        TreeNode *cur=NULL,p;
        for(int i=0;i<preorder.size();i++){
            TreeNode *p=new TreeNode(preorder[i]);
            insert(&cur,p);
        }
        return cur;
    }
};
