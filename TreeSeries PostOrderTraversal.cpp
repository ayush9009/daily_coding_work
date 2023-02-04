class Solution {
public:
    vector<int>result;
     void helper(TreeNode* root){
         if(root!=NULL){
             helper(root->left);
             helper(root->right);
             result.push_back(root->val);
         }
     }
     vector<int> postorderTraversal(TreeNode* root) {
         helper(root);
         return result;
     }
};
