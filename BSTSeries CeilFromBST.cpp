int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    vector<int>result;
    BinaryTreeNode<int>*root=node;
    queue<BinaryTreeNode<int>*>q
    q.push(root);
    while(q.empty()==false){
        BinaryTreeNode<int>*cur=q.front()
        q.pop();
        result.push_back(cur->data)
        if(cur->left)q.push(cur->left)
        if(cur->right)q.push(cur->right);
    }
    sort(result.begin(),result.end());
    int mx=x;
    int flag=0;
    for(auto it:result){
        if(it==mx || it>mx){
            flag=1;
            mx=it;
            break;
        }
    }
    if(flag)return mx;
    return -1;
}
