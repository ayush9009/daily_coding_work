#include <bits/stdc++.h> 
vector<string>wordBreakHelper(string &s,int idx,unordered_set<string>&st,unordered_map<int,vector<string>>&dp,
int size){
    if(idx==size)return {" "};

    if(dp.find(idx)!=dp.end()){
        return dp[idx];  //this is the rule of dp if already exist then use it
    }

    vector<string>subPart,completePart;
    // subpart->stores the answer from recursion call 
    // complete part->add the word to subpart then add it to complete sentencei.e dp
    string word=""; //current string add hojagi
    
    for(int j=idx;j<size;j++){
        word.push_back(s[j]);
        // word+=s[j];

        if(st.count(word)==0)continue;

        subPart=wordBreakHelper(s,j+1,st,dp,size);

        for(int i=0;i<subPart.size();i++){
            //har ek indx pai alg combination
            //unme aap god ko add karte jare
            if(subPart[i].size()!=0){
                string temp=word;
                temp.append(" ");//add the space
                temp.append(subPart[i]);
                subPart[i]=temp;
            }else{
                subPart[i]=word;  //agr nahi to subpart mai add kardo word
            }
        }

        for(int i=0;i<subPart.size();i++){
            //isme sare kai sare cmoplete sentence add kardiye
            completePart.push_back(subPart[i]);
        }
        dp[idx]=completePart; //ispe sare vo possibele combination of strings
        // add hogyi 
        return dp[idx];  //return dp[idx]kuki isme sare combinations store puri strinkai
    }
}
vector<string> wordBreak(string &s, vector<string> &dict)
{
    // Write your code here
    unordered_map<int,vector<string>>dp;
    unordered_set<string>st;
    for(auto it:dict){
        st.insert(it);
    }
    return wordBreakHelper(s,0,st,dp,s.size());
}
