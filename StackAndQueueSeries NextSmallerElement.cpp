#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    // Write your code here.
     stack<int>st;
     vector<int>result;
     for(int i=nums.size()-1;i>=0;i--){
         while(st.empty()==false && st.top() >= nums[i]){
           st.pop();
         }
         if(st.size()==0)result.push_back(-1);
         else result.push_back(st.top());

         st.push(nums[i]);
     } 
     reverse(result.begin(),result.end());
      return result;
}
