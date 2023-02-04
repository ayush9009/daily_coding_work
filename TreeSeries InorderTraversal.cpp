class Solution {
public:
     vector<int>result;
     void helper(TreeNode* root){
         if(root!=NULL){
             helper(root->left);
             result.push_back(root->val);
             helper(root->right);
         }
     }
     vector<int> inorderTraversal(TreeNode* root) {
         helper(root);
         return result;
     }

};
