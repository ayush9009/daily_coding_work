class Solution
{
    public:
    vector<int>result;
    void helper(int n){
        int temp=n;
        while(temp!=0){
            result.push_back(temp%2);
            temp/=2;
        }
        reverse(result.begin(),result.end());
    }
    int maxConsecutiveOnes(int n)
    {
        // code here
        helper(n);
        int maxi=0,cnt=0;
        for(int i=0;i<result.size();i++){
            if(result[i]==1)cnt++;
            
            else cnt=0;
            
            
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
