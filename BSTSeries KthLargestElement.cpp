  Node* helper(Node* root,int &k){
        if(root==NULL)return NULL;
        
        Node* tmp=helper(root->right,k);
        if(tmp!=NULL)return tmp;
        k--;
        if(k==0)return root;
        return helper(root->left,k);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        Node* ans=helper(root,k);
        if(ans!=NULL)return ans->data;
        return -1
    }
