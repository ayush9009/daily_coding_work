void findPreSuc(Node* root, Node*& pre, Node*& suc, int k)
{

// Your code goes here
   Node *cur=root;
   while(root!=NULL){
       if(k >= root->key)root=root->right;
       else{
           suc=root;
           root=root->left;
           
       }
   }
  while(cur!=NULL){
      if(cur->key < key){
          pre=cur;
          cur=cur->right;
      }else{
          cur=cur->left;
      }
  }

}
