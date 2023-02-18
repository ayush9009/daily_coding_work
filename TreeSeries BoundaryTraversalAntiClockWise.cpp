bool isLeaf(TreeNode *root){
    return (root->left ==NULL && root->right==NULL);
}
void addLeftBoundary(TreeNode<int>* root,vector<int>&res){
    TreeNode *cur=root->left;
    while(cur){
        if(!isLeaf(cur))res.push_back(cur->data);
        if(root->left)addLeftBoundary(root->left, res);
        else addLeftBoundary(root->right, res);
    }
}
void addRightBoundary(TreeNode * root,vector<int>&res){
    TreeNode *cur=root->right;
    vector<int>temp;
    while(cur){
        if(!isLeaf(cur))temp.push_back(cur->data);
        if(root->left)addLeftBoundary(root->right, res);
        else addLeftBoundary(root->left, res);
        
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
void addLeavesBoundary(TreeNode *root,vector<int>&res){
  if (isLeaf(root)) {
    res.push_back(root->data);
    return;
  }
  if(root->left)addLeavesBoundary(root->left, res);
  if(root->right)addLeavesBoundary(root->right, res);
}
vector<int> traverseBoundary(TreeNode * root){
    // Write your code here.
    vector<int>res;
    if(!root)return res;
    if(!isLeaf(root))return res.push_back(root->data);

    addLeftBoundary(root,res);
    addLeavesBoundary(root,res);
    addRightBoundary(root,res);
}
