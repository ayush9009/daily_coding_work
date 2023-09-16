class Solution {
public:
    int characterReplacement(string s, int k) {
        int count=0;
        int max_length=0;
        int max_cnt=0;
        int left=0;
        vector<int>cnt(26,0);
        for(int right=0;right<s.size();right++){
            cnt[s[right]-'A']+=1;
            max_cnt=max(max_cnt,cnt[s[right]-'A']);

            if((right-left+1) - max_cnt > k){ 
                
                //right-left+1 deontes window size
            // see AABAB k=1 window size=5 max_cnt=3 5-3=2 2>1 
            // so now our string is ABAB not AABAB
                cnt[s[left]-'A']-=1;
                left+=1;
            }

            max_length=max(max_length,right-left+1);
        }
        return max_length;
    }
};
