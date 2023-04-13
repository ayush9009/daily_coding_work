class Solution {
public:
    bool isValid(string s) {
    //     int n=s.length();
    //     if(n==1)
    //         return false;
    //     stack<char>m;
    //    for(int i=0;i<n;i++)
    //    {
        //    if(s[i]=='('||s[i]=='['||s[i]=='{')
        //        m.push(s[i]);
        //    else if(!m.empty()&&(s[i]==')'||s[i]==']'||s[i]=='}'))
        //    {
        //        if(m.top()=='('&&s[i]==')')
        //            m.pop();
        //        else if(m.top()=='['&&s[i]==']')
        //            m.pop();
        //        else if(m.top()=='{'&&s[i]=='}')
        //            m.pop();
        //        else
        //            return false;
        //    }
        //    else 
        //        return false;
    //    }
    //     if(m.empty())
    //         return true;
    //     else 
    //         return false;
    int n=s.size();
    if(n==1)return false;
    stack<char>st;
     for(int i=0;i<n;i++){
           if(s[i]=='('||s[i]=='['||s[i]=='{')
               st.push(s[i]);
           else if(!st.empty()&&(s[i]==')'||s[i]==']'||s[i]=='}'))
           {
               if(st.top()=='('&&s[i]==')')
                   st.pop();
               else if(st.top()=='['&&s[i]==']')
                   st.pop();
               else if(st.top()=='{'&&s[i]=='}')
                   st.pop();
               else
                   return false;
           }
           else 
               return false;
         
     }
     if(st.empty())
     return true;
     else 
     {
          cout<<"cingo"<<endl;
         return false;
     }
    }
    
};
