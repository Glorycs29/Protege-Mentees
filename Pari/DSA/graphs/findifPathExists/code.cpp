//Qlink -> https://leetcode.com/problems/find-if-path-exists-in-graph/?envType=problem-list-v2&envId=graph
class Solution {
public:
bool dfs(int node, int destination, vector<vector<int>>& adj, vector<int> &vis){
    //checking for destination
    vis[node]=1;
    for(auto i: adj[node] ){
        if(i==destination) return true;
        if(!vis[i])
           // return dfs(i, destination, adj, vis); //as this doesnt explore other paths at all and returns only the reuslt of the first adjacent node explored
           if (dfs(i, destination, adj, vis)==true) return true; 
    }
    return false; //if none of the true conditions meet it simply means that destination node not found
}  
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //edge case
         if(n==1) return true;
              //dfs
        vector<vector<int>> adj(n);
        //converted to adjacency list
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0] ].push_back(edges[i][1]);
            adj[edges[i][1] ].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
       return  dfs(source, destination, adj, vis);
    }
};
