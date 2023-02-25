class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int key) {
        // if(root==NULL)
        //     return NULL;
        // else if(root->val==val)
        //     return root;
        // else if(root->val>val)
        //     return searchBST(root->left,val);
        // else 
        //     return searchBST(root->right,val);
        if(root==NULL)return NULL;
        else if(root->val==key)return root;
        else if(root->val > key)return searchBST(root->left,key);
        else return searchBST(root->right,key);
    }
};
