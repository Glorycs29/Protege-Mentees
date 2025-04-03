//LC Q->
//WITHOUT CONVERTING INOT ADJACENCY LIST (1ST APPROACH that clicked)
class Solution {
public:
    void dfs (int node, vector<int>& visited, vector<vector<int>>& grid){
        visited[node]=1;
        for(int i=0;i<visited.size();i++){
            if(i!=node && grid[node][i]==1  && visited[i]!=1){
               // visited[i]=1;
               dfs(i, visited, grid);
            }

        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
      vector<int>visited(isConnected.size(),0);
      int t=0;
      for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, visited,isConnected);
            t++;
        }
      }
return t;
    }
};



//Striver approach (JUST changed the adj matrix to adj list)
class Solution {
  private: 
    // dfs traversal function 
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V]; 
        
        // to change adjacency matrix to list 
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                // self nodes are not considered
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        int vis[V] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
        
    }
};
