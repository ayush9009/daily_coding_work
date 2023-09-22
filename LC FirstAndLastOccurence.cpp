class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>res=mp[x];
        vector<int>ans;
       if(mp[x].size()==0){
           ans.push_back(-1);
           ans.push_back(-1);
           return ans;
       }
       
        ans.push_back(res[0]);
        ans.push_back(res[res.size()-1]);
        return ans;
    }
};
