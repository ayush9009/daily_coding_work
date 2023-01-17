// bfs for disconnected graph
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    // bfs for disconnected graph
   vector<int> bfsOfGraph(int v, vector<int> adj[])
   {
    vector<int> result;
    vector<int> visited(v, false);
    for (int i = 0; i < v; ++i) {
       
        if (!visited[i]) {
            queue<int> q;
            visited[i] = true;
            q.push(i);
         
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                result.push_back(cur);
                for (auto it : adj[cur]) {
                    if (!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return result;
   }

};
