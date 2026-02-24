//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution{
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& inpath){
        visited[node]=1;
        inpath[node]=1;

        for(int i=0; i < adj[node].size();  i++){
            int next=adj[node][i];

            if(visited[next] == 0){
                if(dfs(next,adj, visited, inpath))
                    return true;
            }
            else if(inpath[next]==1){
                return true;
            }
        }

        inpath[node]=0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges){
        vector<vector<int>> adj(V);

        for(int i = 0; i < edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> visited(V, 0);
        vector<int> inpath(V, 0);

        for(int i = 0; i<V; i++) {
            if(visited[i] == 0){
                if(dfs(i, adj, visited, inpath))
                    return true;
            }
        }

        return false;
    }
};
