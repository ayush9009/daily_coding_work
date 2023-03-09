class Info{
    public:
    int maxNode;
    int minNode;
    int maxSize;
    Info(int minNode,int maxNode,int maxSize){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Info solve(Node *root){
        if(root==NULL){
            //an empty tree is a bst of 0
            return Info(INT_MAX,INT_MIN,0);
        }
        
        auto left=solve(root->left);
        auto right=solve(root->right);
        
        if(root->data > left.maxNode && root->data < right.minNode){
            //it means valid bst
            return Info(min(root->data,left.minNode),max(root->data,right.maxNode),1+left.maxSize+right.maxSize);
        }
        
            //means not a valid bst so we return -inf,inf so that parent cnanot be bst
            //left right maxSize le liya taki agr chota mota bhi bst hai to uska size hume pta ho
            return Info(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));  
        
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	return solve(root).maxSize;
    }
};
