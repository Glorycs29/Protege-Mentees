
# 1st APPROACH 
DFS for detecting cycle

## time complexity->O(V+E) 
## space complexity->O(2V) 
-as we are using  2 vis and pathvis array in the dfs
## CODE

```cpp
class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int>& pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;
        for (auto nei : adj[node]) {
            if (vis[nei] == 0 && pathvis[nei] == 0) {
                bool ans = dfs(nei, adj, vis, pathvis);
                if (ans == true) return true;
            } else if (vis[nei] && pathvis[nei]) return true;
        }
        pathvis[node] = 0;
        return false;
    }

public:
    bool isCyclic(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathvis) == true) return true;
            }
        }
        return false;
    }
};

