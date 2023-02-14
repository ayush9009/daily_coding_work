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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // vector<vector<int>>ans;
        // if(root==NULL)
        //     return ans;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(q.empty()==false)
        // {
        //     vector<int>result;
        //     int count=q.size();
        //     for(int i=0;i<count;i++){
        //     TreeNode *curr=q.front();
        //     q.pop();
        //     if(curr->left!=NULL)
        //     q.push(curr->left);
        //     if(curr->right!=NULL)
        //         q.push(curr->right);
        //     result.push_back(curr->val);
        //     }
        //     ans.push_back(result);
        // }
        // return ans;
        
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            int n=q.size();
            vector<int>result;
            for(int i=0;i<n;i++){
                TreeNode * cur=q.front();
                q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);

                result.push_back(cur->val);
                
            }
            ans.push_back(result);
        }
        return ans;
        // vector<vector<int>>ans;
        // if(root==NULL)return ans;
        // queue<TreeNode*>q;
        // while(q.empty()==false){
        //     vector<int>result;
        //     int count=q.size();
        //     for(int i=0;i<count;i++){
        //         TreeNode *curr=q.front();
        //         q.pop();
        //         if(curr->left!=NULL)
        //             q.push(curr->left);
        //         if(curr->right!=NULL)
        //             q.push(curr->right);
        //         result.push_back(curr->val);
        //     }
        //     ans.push_back(result);
        // }
        // return ans;
    }
};
