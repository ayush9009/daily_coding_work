class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int curr=1,result=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     curr*=nums[i];
        //     result=max(curr,result);
        //     if(curr==0)
        //         curr=1;
        // }
        // curr=1;
        // for(int i=nums.size()-1;i>=0;i--){
        //     curr*=nums[i];
        //     result=max(curr,result);
        //     if(curr==0)
        //         curr=1;
        // }
        // return result;
        int mx=1;
        int n=nums.size();
        vector<int>dp(n+1,1);
        // for(int i=0;i<nums.size();i++){
        //     mx*=nums[i];
        //     dp[i]=max(mx,dp[i]);
        //     if(mx==0)
        //     mx=1;
        // }
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i],dp[i]*dp[i-1]);
        }
        return dp[n];
        // return dp[n];
        //SORRY BRO I WANT THE DP SOLUTION THIS IS NOT THE SOLUTION THAT I WANT FROM YOUR SIDE..
    }
};
          
