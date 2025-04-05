//fill with two colors
//qlink ->https://www.geeksforgeeks.org/problems/bipartite-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class Solution {
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        // GIVEN an adjacency list of a graph adj -> SO CONSIDER IT AS AN ADJ LIST 
        //bfs
        queue<int> q;
        q.push(0);
        int n=adj.size();
        vector<int> col(n,-1);
        col[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                if(col[it]==-1){
                    col[it]=!col[node];
                    q.push(it);
                }
                else if(col[node]==col[it] ) return false;
            }
         
        }
        return true;
    }
};
