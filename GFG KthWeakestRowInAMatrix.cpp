class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>q;
        int n=mat.size();                //priority queue
        int sum;
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    break;
                if(mat[i][j]==1)
                    sum+=1;
            }
            q.push(make_pair(sum,i));
        }
        vector<int>ans;
        n=n-k;
        for(int i=1;i<=n;i++)              
        {
            q.pop();
        }
        for(int i=1;i<=k;i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
