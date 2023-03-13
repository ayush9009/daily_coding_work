int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    vector<int>result;
    TreeNode<int>*nod=root;
    queue<TreeNode<int>*>q;
    q.push(nod);
    while(q.empty()==false){
        TreeNode<int>*cur=q.front();
        q.pop();
        result.push_back(cur->val);
        if(cur->left)q.push(cur->left);
        if(cur->right)q.push(cur->right);
    }
    sort(result.begin(),result.end(),greater<int>());
    int flag=0;
    int mx=x;
    for(auto it:result){
        if(mx>it || mx==it){
            mx=it;
            flag=1;
            break;
        }
    }
    if(flag)return mx;
    return -1;
}
