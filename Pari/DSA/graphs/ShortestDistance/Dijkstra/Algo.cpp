class Solution {
        //using SET
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
         // Build adjacency list first
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // since undirected
        }
        set<pair<int, int>> st;
        vector<int> distance(V,INT_MAX);
        st.insert( {0, src});
        distance[src]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            int dist=it.first;
            int node=it.second;
            st.erase(it);
            for(auto i: adj[node]){
              //  if(dist==INT_MAX){
                 int  adjnode= i.first;
                  int weight=  i.second;
                  if(dist+weight<distance[adjnode]){
                      if(distance[adjnode]!=INT_MAX){
                          st.erase({distance[adjnode], adjnode});
                      }
                      
                      st.insert({dist+weight, adjnode});
                      distance[adjnode]=dist+weight;
                  }
                }
            }
            return distance;
        
        
    }
};
