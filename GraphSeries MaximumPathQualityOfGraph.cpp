class Solution {
public:
//simple backtracking apporach nothing more,like u find the permuationso f stirng using backtracking
// in similar manner we do,one extra thing, if(node==0)res=max(res,score) because from every node,we have to come to 0
    void dfs(vector<int>& values, vector<int>&vis,int &res,int node,int score,int time,int &maxTime, vector<vector<pair<int,int>>>&graph){
        if(time>maxTime)return;
        if(vis[node]==0)score+=values[node];
 
        vis[node]++;  //ye node visit ho chuki
        
        

        if(node ==0)res=max(res,score);  //jab bhi 0th node pai aye kuki backtracking chl ri,tabhimxfind krlo

       
        for(auto it:graph[node]){
            int x=it.first;  //node
            int y=time + it.second;  //new time
            dfs(values,vis,res,x,score,y,maxTime,graph);
        }
        vis[node]--;  //backtracking,node pai gye phir vapas hogye
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>>graph(n);
        for(int  i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>visited(n,0);
        int res=values[0];
         dfs(values,visited,res,0,0,0,maxTime,graph); //0,0,0 node,score,time
         return res;
    }
};
