bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        queue<TreeNode*>q;
        q.push(root);
        
        vector<int>result;
        while(q.empty()==false){
            TreeNode* cur=q.front();
            q.pop();
            if(cur!=NULL)result.push_back(cur->val);
            if(cur->left!=NULL)q.push(cur->left);
            if(cur->right!=NULL)q.push(cur->right);
        }
        int flag=0;
        for(int i=0;i<result.size();i++){
            for(int j=i+1;j<result.size();j++){
                if(result[i]+result[j]==k){
                    flag=1;
                    break;
                }
            }
        }
        return flag;
    }
