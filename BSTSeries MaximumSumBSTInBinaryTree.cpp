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
//bahatreen question
class Info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};
Info solve(TreeNode* root,int &maxSum){
    if(root==NULL){
       return {INT_MIN,INT_MAX,true,0};
     }

    Info left=solve(root->left,maxSum);
    Info right=solve(root->right,maxSum);

    Info cur;

    cur.sum=root->val+left.sum+right.sum;
    cur.maxi=max(root->val,right.maxi);
    cur.mini=min(root->val,left.mini);
    

    if(left.isBST && right.isBST && (root->val > left.maxi && root->val <right.mini)){
        cur.isBST=true;
    }else{
        cur.isBST=false;
    }

    if(cur.isBST){
        maxSum=max(maxSum,cur.sum);
    }
    return cur;
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum=0;
        Info temp=solve(root,maxSum);
        return maxSum;
    }
};
