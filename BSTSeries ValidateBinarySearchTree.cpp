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
    // bool isValidBst(TreeNode *root,long minValue,long maxValue)
    // {
//         if(root==NULL)
//             return true;
//         if(root->val >= maxValue || root->val <= minValue)
//             return false;
// return (isValidBst(root->left,minValue,root->val)&&isValidBst(root->right,root->val,maxValue));
    // // }
    // appraoch:agr aap sirf root->val check karogey greater than root->left->val and root->val > root->right->val to ye appraoch fail hojagi
    // 15 5 10,2 6 8 12 is tree kai liye check karogey to ye approach glt ho jagi kuki aap left tree
    // sahi hai lakin right subtree mai right mai 12 hai so here 15<12 to ye bst kai khilaf hogya
    // to aapko kya dekna root->val >= minvalue(leftsubstrree)  && root->val<=maxValue(rightsubtree); 


     bool helper(TreeNode *root,long min_value,long max_value){
         if(root==NULL)return true;
         else if(root->val >=max_value || root->val <=min_value)
         return false;
         return helper(root->left,min_value,root->val) && helper(root->right,root->val,max_value);
     }
      bool isValidBST(TreeNode* root) {
       return helper(root,LONG_MIN,LONG_MAX);
    }
};
