class Solution {
public:
    void helper(vector<int>&v,vector<vector<int>>&ans,vector<int>&candidates,int target,int idx){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
                if(i&&candidates[i]==candidates[i-1]&&i>idx)continue;
                if(candidates[i]<=target){
                    v.push_back(candidates[i]);
                    helper(v,ans,candidates,target-candidates[i],i+1);
                    v.pop_back();
                }else{
                    break;
                }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        helper(v,ans,candidates,target,0);
        return ans;
    }
};
