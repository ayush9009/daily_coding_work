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
// class Solution {
// public:
//     int ans=INT_MAX,i=1;
//     int kthSmallest(TreeNode* root, int k) {
//       in(root,k);
//       return ans;
//     }
//     void in(TreeNode*root,int k){
//         if(!root)return ;
//         in(root->left->val,k);
//         if(k==i)
//             ans=root->val;
//         in(root->right,val);
//     }
//     return ans;
// }
// };
class Solution {
public:
    // vector<int>ans;
    //  void in(TreeNode *root)
    // {
    //   if(root==NULL)return ;
    //      if(root->left)in(root->left);
    //       ans.push_back(root->val);
    //     if(root->right)in(root->right);
    // }
    vector<int>result;
    void helper(TreeNode *root){
        if(root!=NULL){
            
            helper(root->left);
            result.push_back(root->val);
            helper(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        //  in(root);
        // return ans[k-1];
        helper(root);
        return result[k-1];
    }
   
};
