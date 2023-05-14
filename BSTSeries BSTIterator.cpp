 stack<TreeNode*>st;
     void pushAll(TreeNode*root){
         TreeNode*cur=root;
         while(cur!=NULL){
             st.push(cur);
             cur=cur->left;
         }
     }
     BSTIterator(TreeNode* root) {
         pushAll(root);
     }
     int next() {
         TreeNode* tmp=st.top();
         st.pop();
         pushAll(tmp->right);  //agr null to koi dikkt ni else agr nodes to vo sarileftstackmai gyi
         return tmp->val;
     }
     bool hasNext(){
         return !st.empty(); //!st.empty() mtlb st agr emmpty nhi to return true else false  
         //agr stack empty to false return kar do else true
     }
