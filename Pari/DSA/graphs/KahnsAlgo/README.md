// TOPOLOGICAL SORT USING BFS AND INDEGREE VECTOR
//INdegree-> no of incoming edges of a node


//COMPLEXITIES 
-TC: O(V+E)
-SC:O(V)

##code
```cpp
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //USING KAHN'S ALGORITHM
        vector<int> indegree(V+1,0);
        for(auto edge: edges){
            indegree[edge[1]]++;
        }
        //CHANGING THE EDGES LIST TO ADJACENCY LIST
        vector<vector<int>> adj(V);
         for(auto &edge : edges){
           adj[edge[0]].push_back(edge[1]);
        }
        
        
        
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);

        }
        vector<int> topo_order;
        while(!q.empty()){
            int node=q.front();
            topo_order.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                if(indegree[it]==0) continue;
                if(--indegree[it]==0) {
                    q.push(it);
                }
            }
        }
        return topo_order;
        
    }
};
