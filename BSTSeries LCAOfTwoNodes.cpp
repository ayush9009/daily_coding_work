   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL)return NULL;
            if(root->val== p->val || root->val==q->val)return root;
            TreeNode *lca1=lowestCommonAncestor(root->left,p,q);
            TreeNode *lca2=lowestCommonAncestor(root->right,p,q);
            if(lca1!=NULL && lca2!=NULL){
                // yani jo p left mai hai and q right mai or viceversa
                // mtlb ye bat to paki hai ek left mai ek right mai
                // to return root yani papa root hoga
                return root;
            }
            if(lca1!=NULL)return lca1; //mtlb doono p,q left mai to returnn lca1
            return lca2;
    }
