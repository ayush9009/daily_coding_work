class Solution {
public:
//vvip question ,optimised apporach
    vector<vector<int>> threeSum(vector<int>& nums){
        int n=nums.size();
       sort(nums.begin(),nums.end());
       vector<vector<int>>ans;
       for(int i=0;i<nums.size();i++){
           //ye nums[i]==nums[i-1]isliye check hora taki repeative pairs na include ho ja result mai
           if(i>0 && nums[i]==nums[i-1])continue; //kukiyevalacase conider hogyaalrdy
           int j=i+1;
           int k=n-1;
           while(j<k){
              int sum=nums[i]+nums[j]+nums[k];
               if(sum>0){
                   k--;
               }
               else if(sum<0){
                   j++;
               }
               else{
                   vector<int>temp={nums[i],nums[j],nums[k]};
                   ans.push_back(temp);
                   j++;
                   k--;
                //    humne j++ kara k-- lakin nums[j]==nums[j-1]still equal hore
                //    to uske liye hum ek loop chla denge tab tak jab tak not equal element na mile,ye isliye kar rai ,to avoid repearive pairs
//   -2 -2 -2 -1 -1 -1 0 0 0 2 2 2 2
//   suppose i=0 ,j=6 k=12   -2+0+2 this is one pair,we do i++,j++,k--
//   if i++ -2  ,j++ 0 ,k-- 2 so we again get same pair,to aisa na ho isliye
//   i kai liye condition nums[i]==nums[i-1]continiue
//   aur j kai liye bhi if(j<k && nums[j]==nums[j-1])j++ to avoid repetive pairs,aise hi k kai liye bhi kara while(j<k && nums[k]==nums[k+1])k--;

                   while(j<k && nums[j]==nums[j-1])j++;
                   while(j<k && nums[k]==nums[k+1])k--;
               }
           }
       }
       return ans;
    }
};
