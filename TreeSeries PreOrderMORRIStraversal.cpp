 // MORRIS TRAVERSAL
   vector < int > preorderTraversal(TreeNode * root) {
  vector < int > preorder;

  TreeNode * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
        //testcase1 if(root->left==null to current print kardo)
      preorder.push_back(cur -> val);
      cur = cur -> right;//aur left null to rightmai chlo
    } else {
      TreeNode * prev = cur -> left;  //abhi hum current pai to left mai jana to uske liye thread
    //   from rightmost guy of leftsubstre has to be connected to curr to uske liye rightmost nikalo
      while (prev -> right != NULL && prev -> right != cur) {
          //agr prev->right==cur yani thread exist kar rta hai
        prev = prev -> right;

      }

      if (prev -> right == NULL) {
          //yani prev->right ==NULL to current right---->cur tak thread bn gya
         //  uske bad cur se cur->left mai ja sako
        prev -> right = cur;  ///ye jod diya cur se 
         preorder.push_back(cur -> val); //thread bnate hi print kar diya(kuki root left right hove preorder mai)
        cur = cur -> left; //aur phir left subtree mai chle gye
      } else { //yani already thread exist kar ra
        prev -> right = NULL; //to prev->right=null yani thread delete kar do
       
        cur = cur -> right;//aur right mai chle jao
      }
    }
  }
  return preorder;
}
