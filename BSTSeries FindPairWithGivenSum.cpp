//optimised Solution 
//tc:O(nlogn)
//sc:O(1)
class Solution{
  public:
    vector<int>result;
    void helper(struct Node *root){
        if(root!=NULL){
            helper(root->left);
            result.push_back(root->data);
            helper(root->right);
        }
    }
    int isPairPresent(struct Node *root, int target)
    {
    helper(root);
    int flag=0;
    sort(result.begin(),result.end());
    int l=0,r=result.size()-1;
    while(l<r){
        if(result[l]+result[r]==target)
        {
            flag=1;
            break;
        }else if(result[l]+result[r]<target)l=l+1;
        else r=r-1;
    }
    return flag;
    }
};
