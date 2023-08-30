class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool helper(Node* root){
     if(root==NULL)return 1;
     if(root->left==NULL && root->right==NULL)return 1;
     int sum=0;
     if(root->left!=NULL)sum+=root->left->data;
     if(root->right!=NULL)sum+=root->right->data;
     
     return (root->data==sum && helper(root->left) && helper(root->right));
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
      int x=helper(root);
      return x;
    }
};
