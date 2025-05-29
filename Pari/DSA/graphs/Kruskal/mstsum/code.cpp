//LINK= https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int num){
        parent.resize(num+1,0);
        size.resize(num+1);
        for(int i=0;i<=num;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findparent(int u){
        //base case
        if(parent[u]==u) return u;
        return parent[u]=findparent(parent[u]);
    }
    void unionBYsize(int u, int v){
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
      if(ulp_u==ulp_v) return; //means are of same component only
            if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            else {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
    }
};
class Solution {
  public:
   // Kruskal's Algorithm
    int kruskalsMST(int V, vector<vector<int>> &edges) {
    //     vector<pair<int, pair<int,int>> e;
    //     for(int i=0;i<V;i++){
    //         for(auto it: edges[i]){
    //             int wt=it[2];
    //             int u=it[0];
    //             int v=it[1];
    //             e.push_back({wt,{u, v}} );
    //         }
    //     }
    
    int Mstsum=0;
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int>& b){
        return a[2]<b[2];  // Sort by weight (3rd element)
    });
    //sorting done
    DisjointSet ds(V); //object of n=V(no of vertices)
    for(auto edge: edges){
        int wt=edge[2];
        int v1=edge[0];
        int v2=edge[1];
        if(ds.findparent(v1)!=ds.findparent(v2)){
            Mstsum+=wt;
            ds.unionBYsize(v1,v2);
        }
    }
    return Mstsum;
     }    
};
