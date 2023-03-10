class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        string str="";
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            TreeNode *cur=q.front();
            q.pop();
            if(cur==NULL)str.append("#,");
            else str.append(to_string(cur->val)+',');
            if(cur!=NULL){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        cout<<str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        queue<TreeNode*>q;
        string str;
        stringstream s(data);  //accept the string of objects
        getline(s,str,',');  //it allows the user to read multiple lines and multiple words
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(q.empty()==false){
            TreeNode *cur=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                cur->left=NULL;
            }
            else{
                TreeNode* leftNode=new TreeNode(stoi(str));
                cur->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#"){
                cur->right=NULL;
            }else{
                TreeNode* rightNode=new TreeNode(stoi(str));
                cur->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
