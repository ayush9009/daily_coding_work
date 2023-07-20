class Solution {
public:
    //longest common yani vo sab strings mai common hoga to koi bhi do strings dek lo agr match kar rai to theek nahi to break
    string longestCommonPrefix(vector<string>& strs) {
          
        //   if(strs.size()==0)return "";
        //   sort(strs.begin(),strs.end());
        //   string t=strs[0];
        //   string s=strs[strs.size()-1];
        //    string ans="";
        //   for(int i=0;i<t.size();i++){
        //       if(t[i]==s[i])
        //           ans+=t[i];
        //       else 
        //           break;
        //   }
        // return ans;

// longest prefix sab mai common hoga,agr huha to ,longest hoga,prefix h to shurh mai hoga accoring to question need,
        sort(strs.begin(),strs.end());
        if(strs.size()==0)return "";
        string t=strs[0];
        string str;
        string s=strs[strs.size()-1];
        for(int i=0;i<t.size();i++){
            if(t[i]==s[i]){
                str+=t[i];
            }else{
                break;
            }
        }
        return str;
    }
};
