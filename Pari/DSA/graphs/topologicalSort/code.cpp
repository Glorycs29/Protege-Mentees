//Qlink-> https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
  public:
    void dfs(int node, vector<vector<int>> & adj, vector<int>& vis, stack <int>& st){
        vis[node]=1;
      //  st.push(node); here is the problem
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        stack<int> st;
        vector<int> vis(V,0);
        //convert the edges list to sdjacency list
    //    vector<int> adj[V];
    vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
            
      return ans;
    }
};
