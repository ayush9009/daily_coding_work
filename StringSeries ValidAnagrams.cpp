class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n>m || n<m)return false;
        unordered_map<char,int>mp1,mp2;
        for(auto it:s){
            mp1[it]++;
        }
        for(auto it:t){
            mp2[it]++;
        }
        for(auto it:t){
            int x=mp2[it];
            if(mp1.find(it)==mp1.end())return false;
            if(mp1[it]>mp2[it] || mp1[it]<mp2[it])return false;
        }
        return true;
    }
};
