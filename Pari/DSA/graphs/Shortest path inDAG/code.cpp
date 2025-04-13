
class Solution {
  public:
void dfs(int node,  vector<vector<pair<int,int>>>& adj, stack<int>& st, vector<int> &vis){
    vis[node]=1;
    for(auto i: adj[node]){
     //   int nei=i[0];
     //   int wt=i[1];
     int nei=i.first;
     int wt=i.second;
        if(!vis[nei]){
            dfs(nei, adj, st, vis);
        }
    }
     st.push(node);
}
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
      vector<vector<pair<int,int>>> adj(V);
        //MAKING AN ADJ. LIST WITH EDGES AND WEIGHTS
       // vector<pair<int,int>> adj ;
        for(int i=0;i<E ;i++){
          //  adj[edges[i][0]].push_back(edges[i][1]); as it is a 
            //adj[edges[i][0]].push_back(edges[i][2]);
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        //Step-1 topological sort
        stack<int> st;
       // vector<int> 
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj, st, vis);
            }
        }
        vector<int> distance(V,INT_MAX);
        //for each element update the shortest distance
        //distance=
       // st.push(0);
        
         distance[0] = 0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            int dist=distance[node];
            if (distance[node] != INT_MAX){
                for(auto &i : adj[node]){
                int nei=i.first;
                int wt=i.second;
                if(dist+ wt< distance[nei]){
                    distance[nei]=dist+ wt;
                }
            }
            }
        }
         for(int i=0;i<V;i++){
             if(distance[i]==INT_MAX) distance[i]=-1;
         }
       return distance; 
    }
};
