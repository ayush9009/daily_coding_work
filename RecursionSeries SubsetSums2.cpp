class Solution {
public:
   
    void findSubsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);//jo apne array bnaya us apne ds mai add kar diya
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            //to avoid duplicacy
            //hume pata i= range from index-(n-1)
            //to agr i!=index and nums[i]==nums[i-1] yani duplicate elemnt hai ye to kuch mat karo
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            //to bhai ab index traverse kar liye to ab next kai liye jao
            // i.e index+1 aur res bhi  to +1 ho jaga,yaha res.push_back to ek trahincrease hogya
            //res.pop_back();//pop out taki dubare use ho sake next iteration mai
            // time complexity: (2^n)*n
            ds.pop_back();
         }
      }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<vector<int>>ans;
        // vector<int>res;
         vector < vector < int >> ans;
         vector < int > ds;
         sort(nums.begin(), nums.end());
        // traverse(res,ans,nums,0);
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};
     

