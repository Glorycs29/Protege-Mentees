//link= https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

//T.C. =O(E*V)
//SC= O(V)


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        //directed graph given
        
        vector<int > distance(V, 1e8);
        distance[src]=0;
        for(int i=0;i<V-1;i++){ //v-1 times
            for(auto j: edges){
                int u=j[0];
                int v=j[1];
                int w=j[2];
                if(distance[u]!=1e8 && distance[u]+w<distance[v]){
                    distance[v]=distance[u]+w;
                }
            }
            
        }
        for(auto i: edges){
            if(distance[i[0]]!=1e8 && distance[i[0]]+i[2]< distance[i[1]]) return {-1};
        }
        return distance;
    }
};
