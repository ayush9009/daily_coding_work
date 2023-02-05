 // MORRIS TRAVERSAL
  vector < int > inorderTraversal(TreeNode * root) {
  vector < int > inorder;

  TreeNode * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
        //testcase1 if(root->left==null to current print kardo)
      inorder.push_back(cur -> val);
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
        cur = cur -> left; //aur phir left subtree mai chle gye
      } else { //yani already thread exist kar ra
        prev -> right = NULL; //to prev->right=null yani thread delete kar do
        inorder.push_back(cur -> val);//aur current print kardo
        cur = cur -> right;//aur right mai chle jao
      }
    }
  }
  return inorder;
}
