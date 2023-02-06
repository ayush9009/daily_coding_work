void helper(Node* root,int level,vector<int>&res){
    if(root==NULL)return;
    if(res.size()==level)res.push_back(root->data);
    helper(root->right,level+1,res);
    helper(root->left,level+1,res);
    
}
vector<int> rightView(Node *root)
{
   vector<int>res;
   helper(root,0,res);
   return res;
}
