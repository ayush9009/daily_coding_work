class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//         int index=0;
//         for(int i=0;i<nums.size()&&i+1<nums.size();i++){
//                 if(nums[i]!=-1){
//                 if(nums[i]==nums[i+1]){
//                     nums[i+1]=-1;
//                     nums[index]=nums[i];
//                     index++;
//                 }
//                 }
//             else{
//                     if(nums[i]!=-1){
//                     nums[index]=nums[i];
//                     index++;
//                     }
//                 }
            
//         }
//         return index;
   //optimised apporach:
   int i=0;
   for(int j=1;j<nums.size();j++){
       if(nums[j]!=nums[i]){
           nums[i+1]=nums[j];
           i++;
       }
   }
   return i+1;
    }
};
