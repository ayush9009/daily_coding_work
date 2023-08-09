class Solution{
    public:
    
    //VVIP QUESTION 
    
    //something comes before something,or somehting comes after something,
    // WHEN THIS IS THE CASE THEN THERE IS ONLY TOPO SORT WHICH CAN HELP US TO FIND ANSWER
    
    
    // when the order is not posssible?
    // see if ,
    // case1:
    // s[i]=abc
    // s[i+1]=abcd ,then there is no problem 
    
    // but if s1[i]=abcd
    //       s2[i+1]=abc then you know that abcd can never comes abc kuki abc tak hoga bas comparison
    //       len=min(s1.size(),s2.size())=3,uske bad comparson ni huha lakin still abcd comes before abc
    //       aap normally english dicti bhi deken to jo string choti vo pahle ayegi lakin ya ulta hora to 
    //       order is not possible so we return -1
           
    // case2: if cylce is there
    // s1=abcd
    // s2=bcde
    // s3=aced
    // a<b<a ? how this is possible ,yaha to cycle bn ri to not possible,iska to topo sort bhi ni niklega
    // so order is not possible so we return -1
    vector<int> topologicalSort(vector<int>adj[],int v){
        vector<int>topo;
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            topo.push_back(cur);
            for(auto it:adj[cur]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return topo;
    }
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int>adj[k];
        for(int i=0;i<n-1;i++){
            string s1=dict[i];   //baa
            string s2=dict[i+1];   //abcd ,here we make comparison why baa occrus first then abcd,
            // because b<a consider here in alien dictionary
            int len=min(s1.size(),s2.size());  
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){   // baa abcd b!=a means b<a so we make directed edge from b->a
                // in this manner we make directed edges and in the end we get directed graph
                // and after getting graph we simply find topo sort of it,that is our result
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');//integer ki form mai directed edge bna rai hum
                    break;//baki bachi string kai liye  comparison karne ki jaroat ni 
                }
            }
        }
        vector<int>result=topologicalSort(adj,k);
        string ans="";
        for(int i=0;i<result.size();i++){
            ans+=result[i]+'a';
        }
        return ans;
    }
};
