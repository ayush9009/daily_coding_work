class Solution {
public:
    string getPermutation(int n, int k) {
      vector<int>nums;
      int fact=1;
      for(int i=1;i<n;i++){
          fact=fact*i;
          nums.push_back(i);
      }
      nums.push_back(n);
      string ans="";
      k=k-1;
      while(true){
          ans=ans+to_string(nums[k/fact]);   //16/6=2 i.e 3
          nums.erase(nums.begin()+k/fact);   //16%6 i.e 4 to ab k=4 hogtay
          if(nums.size()==0){
              break;
          }
          k=k%fact;
          fact=fact/nums.size();
      }
      return ans;
    }
};
