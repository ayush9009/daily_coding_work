class Solution{
    public:
    void connect(Node *root)
    {
       // Code Here
       Node* cur=root;
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int n=q.size();
           for(int i=0;i<n;i++){
                Node* cur=q.front();
                q.pop();
                if(i<n-1){
                    //suppose in queue 345  
                                    //   012 0<n-1,1<n-1,but 2 is not less than 2 therefeore 5->nextRgh=NULL
                    cur->nextRight=q.front();
                }else{
                    cur->nextRight=NULL;
                }
                
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
           }
       }
    }    
};
