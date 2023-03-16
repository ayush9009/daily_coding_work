class Solution
{
public:
    void traverse(vector<int>&result,vector<int>&res,vector<vector<int>>&ans,int index){
        ans.push_back(res);
        for(int i=index;i<result.size();i++){
            res.push_back(result[i]);
            traverse(result,res,ans,i+1);
            res.pop_back();
        }
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>res,rs;
        vector<vector<int>>ans;
        res.push_back(0);
        traverse(arr,res,ans,0);
        for(auto it:ans){
            int sum=0;
            for(int j=0;j<it.size();j++){
                sum+=it[j];
            }
            rs.push_back(sum);
        }
        // for(auto it:rs)cout<<it<<" ";
        return rs;
    }
};
