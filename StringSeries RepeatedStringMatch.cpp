class Solution {
public:
// VVIP QUESTION
// a=xyz
// b=zxyzxyzxyz
// maximum times reaptition=b.size()/a.size()=10/3=3 but (we have to 3+2) kuki shuru mai aur last mai bhi to add ho sake,cnt=1 kuki ek bar to add hogya 
    int repeatedStringMatch(string a, string b) {
        int repeat=b.size()/a.size();
        int cnt=1;
        string str=a;
        // repeat+2,+2 isliye kare kuki shuru mai aur last mai bhi to add ho sake
        for(int i=0;i<repeat+2;i++){
            if(a.find(b)!=string::npos)return cnt;
            else{
                a+=str;
                cnt++;
            }
        }
        return -1;
    }
};


// check if one string contains another string
// if(str1.find(str2)!=string::npos)return 1;
// else return 0;
