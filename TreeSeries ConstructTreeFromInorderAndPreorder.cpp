/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    // int preIndex=0;
    // TreeNode*cTree(vector<int>&preorder,vector<int>&inorder,int is,int ie)
    // {
    //     if(is>ie)
    //     {
    //         return NULL;
    //     }
    //     TreeNode *root=new TreeNode(preorder[preIndex++]);
        
    //     int Index;
    //     for(int i=is;i<=ie;i++)
    //     {
    //         if(inorder[i]==root->val)
    //         {
    //             Index=i;
    //             break;
    //         }
    //     }
    //     root->left=cTree(preorder,inorder,is,Index-1);
    //     root->right=cTree(preorder,inorder,Index+1,ie);
    //     return root;
    // }
    int preIndex=0;
    TreeNode *cTree(vector<int>& preorder, vector<int>& inorder,int is,int ie){
        if(is>ie)return NULL;
        TreeNode *root=new TreeNode(preorder[preIndex++]);

        int index=0;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                index=i;
                break;
            }
        }
        // for eg:preooder=[3,9,20,15,7] inorder=[9,3,15,20,7] initially is=0,ie=preoder.size()-1
        // int index=0 aur root=new treenode(preoder[0]) yani 3 ki root bn gyu
        // ab inorder mai deko jo 3 kai leftmai vo 3 kai left child jo right mai vo right child
        // //ab ye indexing pata honi chaiye ki root kaha h in inorer
        // to uske liye for loop i.e if(inorder[i]==root->val)  to is sey milgya index
        // for 3 indx mila 1 to left mai index-1 vale aur right mai index+1 vale to vo hi to likha
        root->left=cTree(preorder,inorder,is,index-1);
        root->right=cTree(preorder,inorder,index+1,ie);   //ek trah se ye smjo ki is represent indx in left
        // and ie represent index in right
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int is=0,ie=preorder.size()-1;
        return cTree(preorder,inorder,is,ie);
    }
};
