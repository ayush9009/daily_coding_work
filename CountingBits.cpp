class Solution {
public:
    void dec_bin(int i,vector<int>&result)
    {
        int m=i;
        int temp;
        while(m!=0)
        {
            temp=m%2;
            result.push_back(temp);
            m=m/2;
        }
        reverse(result.begin(),result.end());
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        vector<int>result;
        for(int i=0;i<=n;i++)
        {
            dec_bin(i,result);
            int c=0;
            for(int i=0;i<result.size();i++)
            {
                if(result[i]==1)
                    c++;
            }
            result.clear();
            ans.push_back(c);
        }
        return ans;
    }
};
