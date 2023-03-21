void func(int index,vector<vector<int>>&ans,vector<int>&nums){
        if(index==nums.size()){
            ans.push_back(nums);
        }
        unordered_set<int>s;
        for(int i=index;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())continue;  //ab is sey repeatition ni ho panekey
            s.insert(nums[i]);
            swap(nums[i],nums[index]);
            func(index+1,ans,nums);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        // perm(nums,0);
        func(0,ans,nums);
        return ans;
    }
