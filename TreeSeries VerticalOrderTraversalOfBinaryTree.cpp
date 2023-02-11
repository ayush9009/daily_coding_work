// vertical order traversal of binary tree
//map<int,map<int,multiset>>>mp;
// queue<pair<TreeNode*,pair<int,int>>>q;

class Solution {
public:
    // void preorder(TreeNode* root, map<int, vector<pair<int,int> > > &mp, int row, int col){
    //    if(!root){
    //        return;
    //    } 
    //     mp[col].push_back({row, root->val});
    //     preorder(root->left,mp,row+1, col-1);
    //     preorder(root->right,mp,row+1, col+1);
    // }
    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     map<int, vector<pair<int,int> > > mp;
    //     preorder(root,mp,0,0);
    //     vector<vector<int>> ans;
    //     for(auto x:mp){
    //         sort(x.second.begin(), x.second.end());
    //         vector<int> temp;
    //         for(auto a:x.second){
    //             temp.push_back(a.second);
    //         }
    //         ans.push_back(temp);
    //     }
    //     return ans;
    // }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //multiset isliye use huha kuki multiple values contains same values 

        map<int,map<int,multiset<int>>>mp;  //first vertical then level then node->val,here we do level order traversal.
        //for every vertical tehre is some level
        //example 2 deko at vertical 0 and level 2 there are multiple nodes for that we can use set,but i multiset
        //becuase we need in soted order aur agr same values ho jaise 5 5 to vo bhi include karo yani 5 5 bhi
        queue<pair<TreeNode*,pair<int,int>>>q; //node,vertical,level
        q.push({root,{0,0}});
        while(q.empty()==false){
            auto que=q.front();  //{root,{0,0}}  first zero ko kahenge second.first,dursi 0 kko second.seoncd
            q.pop();
            TreeNode* cur=que.first;
            int x=que.second.first;
            int y=que.second.second;
            mp[x][y].insert(cur->val);  //[vertical,level]=node,ya phir kahe [column,row]=node->val
            if(cur->left!=NULL){
                q.push({cur->left,{x-1,y+1}});
            }
            if(cur->right!=NULL){
                q.push({cur->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>temp;
            for(auto q:it.second){
                temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
