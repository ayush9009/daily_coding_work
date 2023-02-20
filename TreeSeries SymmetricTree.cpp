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
    bool helper(TreeNode *p,TreeNode *q){
        if(p==NULL && q==NULL)return true;
        if(p==NULL ||q==NULL)return p==q;   //ye isliye kar rai kuki p->val!-q->val agr aap ye check kar rai to 
        // agr socha p==NULL to hhum kya check kare null!=q->val to ye glt hoja error aja 
        //vo na ho isliye agr inme se koi bhi null ho to reutrn p==q;
        if(p->val!=q->val)return false;
        return helper(p->left,q->right) && helper(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        else return helper(root->left,root->right);
    }
   
};
