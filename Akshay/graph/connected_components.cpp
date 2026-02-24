class Solution {
  public:
    
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int s, vector<int>& res) {
        visited[s] = true;
        res.push_back(s);
        for (int i = 0; i < adj[s].size(); i++){
            if (!visited[adj[s][i]]) {
                dfs(adj, visited, adj[s][i], res);
            }
        }
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(V, false);
        vector<vector<int>> res;

        for (int i = 0; i < V; i++){
            if (!visited[i]) {
                vector<int> component;
                dfs(adj, visited, i, component);
                res.push_back(component);
            }
        }

        return res;
    }
};
