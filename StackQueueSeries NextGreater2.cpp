class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      stack<int>st;
      vector<int>result;
      for(int i=nums.size()-1;i>=0;i--){
          st.push(nums[i]);       //is trah isliye kuki jaise 54321 hai to hum chate hai st.top=5 ho to 
          //to yah pahle 12345 push hora taht measn st.top=5
      }
      for(int i=nums.size()-1;i>=0;i--){
          while(st.empty()==false && st.top() <= nums[i]){
              st.pop();
          }
          if(st.size()==0)result.push_back(-1);//mtlb iska koi next greater ni hai
          else result.push_back(st.top());  //milgya next greater 
          st.push(nums[i]);  //st mai element maintain rakna kai liye taki agli bar phir check kar sake
      }
      reverse(result.begin(),result.end());
      return result;
    }
};
