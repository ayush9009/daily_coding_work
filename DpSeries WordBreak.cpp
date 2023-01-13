#include <bits/stdc++.h> 
unordered_set<string>st;
int dictContains(string word){
    return st.find(word)!=st.end();
}
int wb(string &str){
    if(str.size()==0)return true;
    int dp[str.size()+1];
    memset(dp,0,sizeof(dp));
    dp[0]=true;
    for(int len=1;len<=str.length();len++){
        for(int i=0;i<len;i++){
            if(dp[i] && dictContains(str.substr(i,len-i))){
                dp[len]=true;
                break;
            }
        }
    }
    return dp[str.size()];
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    for(auto it:arr){
        st.insert(it);
    }
    return wb(target);
}
