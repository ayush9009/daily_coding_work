 void func(int index,vector<vector<int>>&ans,vector<int>&nums){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            func(index+1,ans,nums);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        // return perm(nums);
        vector<vector<int>>ans;
        func(0,ans,nums);
        return ans;
    }
