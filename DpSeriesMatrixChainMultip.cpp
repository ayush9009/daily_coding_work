int maxIncreasingDumbbellsSum(vector<int> &nums, int n)
{
	// Write your code here
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=nums[i];\
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[i]<dp[j]+nums[i]){
                dp[i]=dp[j]+nums[i];
            }
        }
    }
    int mx=0;
    for(auto it:dp){
        mx=max(it,mx);
    }
    return mx;
}
