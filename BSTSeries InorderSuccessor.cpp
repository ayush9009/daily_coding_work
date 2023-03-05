void TreeNode *find(TreeNode*root,TreeNode*p){
    TreeNode*success=NULL;
    while(root!=NULL){
        if(p->val >= root->val)root=root->right;
        else{
            success=root;
            root=root->left;
        }
    }
    return success;
}
