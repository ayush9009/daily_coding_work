class Solution {
public:
    vector<int>result;
    void helper(TreeNode* root){
        if(root!=NULL){
            result.push_back(root->val);
            helper(root->left);
            helper(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return result;
    }
};
